#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

// Метод с презентации для нахождения компонент сильной связности по алгоритму Тарьяна
void strongConnect(int v, int &index,
                   stack<int> &s, vector<bool> &onStack,
                   vector<int> &pre, vector<int> &low,
                   vector<string> &names, vector<vector<bool>> &relations, vector<vector<string>>& res) {
    pre[v] = index;
    low[v] = index;
    index++;
    s.push(v);
    onStack[v] = true;
    for (int w = 0; w < relations[v].size(); ++w) {
        if (relations[v][w]) {
            if (pre[w] == -1) {
                strongConnect(w, index, s, onStack, pre, low, names, relations, res);
                low[v] = min(low[v], low[w]);
            } else {
                if (onStack[w])
                    low[v] = min(low[v], pre[w]);
            }
        }
    }
    if(low[v] == pre[v]){
        vector<string> scc;
        int w;
        do{
            w = s.top();
            s.pop();
            onStack[w] = false;
            scc.push_back(names[w]);
        }while(w != v);
        sort(scc.begin(), scc.end());
        res.push_back(scc);
    }
}

// Компаратор, для сортировки вектора векторов string в алфавитном порядке
bool compare(vector<string>& first, vector<string>& second){
    return first[0] < second[0];
}

vector<vector<string>> getList(vector<string> &names, vector<vector<bool>> &relations) {
    int n = names.size();
    vector<vector<string>> res;

    vector<int> pre(n);
    fill(pre.begin(), pre.end(), -1); // -1 будет говорить о том, что вершина ещё не посещена

    vector<int> low(n);

    stack<int> s;
    vector<bool> onStack(n);

    int index = 0;
    for (int i = 0; i < n; ++i) {
        if (pre[i] == -1)
            strongConnect(i, index, s, onStack, pre, low, names, relations, res);
    }

    sort(res.begin(), res.end(), compare);
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

    vector<vector<string>> res = getList(names, relations);

    fstream fout;
    fout.open("output.txt", ios::out);
    for (auto &re : res) {
        for (int j = 0; j < re.size(); j++)
            fout << re[j] << "\n";
        fout << "\n";
    }
    fout.close();

    return 0;
}
