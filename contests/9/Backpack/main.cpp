#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Основная задача - реализовать данный метод
int getMaxValue(int N, int M, vector<int> &masses, vector<int> &values) {
    int **A = new int *[N + 1];
    for (int i = 0; i <= N; ++i)
        A[i] = new int[M + 1]{};

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            if (j < masses[i - 1])
                A[i][j] = A[i - 1][j];
            else {
                A[i][j] = max(A[i - 1][j], A[i - 1][j - masses[i - 1]] + values[i - 1]);
            }
        }
    }

    int res = A[N][M];

    for (int i = 0; i <= N; ++i)
        delete[] A[i];
    delete[] A;

    return res;
}


int main() {

    int n = 0, m = 0;
    vector<int> masses;
    vector<int> values;
    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open()) {
        fin >> n >> m;
        int tmp;
        for (int i = 0; i < n; ++i) {
            fin >> tmp;
            masses.push_back(tmp);
        }
        for (int i = 0; i < n; ++i) {
            fin >> tmp;
            values.push_back(tmp);
        }
        fin.close();
    }

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << getMaxValue(n, m, masses, values);
    fout.close();

    return 0;
}
