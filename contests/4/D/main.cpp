#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

vector<int> getPalindrome(string &str) {
    // Алгоритм Манакера
    int length = str.length();
    vector<int> cnt(length);
    vector<int> res(length);
    int l = 0;
    int r = -1;
    int tmp_cnt;
    int tmp;

    for (int i = 0; i <= length - 1; ++i) {
        tmp_cnt = i > r ? 1 : min(cnt[l + (r - i)], r - i + 1);
        tmp = i > r ? 1 : min(res[l + (r - i)], 2 * (r - i) + 1);
        while (i + tmp_cnt <= length - 1 && i - tmp_cnt >= 0 && str[i + tmp_cnt] == str[i - tmp_cnt]) {
            tmp_cnt += 1;
            tmp += 2;
        }

        cnt[i] = tmp_cnt;
        res[i] = tmp;
        if (i + tmp_cnt - 1 > r) {
            l = i - tmp_cnt + 1;
            r = i + tmp_cnt - 1;
        }
    }

    return res;
}

int main() {
    string str;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open()) {
        getline(fin, str);
        fin.close();
    }

    vector<int> res = getPalindrome(str);

    fstream fout;
    fout.open("output.txt", ios::out);

    for (int re : res)
        fout << re << " ";
    fout.close();
    return 0;
}
