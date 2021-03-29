#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)

void getNext(vector<int> &A, int M, int N) {
    int i;
    for (i = M - 2; i >= 0; --i) {
        if (A[i] > A[i + 1])
            break;
    }


}

string get(int N, int M, int K) {
    vector<int> A(M, 0);
    A[0] = N;
    int ptr = 0;
    for (int i = 1; i < K; ++i) {
        if (ptr != M - 1) {
            --A[ptr++];
            A[ptr] = 1;
        } else {
            --ptr;
            for (; ptr >= 0; --ptr) {
                if (A[ptr] != 0)
                    break;
            }
            --A[ptr++];
            int tmp = A[M - 1];
            A[M - 1] = 0;
            A[ptr] = tmp + 1;
        }
    }
    stringstream ss;
    for (int i = 0; i < M - 1; ++i) {
        ss << A[i] << " ";
    }
    ss << A[M - 1];
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
        N = stoi(str.c_str());
        getline(fin, str);
        M = stoi(str.c_str());
        getline(fin, str);
        K = stoi(str.c_str());
        fout << get(N, M, K) << endl;

        fout.close();
        fin.close();
    }
    return 0;
}