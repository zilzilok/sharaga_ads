#include <algorithm>
#include "ReadWriter.cpp"
#include <queue>

//Можно добавлять любые методы для решения задачи.

//Задача - реализовать данный метод, решение должно быть в переменной result
void solve(std::vector<Node> &graph, int start, std::vector<std::string> &result) {
    std::queue<Node> q;

    Node *curr = &graph[start];
    curr->visited = true;
    q.push(*curr);
    result.push_back(curr->name);

    while (!q.empty()) {
        std::vector<Node> neighbours;
        std::vector<std::string> neighboursNames;

        while (!q.empty()) {
            *curr = q.front();
            q.pop();
            for (Node *neighbour : curr->neighbours) {
                if (!neighbour->visited) {
                    neighbour->visited = true;
                    neighbours.push_back(*neighbour);
                    neighboursNames.push_back(neighbour->name);
                }
            }
        }
        for (Node &node : neighbours)
            q.push(node);

        std::sort(neighboursNames.begin(), neighboursNames.end());
        for (std::string &name : neighboursNames)
            result.push_back(name);
    }
}

int main() {
    std::vector<Node> graph;
    std::vector<std::string> result;
    int start;

    ReadWriter rw;
    rw.readGraph(graph, start);
    solve(graph, start, result);
    rw.writeAnswer(result);
    return 0;
}
