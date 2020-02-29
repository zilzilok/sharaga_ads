#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int Wagner_Fischer(string &s, string &t, int numberOfErrors) {
    int sLength = s.length();
    int tLength = t.length();
    if (sLength > tLength)
        return Wagner_Fischer(t, s ,numberOfErrors);
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
    int rm, add, ins, maxJ, minJ;
    d[sLength][tLength] = -1;

    for (int i = 1; i <= sLength; ++i) {
        for (int j = max(1, i - numberOfErrors - 1); j <= min(tLength, ); ++j) {
            rm = d[i - 1][j] + 1;
            add = d[i][j - 1] + 1;
            ins = d[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1);
            d[i][j] = min(min(rm, add), ins);
        }
    }

    int res = d[sLength][tLength];

    // Освобождаем память
    for (int k = 0; k <= sLength; ++k) {
        delete[] d[k];
    }
    delete[] d;

    return res <= numberOfErrors;
}

int countSuitableCommands(string &cm, vector<string> &dict, int numberOfErrors) {
    int k = 0;
    for (string &str : dict) {
        if (abs((int)(str.length() - cm.length())) <= numberOfErrors)
            k += Wagner_Fischer(cm, str, numberOfErrors);
    }
    return k;
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main(int argc, const char *argv[]) {
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open()) {
        int N;
        fin >> N;
        vector<string> dict;
        string cm;
        for (int i = 0; i < N; ++i) {
            fin >> cm;
            dict.push_back(cm);
        }
        int numberOfErrors;
        fin >> numberOfErrors;
        fin >> N;
        for (int i = 0; i < N; i++) {
            fin >> cm;
            fout << countSuitableCommands(cm, dict, numberOfErrors) << endl;
        }
        fout.close();
        fin.close();
    }
    return 0;
}
