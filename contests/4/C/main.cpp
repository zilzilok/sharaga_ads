#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

//Основная задача - реализовать данный метод
//Можно изменить передачу параметров на ссылки (&)
//Можно добавлять любое количество любых вспомогательных методов, структур и классов
void getPrefix(int* prefix, string& str){
    int tmp;
    for (int i = 1; i <= str.length() - 1; ++i) {
        tmp = prefix[i - 1];
        while (tmp > 0 && str[i] != str[tmp])
            tmp = prefix[tmp - 1];
        if (str[i] == str[tmp])
            prefix[i] = ++tmp;
        else
            prefix[i] = 0;
    }
}

void getSubstrings(string &source, string &substring, vector<int> &res) {
    // Найдем массив граней
    int *prefix = new int[substring.length()]{};
    getPrefix(prefix, substring);

    for (int i = 0, k = 0; i < source.length(); ++i) {
        while (k > 0 && source[i] != substring[k])
            k = prefix[k - 1];

        if (source[i] == substring[k]) {
            k++;
            if (k == substring.length())
                res.push_back(i - substring.length() + 1);
        }
    }
    delete[] prefix;
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main() {
    string t;
    string p;
    vector<int> res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open()) {
        getline(fin, t);
        getline(fin, p);
        fin.close();
    }

    getSubstrings(t, p, res);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res.size() << "\n";
    for (std::vector<int>::const_iterator i = res.begin(); i != res.end(); ++i)
        fout << *i << "\n";
    fout.close();

    return 0;
}
