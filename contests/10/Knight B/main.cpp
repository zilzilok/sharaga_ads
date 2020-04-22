#include <stack>
#include <algorithm>
#include "ReadWriter.cpp"

//Можно добавлять любые методы для решения задачи.
bool compareNode(Node *n1, Node *n2) {
    return n1->name > n2->name;
}

//Задача - реализовать данный метод, решение должно быть в переменной result
void solve(std::vector<Node> &graph, int start, std::vector<std::string> &result) {
    std::stack<Node *> s;

    Node *curr = &graph[start];
    s.push(curr);

    while (!s.empty()) {
        std::vector<Node *> neighbours;
        curr = s.top();
        s.pop();
        if (!curr->visited) {
            result.push_back(curr->name);
            curr->visited = true;
            for (Node *neighbour : curr->neighbours) {
                if (!neighbour->visited)
                    neighbours.push_back(neighbour);
            }

            if (!neighbours.empty()) {
                std::sort(neighbours.begin(), neighbours.end(), compareNode);
                for (Node *node : neighbours)
                    s.push(node);
            }
        }
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
