//
//  main.cpp
//  A
//
//  Created by Данил Нечай on 02.04.2018.
//  Updated by Плесовских Александр on 07.09.2018.
//  Copyright © 2018 Данил Нечай. All rights reserved.
//

#include "BigIntegerAlgorithms.hh"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

//Необходимо реализовать 3 метода (1,2,3).
//Вся информация о задаче доступна в тексте задачи и в слайдах презентации к семинару(в ЛМС)
static BigInteger FactTree(int n) //1
{
    BigInteger res = 1;
    for (int i = 2; i <= n; ++i) {
        res*= i;
    }
    return res;
}

static BigInteger C(int n, int k) //2
{
    return FactTree(n) / FactTree(k) / FactTree(n - k);
}

static BigInteger Pair(int n) //3
{
    BigInteger res = 1;
    for (int i = 1; i <= n; i += 2) {
        res *= i;
    }
    return res;
}

int main(int argc, const char *argv[]) {

    int n, N, K;
    fstream fin;
    fstream fout;
    fin.open("input.txt", ios::in);
    fout.open("output.txt", ios::out);
    if (fin.is_open()) {
        string str;
        getline(fin, str);
        N = atoi(str.c_str());
        n = N;
        getline(fin, str);
        K = atoi(str.c_str());
        fout << FactTree(N) << endl;
        fout << C(N, K) << endl;
        fout << Pair(N) << endl;
        fout.close();
        fin.close();
    }
    return 0;
}
