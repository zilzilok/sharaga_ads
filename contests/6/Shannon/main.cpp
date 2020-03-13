
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;
class Node{
public:
    Node(int val){
        value = val;
    }

    int value;
    string code;
};


class ShannonFano {
public:
     ~ShannonFano(){
         for(Node* node : chances)
             delete node;
     }

    ShannonFano()// можно изменить что бы принимал на вход количество элементов
    {

    }

    int findMedian(int left, int right){
        if(right - left >= 2) {
            int lSum1 = chances[left]->value;
            int rSum1 = 0;
            for (int i = left + 1; i <= right; ++i) {
                rSum1 += chances[i]->value;
            }
            int abs1 = abs(lSum1 - rSum1);

            int lSum2 = lSum1, rSum2 = rSum1, abs2, dif = 1;
            while(left + dif != right) {
                lSum2 += chances[left + dif]->value;
                rSum2 -= chances[left + dif]->value;
                abs2 = abs(lSum2 - rSum2);

                if(abs1 <= abs2)
                    break;

                abs1 = abs2;
                dif++;
            }
            return left + dif - 1;
        }
        return left;
    }

    void buildRecursive(int left, int right){
        if(left != right) {
            int med = findMedian(left, right);
            for (int i = left; i <= med; ++i) {
                chances[i]->code += "0";
            }
            buildRecursive(left, med);

            for (int i = med + 1; i <= right; ++i) {
                chances[i]->code += "1";
            }
            buildRecursive(med + 1, right);
        }
    }

    void build() {
        // запускает алгоритм (после того как были добавлены все элементы)
        buildRecursive(0, chances.size() - 1);
    }

    void addChance(int chance) {
        // добавляет элемент в список (дерево, все зависит от реализации)
        chances.push_back(new Node(chance));
    }

    string get(int i) {
        // выдает битовый код i символа
        return chances[i]->code;
    }

private:
    vector<Node*> chances;

};


int main() {

    int n;
    ShannonFano *shf = new ShannonFano();

    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open()) {
        fin >> n;
        for (int i = 0; i < n; i++) {
            int x;
            fin >> x;
            shf->addChance(x);
        }

        fin.close();

        shf->build();
        fstream fout;
        fout.open("output.txt", ios::out);
        for (int i = 0; i < n; i++) {
            fout << shf->get(i) << (i == n - 1 ? "" : " ");
        }
        fout.close();
        delete shf;

    }
    return 0;
}