#include <algorithm>
#include <climits>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 130000

class Edge {
public:
    int A;
    int B;
    int W;

    Edge() : Edge(0, 0, 0) {

    }

    Edge(int A, int B, int W) {
        this->A = A;
        this->B = B;
        this->W = W;
    }
};

void readInt(fstream &fin, int &N) {
    if (!fin.is_open())
        throw std::ios_base::failure("file not open");

    fin >> N;
}

void readEgdes(fstream &fin, int &N, std::vector<Edge> &edges) {
    if (!fin.is_open())
        throw std::ios_base::failure("file not open");

    std::string s;
    for (int i = 0; i < N; i++) {
        int W;
        fin >> W;
        edges.emplace_back(N, i, W);
    }

    for (int i = 0; i < N - 1; i++) {
        int W;
        fin >> W;
        edges.emplace_back(i, i + 1, W);
    }
}

void writeAnswer(fstream &fout, long long &res) {
    if (!fout.is_open())
        throw ios_base::failure("file not open");

    fout << res;
}

/**
 * Минимизируем стоимость подключения общежития к интернету так, чтобы во всех комнатах был интернет.
 * @param N количество комнат
 * @param M количество путей между комнатами
 * @param edges пути
 * @return минимальную стоимость подключения всех комнат к интернету
 */
long long solve(int N, vector<Edge> &edges) {
    // Воспользуемся алгоритмом Прима и найдем МОД
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

    long long res = 0;
    for (Edge &edge: edges) {
        if (parents[edge.A] == edge.B || parents[edge.B] == edge.A) {
            res += edge.W;
        }
    }
    return res;
}

int main() {
    //N - количество вершин
    fstream fin;
    fin.open("input.txt", std::ios::in);
    int N;
    readInt(fin, N);
    vector<Edge> edges;
    readEgdes(fin, N, edges);
    fin.close();

    fstream fout;
    fout.open("output.txt", std::ios::out);

    //Алгоритм решения задачи
    long long res = solve(N + 1, edges);

    writeAnswer(fout, res);
    fout.close();
    return 0;
}