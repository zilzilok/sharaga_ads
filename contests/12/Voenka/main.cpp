#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Edge {
public:
    int A;
    int B;
};

void solve(vector<Edge> &edges, vector<int> &result) {
    int N = edges.size() + 1;
    vector<vector<int>> adj(N);
    vector<int> degree(N);  // степень вершины (количество рёбер инцидентных вершине)
    vector<int> level(N);   // уровень вершины
    for (Edge &edge : edges) {
        int A = edge.A - 1;
        int B = edge.B - 1;
        adj[A].push_back(B);
        adj[B].push_back(A);
        degree[A]++;
        degree[B]++;
    }

    for (int i = 0; i < N; ++i) {
        cout << i << " " << degree[i] << endl;
    }

    queue<int> q;
    // Добавляем в очередь все листья
    for (int i = 0; i < N; ++i) {
        if (degree[i] == 1)
            q.push(i);
    }

    int maxLevel = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            // т.к. родителя мы удалили поэтому изначально инкрементируем
            if (--degree[u] == 1) {
                q.push(u);
                maxLevel = max(maxLevel, (level[u] = level[v] + 1));
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        if (level[i] == maxLevel)
            result.push_back(i + 1);
    }
}

int main() {
    int N;
    vector<Edge> edges;
    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open()) {
        fin >> N;
        for (int i = 0; i < N - 1; ++i) {
            Edge e;
            fin >> e.A >> e.B;
            edges.push_back(e);
        }
        fin.close();
    }

    vector<int> result;
    solve(edges, result);

    fstream fout;
    fout.open("output.txt", ios::out);
    sort(result.begin(), result.end());
    fout << result.size() << endl;
    for (int i : result) {
        fout << i << " ";
    }
    fout.close();

    return 0;
}