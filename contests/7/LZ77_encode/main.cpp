
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
    return flag ? i - (int) substring.length() + 1 : -1;
}

#define DICT_LEN 3072
#define LOOKHEAD_LEN 1024

void updateDict(int &dictStart, int &dictSize, int codeSize) {
    if (dictSize + codeSize > DICT_LEN) {
        dictStart += dictSize + codeSize - DICT_LEN;
        dictSize = DICT_LEN;
    } else
        dictSize += codeSize;
}

void encode(vector<Code *> &codes, string &input) {
    if (input.length() == 0)
        return;

    string code, tmp;
    int dictStart = 0;
    int dictSize = 0;
    int codeIndex = 0;
    bool flag = true;
    for (int i = 0; i < input.length(); ++i) {
        code += input[i];
        if (flag){
            tmp = input.substr(dictStart);
            flag = false;
        }
        int index = getSubstringIndex(code, tmp);
        if (index != -1 && index < dictSize) {
            codeIndex = index;
            if (code.length() <= LOOKHEAD_LEN)
                continue;
        }

        if (code.length() == 1) {
            codes.push_back(new Code(0, 0, input[i]));
        } else {
            int offset = dictSize - codeIndex;
            if (code.length() <= LOOKHEAD_LEN && offset == code.length() - 1) {
                int k = 0, codeLen = (int) code.length() - 1;
                while (code.length() <= LOOKHEAD_LEN && input[i] == input[dictStart + codeIndex + k % codeLen]) {
                    code += input[i++];
                    k++;
                }
            }
            codes.push_back(new Code(offset, (int) code.length() - 1, input[i]));
        }
        flag = true;
        updateDict(dictStart, dictSize, code.length());
        code = "";
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

