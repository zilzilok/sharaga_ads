#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
typedef unsigned long ul;

string get(ul N, ul M, ul K) {
    vector<ul> A(M, 1);
    ul i = M - 1;
    K--;
    while(K > 0) {
        A[i--] = K % N + 1;
        K /= N;
    }
        stringstream ss;
    for (i = 0; i < M - 1; ++i) {
        ss << A[i] << " ";
    }
    ss << A[M - 1];
    return ss.str();
}

int main(int argc, const char *argv[]) {
    ul M, N, K;
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open()) {
        string str;
        getline(fin, str);
        N = stoul(str.c_str());
        getline(fin, str);
        M = stoul(str.c_str());
        getline(fin, str);
        K = stoul(str.c_str());
        fout << get(N, M, K) << endl;

        fout.close();
        fin.close();
    }
    return 0;
}