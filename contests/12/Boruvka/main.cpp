﻿#include "ReadWriter.h"
//string, fstream, iostream, vector, algorithm, Edge.h - included in ReadWriter.h

//Можно создавать любые классы и методы для решения задачи

using namespace std;

// Будем использовать для удобства реализацию Union Find

int findSet(const vector<pair<int, int>> &parentsAndKeys, int i) {
    if (i == parentsAndKeys[i].first) return i;
    return findSet(parentsAndKeys, parentsAndKeys[i].first);
}

// Доп функция для удобства нахождения сразу двух значений
void findSets(const vector<pair<int, int>> &parentsAndKeys, int &a, int &b, int i, int j) {
    a = findSet(parentsAndKeys, i);
    b = findSet(parentsAndKeys, j);
}

// Union по ключу
void unionSet(vector<pair<int, int>> &parentsAndKeys, int i, int j) {
    int a, b;
    findSets(parentsAndKeys, a, b, i, j);
    if (parentsAndKeys[a].second < parentsAndKeys[b].second)
        parentsAndKeys[a].first = b;
    else if (parentsAndKeys[a].second != parentsAndKeys[b].second)
        parentsAndKeys[b].first = a;
    else {
        parentsAndKeys[b].first = a;
        parentsAndKeys[a].second++;
    }
}

//Основной метод решения задачи, параметры:
//N - количество вершин, M - количество ребер в графе
//edges - вектор ребер, каждое ребро представлено 3-мя числами (А,В,W), где A и B - номера вершин, которые оно соединяет, и W - вес ребра,
//передается по ссылке (&), чтобы не копировать, изменять вектор и его значения можно.
//Результат также в виде вектора ребер, передается по ссылке (&), чтобы не копировать его.
void solve(int N, int M, vector<Edge> &edges, vector<Edge> &result) {
    //Советую разделить решение на логические блоки
    //Можно использовать любые другие структуры, но затем скопировать ответ в структуру Edge для записи результата в файл.
    //Также можно добавить любые необходимые компараторы для предложенного класса Edge, так как все методы и поля публичные.
    vector<pair<int, int>> parentsAndKeys(N);
    vector<int> minEdges(N, -1);
    for (int i = 0; i < N; ++i) {
        parentsAndKeys[i].first = i;
    }
    int count = N;
    while (count != 1) {
        fill(minEdges.begin(), minEdges.end(), -1);
        for (int i = 0; i < M; ++i) {
            int a, b;
            findSets(parentsAndKeys, a, b, edges[i].A, edges[i].B);
            if (a != b) {
                // Находим минмальный вес ребра, инцидентных вершинам
                if (minEdges[a] == -1 || edges[minEdges[a]].W > edges[i].W) minEdges[a] = i;
                if (minEdges[b] == -1 || edges[minEdges[b]].W > edges[i].W) minEdges[b] = i;
            }
        }
        // Добавляем ближайшое ребро к MST, если он еще не добавлен
        for (int i = 0; i < N; ++i) {
            if (minEdges[i] != -1) {
                int a, b;
                findSets(parentsAndKeys, a, b, edges[minEdges[i]].A, edges[minEdges[i]].B);
                if (a != b) {
                    result.push_back(edges[minEdges[i]]);
                    unionSet(parentsAndKeys, a, b);
                    count--;
                }
            }
        }
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