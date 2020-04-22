#include "ReadWriter.h"
//vector, string, iostream included in "ReadWriter.h"

using namespace std;

//Можно добавлять любые вспомогательные методы и классы для решения задачи.

//Задача реализовать этот метод
//param N - количество предметов
//param W - ограничения на вес рюкзака
//param items - массив размера N, с предметами - first = вес, second = стоимость
//param res - вектор результатов (предметы, которые надо взять)
void solve(int N, int W, pair<int, int> *items, vector<pair<int, int>> &res) {
    int **A = new int *[N + 1];
    for (int i = 0; i <= N; ++i)
        A[i] = new int[W + 1]{};

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= W; ++j) {
            if (j < items[i - 1].first)
                A[i][j] = A[i - 1][j];
            else
                A[i][j] = max(A[i - 1][j], A[i - 1][j - items[i - 1].first] + items[i - 1].second);
        }
    }

    int i = N, j = W;
    while (i > 0 && j > 0) {
        if (A[i][j] != A[i - 1][j]) {
            j -= items[i - 1].first;
            res.emplace_back(items[i - 1].first, items[i - 1].second);
        }
        i--;
    }

    for (int k = 0; k <= N; ++k)
        delete[] A[k];
    delete[] A;
}

int main(int argc, const char *argv[]) {
    ReadWriter rw;
    int N = rw.readInt(); //количество предметов
    int W = rw.readInt(); //ограничения на вес рюкзака

    //структура массив pair выбрана, так как известно количество и у объекта всего 2 характеристики
    //first = вес(weight), second = стоимость (cost)
    //Можно переложить данные в любую другую удобную струтуру
    //Внимание(!) данные не упорядочены, но можно это сделать если вам требуется
    pair<int, int> *arr = new pair<int, int>[N];
    rw.readArr(arr, N);

    //структура вектор pair выбрана, так как неизвестно количество элементов, и у объекта всего 2 характеристики
    //результат, также first = вес(weight), second = стоимость (cost)
    vector<pair<int, int>> res;
    solve(N, W, arr, res);

    int sumCost = 0, sumWeight = 0;
    for (int i = 0; i < res.size(); i++) {
        sumWeight += res[i].first;
        sumCost += res[i].second;
    }
    //записываем ответ в файл
    rw.writeInt(sumCost);
    rw.writeInt(sumWeight);
    rw.writeInt(res.size());
    rw.writeVector(res);

    delete[] arr;
    return 0;
}