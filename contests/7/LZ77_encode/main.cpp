
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Code {
public:
    Code(int _offset, int _length, char _next) {
        offset = _offset;
        length = _length;
        next = _next;
    }

    int offset;
    int length;
    char next;
};

void getPrefix(int *prefix, string &str) {
    int tmp;
    for (int i = 1; i <= str.length() - 1; ++i) {
        tmp = prefix[i - 1];
        while (tmp > 0 && str[i] != str[tmp])
            tmp = prefix[tmp - 1];
        if (str[i] == str[tmp])
            prefix[i] = ++tmp;
        else
            prefix[i] = 0;
    }
}

int getSubstringIndex(string &substring, string &source) {
    // Найдем массив граней
    int *prefix = new int[substring.length()]{};
    getPrefix(prefix, substring);

    int i = 0;
    bool flag = false;
    for (int k = 0; i < source.length(); ++i) {
        while (k > 0 && source[i] != substring[k])
            k = prefix[k - 1];

        if (source[i] == substring[k]) {
            k++;
            if (k == substring.length()) {
                flag = true;
                break;
            }
        }
    }
    delete[] prefix;
    return flag ? i - substring.length() + 1 : -1;
}

#define DICT_LEN 3072

void updateDict(string &dict, char ch) {
    if (dict.length() == DICT_LEN)
        dict = dict.substr(1);
    dict += ch;
}

void updateDict(string &dict, string &str) {
    if (dict.length() + str.length() > DICT_LEN)
        dict = dict.substr(dict.length() + str.length() - DICT_LEN);
    dict += str;
}

void encode(vector<Code *> &codes, const string &input) {
    if (input.length() == 0)
        return;

    string dict, code;
    int codeIndex = 0;
    for (int i = 0; i < input.length(); ++i) {
        code += input[i];
        int index = getSubstringIndex(code, dict);
        if (index != -1) {
            codeIndex = index;
        } else {
            if (code.length() == 1) {
                codes.push_back(new Code(0, 0, input[i]));
            } else {
                int offset = dict.length() - codeIndex;
                if (offset == code.length() - 1) {
                    int k = 0, codeLen = code.length() - 1;
                    while (input[i] == dict[codeIndex + k % codeLen]) {
                        code += input[i++];
                        k++;
                    }
                }
                codes.push_back(new Code(offset, code.length() - 1, input[i]));
            }
            updateDict(dict, code);
            code = "";
        }
    }
}

int main() {
    int n;
    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open()) {
        string input;
        fin >> input;
        fin.close();

        vector<Code *> codes;
        encode(codes, input);


        fstream fout;
        fout.open("output.txt", ios::out);
        fout << codes.size() << endl;
        for (auto &code : codes) {
            fout << code->offset << " " << code->length << " " << code->next << " ";
        }
        fout.close();

        for (auto &code : codes) {
            delete code;
        }
    }
    return 0;

}

