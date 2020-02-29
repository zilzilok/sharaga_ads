#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

//Необходимо реализовать метод
//о алгоритме можно прочитать в источниках указанных в программе курса, или на странице курса в ЛМС или в презентациях к семинару.
int Wagner_Fischer_for_Damerau_Levenshtein(string &s, string &t) {
    int sLength = s.length();
    int tLength = t.length();
    int **d = new int *[sLength + 1];
    for (int i = 0; i <= sLength; ++i)
        d[i] = new int[tLength + 1];

    // Начальная инициализация таблицы
    d[0][0] = 0;
    for (int i = 1; i <= sLength; ++i) {
        d[i][0] = d[i - 1][0] + 1;
    }
    for (int i = 1; i <= tLength; ++i) {
        d[0][i] = d[0][i - 1] + 1;
    }

    // Инициализация таблицы
    int rm, add, ins, tr;
    for (int i = 1; i <= sLength; ++i) {
        for (int j = 1; j <= tLength; ++j) {
            rm = d[i - 1][j] + 1;
            add = d[i][j - 1] + 1;
            ins = d[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1);
            d[i][j] = min(min(rm, add), ins);
            if (i >= 2 && j >= 2 && s[i - 1] == t[j - 2] && s[i - 2] == t[j - 1]) {
                tr = d[i - 2][j - 2] + 1;
                d[i][j] = min(d[i][j], tr);
            }
        }
    }

    int res = d[sLength][tLength];

    // Освобождаем память
    for (int k = 0; k <= sLength; ++k) {
        delete[] d[k];
    }
    delete[] d;

    return res;
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main(int argc, const char *argv[]) {
    int n;
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open()) {
        string N;
        getline(fin, N);
        n = atoi(N.c_str());
        for (int i = 0; i < n; i++) {
            string s;
            string t;
            getline(fin, s);
            getline(fin, t);
            fout << Wagner_Fischer_for_Damerau_Levenshtein(s, t) << (i == n - 1 ? "" : " ");
        }
        fout.close();
        fin.close();
    }
    return 0;
}