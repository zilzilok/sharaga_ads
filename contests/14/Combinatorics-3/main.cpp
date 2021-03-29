#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//Необходимо реализовать данный метод
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
void getNext(vector<int> &P, int N) {
    int i;
    for (i = N - 1; i > 0; --i) {
        if (P[i - 1] < P[i])
            break;
    }
    i--;

    int j = N - 1;
    while (P[j] <= P[i]){
        j--;
    }

    swap(P[i], P[j]);

    for (int k = i + 1; k < (i + 1 + N) / 2; ++k) {
        swap(P[k], P[N - k + i]);
    }
}

static string get_day(int N, int k) {
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        P[i] = i + 1;
    }

    for (int j = 1; j < k; ++j) {
        getNext(P, N);
    }

    stringstream ss;
    for (int i = 0; i < N - 1; ++i) {
        ss << P[i] << " ";
    }
    ss << P[N - 1];
    return ss.str();
}

int main(int argc, const char *argv[]) {

    int N, K;
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
        fout << get_day(N, K) << endl;

        fout.close();
        fin.close();
    }

    return 0;
}
