#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

//Необходимо реализовать метод используя рекурсивный подход
int recursiveLevenshteinDistance(string &s, int i, string &t, int j){
    if (min(i, j) == -1)
        return max(i, j) + 1;

    int rm = recursiveLevenshteinDistance(s, i - 1, t, j) + 1;
    int add = recursiveLevenshteinDistance(s, i, t, j - 1) + 1;
    int ins = recursiveLevenshteinDistance(s, i - 1, t, j - 1) + (s[i] == t[j] ? 0 : 1);

    return min(min(rm, add), ins);
}

int LevenshteinDistance(string &s, int len_s, string &t, int len_t) {
    return recursiveLevenshteinDistance(s, len_s - 1, t, len_t - 1);
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main() {
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open()) {
        string N;
        getline(fin, N);
        int n = atoi(N.c_str());       // Я тута изменил, потому что некомпил
        for (int i = 0; i < n; i++) {
            string s;
            string t;
            getline(fin, s);
            getline(fin, t);
            fout << LevenshteinDistance(s, s.length(), t, t.length()) << (i == n - 1 ? "" : " ");
        }
        fout.close();
        fin.close();
    }
    return 0;
}
