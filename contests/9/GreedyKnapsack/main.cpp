#include "ReadWriter.h"
//vector, string, iostream, algorithm included in "ReadWriter.h"

using namespace std;

//Можно добавлять любые вспомогательные методы и классы для решения задачи.
void bubbleSort(int N, pair<int, int> *items, double *delta) {
    for (int i = 0; i < N - 1; ++i) {
        bool isSwapped = false;
        for (int j = 0; j < N - i - 1; ++j) {
            if ((delta[j] < delta[j + 1]) || (delta[j] == delta[j + 1] && items[j].first < items[j + 1].first)) {
                isSwapped = true;
                swap(items[j], items[j + 1]);
                swap(delta[j], delta[j + 1]);
            }
        }
        if (!isSwapped)
            break;
    }
}

//Задача реализовать этот метод (жадный алгоритм)
//param N - количество предметов
//param W - ограничения на вес рюкзака
//param items - массив размера N, с предметами - first = вес, second = стоимость
//param res - вектор результатов (предметы, которые надо взять)
void solve(int N, int W, pair<int, int> *items, vector<pair<int, int>> &res) {
    double *delta = new double[N];
    for (int i = 0; i < N; ++i) {
        delta[i] = (double) items[i].second / items[i].first;
    }

    bubbleSort(N, items, delta);
    delete[] delta;

    for (int i = 0; i < N; ++i) {
        int weight = items[i].first;
        if (weight <= W) {
            res.push_back(items[i]);
            W -= weight;
        }
    }
}

int main(int argc, const char *argv[]) {
    ReadWriter rw;
    int N = rw.readInt(); //количество предметов
    int W = rw.readInt(); //ограничения на вес рюкзака

    //структура массив pair выбрана, так как известно количество элементов, и у объекта всего 2 характеристики
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