//
// Created by Kirill Golovko on 06/02/2019.
//

#include <string>
#include <vector>

class Node {
public:
    std::string name;
    std::vector<Node*> neighbours;
    bool visited = false;
    Node(std::string& name) : name(name){};
};