//
// Created by Kirill Golovko on 06/02/2019.
//

#include <fstream>
#include <exception>
#include "Node.h"

class ReadWriter {
private:
    std::string inFilePath = "input.txt";
    std::string outFilePath = "output.txt";

public:
    void readGraph(std::vector<Node>& graph, int& start) {
        std::ifstream inFile(inFilePath);
        if(!inFile.is_open()) {
            throw std::ios_base::failure("Can't open: " + inFilePath);
        }
        std::string next;
        // reading names
        for (std::getline(inFile, next); next != "#"; std::getline(inFile, next)) {
            uint64_t firstSpace = next.find(' ');
            std::string name = next.substr(firstSpace + 1);
            graph.emplace_back(name);
        }
        //reading links
        for (std::getline(inFile, next); next != "#"; std::getline(inFile, next)) {
            uint64_t firstSpace = next.find(' ');
            int from = std::stoi(next.substr(0, firstSpace)) -1;
            int to = std::stoi(next.substr(firstSpace + 1)) - 1;
            graph[from].neighbours.push_back(&graph[to]);
            graph[to].neighbours.push_back(&graph[from]);
        }
        //reading start node
        inFile >> start;
        start--;
        inFile.close();
    }

    void writeAnswer(std::vector<std::string>& result) {
        std::ofstream outFile(outFilePath);
        if(!outFile.is_open()){
            throw std::ios_base::failure("Can't open: " + outFilePath);
        }
        for(std::string& next : result){
            outFile << next << std::endl;
        }
        outFile.close();
    }
};
