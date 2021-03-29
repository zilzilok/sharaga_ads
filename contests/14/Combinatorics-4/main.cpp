#include "BigIntegerAlgorithms.hh"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)

static void getNext(vector<int> &C, int N, int m) {
    int i, k = N;
    for (i = m - 1; i >= 0; --i) {
        if (C[i] < k--)
            break;
    }
    if (i >= 0) {
        C[i]++;
        for (int j = i + 1; j < m; ++j) {
            if (C[j] - 1 > C[j - 1]) {
                while (C[j] - 1 > C[j - 1]) {
                    C[j]--;
                }
                break;
            }
        }
    }
}

static string get(int N, int k, int m) {
    vector<int> C(m);
    for (int i = 0; i < m; i++)
        C[i] = i + 1;
    for (int i = 1; i < k; ++i) {
        getNext(C, N, m);
    }
    stringstream ss;
    for (int i = 0; i < m - 1; ++i) {
        ss << C[i] << " ";
    }
    ss << C[m - 1];
    return ss.str();
}

int main(int argc, const char *argv[]) {
    int M, N, K;
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open()) {
        string str;
        getline(fin, str);
        N = atoi(str.c_str());
        getline(fin, str);
        K = atoi(str.c_str());
        getline(fin, str);
        M = atoi(str.c_str());
        fout << get(N, K, M) << endl;

        fout.close();
        fin.close();
    }
    return 0;
}