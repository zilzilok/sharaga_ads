#include "ReadWriter.h"
#include <queue>
#include <climits>
//string, fstream, iostream, vector, algorithm, Edge.h - included in ReadWriter.h

//Можно создавать любые классы и методы для решения задачи

using namespace std;

//Основной метод решения задачи, параметры:
//N - количество вершин, M - количество ребер в графе
//edges - вектор ребер, каждое ребро представлено 3-м   я числами (А,В,W), где A и B - номера вершин, которые оно соединяет, и W - вес ребра,
//передается по ссылке (&), чтобы не копировать, изменять вектор и его значения можно.
//Результат также в виде вектора ребер, передается по ссылке (&), чтобы не копировать его.
void solve(int N, int M, vector<Edge> &edges, vector<Edge> &result) {
    //Советую разделить решение на логические блоки
    //Можно использовать любые другие структуры, но затем скопировать ответ в структуру Edge для записи результата в файл.
    //Также можно добавить любые необходимые компараторы для предложенного класса Edge, так как все методы и поля публичные.
    // Матрица смежности для удобства
    vector<vector<pair<int, int>>> adj(N);
    for (Edge &edge : edges) {
        adj[edge.A].push_back(make_pair(edge.W, edge.B));
        adj[edge.B].push_back(make_pair(edge.W, edge.A));
    }

    vector<int> parents(N, -1);
    vector<int> keys(N, INT_MAX);
    vector<bool> isUsed(N, false);
    // пара ключ-номер вершины
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Берём нулевую вершину за изначальную
    keys[0] = 0;
    pq.push(make_pair(0, 0));

    while (!pq.empty()) {
        int A = pq.top().second;
        pq.pop();
        isUsed[A] = true;
        for (pair<int, int> &edge : adj[A]) {
            int B = edge.second;
            int W = edge.first;
            if (!isUsed[B] && keys[B] > W) {
                keys[B] = W;
                parents[B] = A;
                pq.push(make_pair(W, B));
            }
        }
    }

    for (Edge &edge : edges) {
        if (parents[edge.B] == edge.A || parents[edge.A] == edge.B)
            result.push_back(edge);
    }
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
    //(а предложенные алгоритмы работают итеративно, увеличивая количество ребер входящих в решение на каждом шаге)
    vector<Edge> result;

    //Алгоритм решения задачи
    //В решение должны входить ребра из первоначального набора!
    solve(N, M, edges, result);

    //Выводим результаты
    rw.writeInt(result.size());
    rw.writeEdges(result);

    return 0;
}