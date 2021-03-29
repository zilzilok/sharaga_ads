#include "ReadWriter.h"
#include <climits>
//string, fstream, iostream, vector, Edge.h - included in ReadWriter.h

//Можно создавать любые классы и методы для решения задачи

using namespace std;

//Основной метод решения задачи, параметры:
//N - количество вершин, M - количество ребер в графе
//edges - вектор ориентированных ребер, каждое ребро представлено 3-мя числами (А, В, W),
// где A и B - номера вершин, которые оно соединяет (Путь строго из А в В), и W - вес ребра
//передается по ссылке (&), чтобы не копировать, изменять вектор и его значения можно.
//Результат также в виде вектора кратчайших расстояний из 0-й вершины во все остальные начиная с 1-й, то есть N-1 значение должно быть
bool solve(int N, int M, vector<Edge> &edges, vector<int> &result) {
    vector<int> d(N, INT_MAX);
    d[0] = 0;
    int i;
    bool isRelaxed;
    for (i = 0; i < N; ++i) {
        isRelaxed = false;
        for (int j = 0; j < M; ++j) {
            int W = d[edges[j].A] + edges[j].W;
            // Процедура релаксации
            if (d[edges[j].A] < INT_MAX && W < d[edges[j].B]) {
                d[edges[j].B] = W;
                isRelaxed = true;
            }
        }
        if (!isRelaxed)
            break;
    }

    /* Если процедура выполнилась N-ый раз (от 0 до N-1)
     * и произошла релаксация, то очевидно есть отрицательный цикл */
    if (i != N || !isRelaxed) {
        for (i = 1; i < N; ++i) {
            result.push_back(d[i]);
        }
        return true;
    }
    return false;
}

int main() {
    ReadWriter rw;
    //Входные параметры
    //N - количество вершин, M - количество ребер в графе
    int N, M;
    rw.read2Ints(N, M);

    //Вектор ребер, каждое ребро представлено 3-мя числами (А, В, W), где A и B - номера вершин, которые оно соединяет, и W - вес ребра
    //Основной структурой выбран вектор, так как из него проще добавлять и удалять элементы (а такие операции могут понадобиться).
    vector<Edge> edges;
    rw.readEgdes(M, edges);

    //Основной структурой для ответа выбран вектор, так как в него проще добавлять новые элементы.
    vector<int> result;

    //Алгоритм решения задачи
    bool isNotNegativeLoop = solve(N, M, edges, result);

    //Выводим результаты
    if (isNotNegativeLoop)
        rw.writeInt(result.size());
    rw.writeIntValues(result);

    return 0;
}