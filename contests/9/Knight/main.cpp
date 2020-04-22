#include "ReadWriter.h"
//string, iostream included in "ReadWriter.h"

using namespace std;


//Можно добавлять любые вспомогательные методы и классы для решения задачи.
long long count(long long **A, int N, int M, int i, int j) {
    if (i == 0 && j == 0)
        return 1;
    if (A[i][j] != -1)
        return A[i][j];
    A[i][j] = 0;
    if (i - 2 >= 0 && j - 1 >= 0) {
        A[i][j] += count(A, N, M, i - 2, j - 1);
    }
    if (i - 1 >= 0 && j - 2 >= 0) {
        A[i][j] += count(A, N, M, i - 1, j - 2);
    }
    if (i - 2 >= 0 && j + 1 < M) {
        A[i][j] += count(A, N, M, i - 2, j + 1);
    }
    if (i + 1 < N && j - 2 >= 0) {
        A[i][j] += count(A, N, M, i + 1, j - 2);
    }
    return A[i][j];
}

//Задача реализовать этот метод
//param N - количество строк (rows) доски
//param M - количество столбцов (columns) доски
//return - количество способов попасть в правый нижний угол доски (клетка N-1, M-1, если считать что первая клетка 0,0)
long long solve(int N, int M) {
    long long **A = new long long *[N];
    for (int i = 0; i < N; ++i) {
        A[i] = new long long[M];
        for (int j = 0; j < M; ++j)
            A[i][j] = -1;
    }

    A[0][0] = 0;
    long long res = count(A, N, M, N - 1, M - 1);

    for (int i = 0; i < N; ++i)
        delete[] A[i];
    delete[] A;

    return res;
}

int main(int argc, const char *argv[]) {
    ReadWriter rw;

    int N = rw.readInt(); //количество строк (rows)
    int M = rw.readInt(); //количество столбцов (columns)
    //решение
    long long res = solve(N, M);
    //результат в файл
    rw.writeLongLong(res);

    return 0;
}