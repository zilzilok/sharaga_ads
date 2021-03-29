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

static string get(ul N, ul K) {
    vector<ul> A(N, 1);
    ul i = N - 1, currN = N + 1;
    K--;
    while(K > 0) {
        currN--;
        A[i--] = K % currN + 1;
        K /= currN;
    }
    stringstream ss;
    for (i = 0; i < N - 1; ++i) {
        ss << A[i] << " ";
    }
    ss << A[N - 1];
    return ss.str();
}

int main(int argc, const char *argv[]) {
    ul N, K;
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open()) {
        string str;
        getline(fin, str);
        N = stoul(str.c_str());
        getline(fin, str);
        K = stoul(str.c_str());
        fout << get(N, K) << endl;

        fout.close();
        fin.close();
    }
    return 0;
}