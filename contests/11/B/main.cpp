#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// сортирует пары (индекс вершины, значение) в алфавитном порядке
bool compare(const pair<int, string> &a, const pair<int, string> &b) {
    return a.second < b.second;
}

void dfs(int v, vector<bool> &isUsed, vector<string> &names, vector<vector<bool>> &relations, vector<string> &res) {
    isUsed[v] = true;
    vector<pair<int, string>> neighbours;
    for (int w = 0; w < relations[v].size(); ++w) {
        if (relations[v][w])
            neighbours.emplace_back(w, names[w]);
    }

    sort(neighbours.begin(), neighbours.end(), compare);
    for (pair<int, string> &neighbour : neighbours) {
        if (!isUsed[neighbour.first])
            dfs(neighbour.first, isUsed, names, relations, res);
    }

    res.push_back(names[v]);
}

vector<string> getList(vector<string> &names, vector<vector<bool>> &relations) {
    int n = names.size();
    vector<string> res;
    vector<bool> isUsed(n, false);

    // найдем все вершины истоки в алфавитном порядке
    vector<pair<int, string>> begins;
    for (int j = 0; j < n; ++j) {
        bool flag = true;
        for (int i = 0; i < n; ++i) {
            if (relations[i][j]) {
                flag = false;
                break;
            }
        }
        if (flag)
            begins.emplace_back(j, names[j]);
    }
    sort(begins.begin(), begins.end(), compare);

    // Сделаем топологическую сортировку учитывая алфавитный порядок
    for (pair<int, string> &begin : begins)
        if (!isUsed[begin.first])
            dfs(begin.first, isUsed, names, relations, res);

    // Развернём, чтобы было по порядку
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<string> names = vector<string>();
    vector<vector<bool>> relations;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open()) {
        string str;
        getline(fin, str);

        while (str != "#") {
            names.emplace_back(str.substr(str.find(' ') + 1));
            getline(fin, str);
        }

        relations = vector<vector<bool>>(names.size());

        for (int i = 0; i < names.size(); i++) {
            relations[i] = vector<bool>(names.size());
            for (int j = 0; j < names.size(); j++)
                relations[i][j] = false;
        }

        getline(fin, str);

        while (fin) {
            int a = stoi(str.substr(0, str.find(' '))) - 1;
            int b = stoi(str.substr(str.find(' '))) - 1;
            relations[a][b] = true;
            getline(fin, str);
        }

        fin.close();
    }

    vector<string> res = getList(names, relations);

    fstream fout;
    fout.open("output.txt", ios::out);
    for (int i = 0; i < res.size(); i++)
        fout << res[i] << "\n";
    fout.close();

    return 0;
}
