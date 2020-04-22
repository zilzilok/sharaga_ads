#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Основная задача - реализовать данный метод
int getMark(int n, int a, int b, int c) {
    bool *states = new bool[n];
    for (int i = 0; i < n; ++i) {
        states[i] = false;
    }
    states[0] = true;
    for (int i = 1; i < n; ++i) {
        if(i >= a && !states[i]) states[i] = states[i - a];
        if(i >= b && !states[i]) states[i] = states[i - b];
        if(i >= c && !states[i]) states[i] = states[i - c];
    }

    int k = 0;
    for (int i = 0; i < n; ++i) {
        if(states[i])
            k++;
    }

    delete[] states;
    return k;
}


int main() {

    int N = 0, A = 0, B = 0, C = 0;
    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open()) {
        fin >> N >> A >> B >> C;
        fin.close();
    }

    fstream fout;
    fout.open("output.txt", ios::out);

    fout << getMark(N, A, B, C);
    fout.close();

    return 0;
}
