
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Node {
public:
    ~Node() {
        if(isZero){
            delete next;
        }
    }

    Node(int val, Node *n = nullptr) {
        value = val;
        next = n;
    }

    int value;
    bool isZero = false;
    Node *next;
};

class Huffman {
public:
    ~Huffman() {
        for (auto & chance : chances)
            delete chance;
    }

    void build() {
        // запускает алгоритм (после того как были добавлены все элементы)
        Node *min = v.back();
        v.pop_back();
        Node *predMin = v.back();
        v.pop_back();

        Node *parent = new Node(min->value + predMin->value);
        predMin->next = parent;
        min->next = parent;
        min->isZero = true;

        if (v.empty())
            return;

        std::vector<Node *>::iterator it;
        for (it = v.begin(); it != v.end(); ++it) {
            if (parent->value > (*it)->value)
                break;
        }

        v.emplace(it, parent);

        build();
    }

    void addChance(int chance) {
        // добавляет элемент в список (дерево, все зависит от реализации)
        Node *tmp = new Node(chance);
        v.push_back(tmp);
        chances.push_back(tmp);
    }

    string get(int i) {
        // выдает битовый код i символа
        Node *tmp = chances[i];
        string res;
        while (tmp->next != nullptr) {
            res = (tmp->isZero ? "0" : "1") + res;
            tmp = tmp->next;
        }
        return res;
    }

private:
    vector<Node *> v;
    vector<Node *> chances;
};


int main() {

    int n;
    Huffman *huff = new Huffman();
    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            fin >> x;
            huff->addChance(x);
        }

        fin.close();

        huff->build();
        fstream fout;
        fout.open("output.txt", ios::out);
        for (int i = 0; i < n; i++) {
            fout << huff->get(i) << (i == n - 1 ? "" : " ");
        }
        fout.close();
        delete huff;

    }

    return 0;

}

