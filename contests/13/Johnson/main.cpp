#include <algorithm>
#include <climits>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 130001

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

void read2Ints(fstream &fin, int &N, int &M) {
    if (!fin.is_open())
        throw std::ios_base::failure("file not open");

    fin >> N;
    //empty line read
    std::string s;
    std::getline(fin, s);
    fin >> M;
    //empty line read
    std::getline(fin, s);
}

void readEgdes(fstream &fin, int M, std::vector<Edge> &edges) {
    if (!fin.is_open())
        throw std::ios_base::failure("file not open");

    std::string s;
    for (int i = 0; i < M; i++) {
        Edge e;
        fin >> e.A >> e.B >> e.W;
        edges.push_back(e);
        //empty line read
        std::getline(fin, s);
    }
}

void writeValues(fstream &fout, vector<vector<int>> &result) {
    if (!fout.is_open())
        throw ios_base::failure("file not open");

    if (!result.empty()) {
        int N = result.size();
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i != j)
                    fout << i << " " << j << " " << (result[i][j] == MAX ? -1 : result[i][j]) << "\n";
            }
        }
    }
}

bool bellmanFord(int v, int N, int M, vector<Edge> &edges, vector<int> &d) {
    d.assign(N, INT_MAX);
    d[v] = 0;
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
    return i != N || !isRelaxed;
}

void dijkstra(int N, int k, vector<vector<pair<int, int>>> &adj, vector<int> &d) {
    d.assign(N, MAX);
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, k));
    d[k] = 0;
    while (!pq.empty()) {
        int u = pq.top().second, w = -pq.top().first;
        pq.pop();
        if (w > d[u]) continue;

        for (int v = 0; v < adj[u].size(); ++v) {
            int B = adj[u][v].first, W = adj[u][v].second;
            if (d[u] + W < d[B]) {
                d[B] = d[u] + W;
                pq.push(make_pair(-d[B], B));
            }
        }
    }
}

void solve(int N, int M, vector<Edge> &edges, vector<vector<int>> &result) {
    int mN = N + 1, mM = M + N;
    for (int i = 0; i < N; ++i) {
        edges.emplace_back(N, i, 0);
    }

    vector<int> bellmanFordRes;
    if (bellmanFord(N, mN, mM, edges, bellmanFordRes)) {
        vector<vector<pair<int, int>>> adj(mN);
        result.assign(N, vector<int>(N, MAX));
        for (Edge &edge : edges)
            adj[edge.A].emplace_back(edge.B, edge.W);

        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj[i].size(); ++j) {
                adj[i][j].second += bellmanFordRes[i] - bellmanFordRes[adj[i][j].first];
            }
        }
        for (int u = 0; u < N; ++u) {
            vector<int> dijkstraRes;
            dijkstra(mN, u, adj, dijkstraRes);
            for (int v = 0; v < N; ++v) {
                if (dijkstraRes[v] != MAX)
                    result[u][v] = dijkstraRes[v] + bellmanFordRes[v] - bellmanFordRes[u];
            }
        }

    } else {
        result.clear();
    }
}

int main() {
    //Входные параметры
    //N - количество вершин, M - количество ребер в графе
    fstream fin;
    fin.open("input.txt", std::ios::in);
    int N, M;
    read2Ints(fin, N, M);
    //Вектор ребер, каждое ребро представлено 3-мя числами (А, В, W), где A и B - номера вершин, которые оно соединяет, и W - вес ребра
    //Основной структурой выбран вектор, так как из него проще добавлять и удалять элементы (а такие операции могут понадобиться).
    vector<Edge> edges;
    readEgdes(fin, M, edges);
    fin.close();

    vector<vector<int>> result(N);

    fstream fout;
    fout.open("output.txt", std::ios::out);

    //Алгоритм решения задачи
    solve(N, M, edges, result);

    writeValues(fout, result);
    fout.close();
    return 0;
}