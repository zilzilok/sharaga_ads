#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
void print(fstream &fout, vector<int> &A, int last) {
    for (int i = 0; i < last; ++i) {
        fout << A[i] << " ";
    }
    fout << A[last] << "\n";
}

#define MAX 12

bool getNext(vector<int> &A, int &last) {
    int k;
    for (k = last - 1; k > 0; --k) {
        if (A[k - 1] > A[k] || A[k] == MAX)
            break;
    }
    if (A[k] == MAX) k++;
    A[k]++;
    int sum = 0;
    for (int i = k + 1; i <= last; ++i) {
        sum += A[i];
    }

    if(sum == 0)
        return false;

    for (int i = k + 1, j = 0; i <= last && j < sum - 1; ++i, ++j) {
        A[i] = 1;
    }
    last = k + sum - 1;
    return true;
}

void get(fstream &fout, int N) {
    if (N > 0) {
        vector<int> A(N, 1);
        int last = N - 1;
        print(fout, A, last);
        while (last != 0 && getNext(A, last)) {
            print(fout, A, last);
        }
    }
}

int main(int argc, const char *argv[]) {
    int N;
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open()) {
        string str;
        getline(fin, str);
        N = atoi(str.c_str());
        get(fout, N);
        fout.close();
        fin.close();
    }
    return 0;
}