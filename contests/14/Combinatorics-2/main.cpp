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
int currVariation = 0;
bool isResult = false;

static void solve(int curr, vector<bool> &isUsed, vector<int> &A, int &N, int &k, int &m) {
    for (int i = 0; i < N; ++i) {
        if (isResult)
            break;
        if (!isUsed[i]) {
            isUsed[i] = true;
            A[curr] = i + 1;
            if (curr + 1 < m)
                solve(curr + 1, isUsed, A, N, k, m);
            else if (++currVariation == k) {
                isResult = true;
                break;
            }
            isUsed[i] = false;
        }
    }
}

static string get(int N, int k, int m) {
    vector<bool> isUsed(N, false);
    vector<int> A(m);
    solve(0, isUsed, A, N, k, m);
    stringstream ss;
    for (int i = 0; i < m - 1; ++i) {
        ss << A[i] << " ";
    }
    ss << A[m - 1];
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