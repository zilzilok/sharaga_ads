#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Основная задача - реализовать данный метод
int countMaxCross(string &riverMap) {
    int n = riverMap.length();
    int *leftMin = new int[n + 1]{};    /* количество переправ (минимальное),
                                           чтобы попасть в текущего участок слева
                                           (начиная с 0 участка) */
    int *rightMin = new int[n + 1]{};   // аналогично справа

    rightMin[0] = 1;                    /* т.к. нужна одна переправа,
                                           чтоб попасть на правыц берег (изначально мы на левом) */

    for (int i = 1; i <= n; ++i) {
        // изначально мы считаем, что нет переправ в текущий участок
        leftMin[i] = leftMin[i - 1];
        rightMin[i] = rightMin[i - 1];
        if (riverMap[i - 1] == 'L') {
            leftMin[i] = leftMin[i - 1] + 1;
        } else if (riverMap[i - 1] == 'R') {
            rightMin[i] = rightMin[i - 1] + 1;
        } else {
            leftMin[i] = leftMin[i - 1] + 1;
            rightMin[i] = rightMin[i - 1] + 1;
        }

        if (leftMin[i] + 1 < rightMin[i])
            rightMin[i] = leftMin[i] + 1;
        else if (rightMin[i] + 1 < leftMin[i])
            leftMin[i] = rightMin[i] + 1;
    }

    int res = rightMin[n];     /* возвращаем количество переправ (минимальное)
                               до последнего участка справа */
    // Очищаем память
    delete[] leftMin;
    delete[] rightMin;

    return res;
}


int main() {
    string riverMap;
    int res;

    ifstream fin;
    fin.open("input.txt");
    if (fin.is_open()) {
        getline(fin, riverMap);
        fin.close();
    }

    res = countMaxCross(riverMap);

    fstream fout;
    fout.open("output.txt", ios::out);
    fout << res;
    fout.close();

    return 0;
}
