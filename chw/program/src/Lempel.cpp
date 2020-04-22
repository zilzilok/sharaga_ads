#include <vector>
#include "Algorithm.h"

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

void updateDict(int &dictStart, int &dictSize, int codeSize, int dictLen) {
    if (dictSize + codeSize > dictLen) {
        dictStart += dictSize + codeSize - dictLen;
        dictSize = dictLen;
    } else
        dictSize += codeSize;
}

string getCode(string &input, int dictLen, int lookHeadLen) {
    string res;
    string code, tmp;
    int dictStart = 0;
    int dictSize = 0;
    int codeIndex = 0;
    bool flag = true;
    int n = input.length();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        code += input[i];
        if (flag) {
            tmp = input.substr(dictStart);
            flag = false;
        }
        int index = getSubstringIndex(code, tmp);
        if (index != -1 && index < dictSize) {
            codeIndex = index;
            if (code.length() <= lookHeadLen)
                continue;
        }

        if (code.length() == 1) {
            res += to_string(0) + " " + to_string(0) + " " + input[i] + " ";
            count++;
        } else {
            int offset = dictSize - codeIndex;
            if (code.length() <= lookHeadLen && offset == code.length() - 1) {
                int k = 0, codeLen = (int) code.length() - 1;
                while (code.length() <= lookHeadLen && input[i] == input[dictStart + codeIndex + k % codeLen]) {
                    code += input[i++];
                    k++;
                }
            }
            res += to_string(offset) + " " + to_string(code.length() - 1) + " " + input[i] + " ";
            count++;
        }
        flag = true;
        updateDict(dictStart, dictSize, code.length(), dictLen);
        code = "";
    }
    return to_string(count) + "\n" + res;
}

void Lempel::packFile(fstream &fin, fstream &fout) {
    char tmp;
    string input;
    while (fin >> noskipws >> tmp)
        input += tmp;

    string res = getCode(input, dictLen, lookheadLen);

    fout << res;
}

void Lempel::unpackFile(fstream &fin, fstream &fout) {
    short offset, length;
    char next;
    string res;
    int n;
    fin >> n;
    for (int i = 0; i < n; ++i) {
        fin >> offset >> length;
        fin.get(next);
        fin.get(next);
        if (length != 0) {
            int start_i = res.length() - offset;
            for (int j = 0; j < length; ++j) {
                res += res[start_i + j % length];
            }
        }
        res += next;
    }
    fout << res;
}