#ifndef KDZ_ALGORITHM_H
#define KDZ_ALGORITHM_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Algorithm {
public:
    virtual ~Algorithm() = default;

    virtual void packFile(fstream &fin, fstream &fout) = 0;

    virtual void unpackFile(fstream &fin, fstream &fout) = 0;
};

class Shannon : public Algorithm {
public:
    /**
     * Запаковывает по алгоритму Шеннона-Фано.
     * @param fin Поток ввода.
     * @param fout Поток вывода.
     * @attention Не проверяет на существование файла.
     */
    void packFile(fstream &fin, fstream &fout) override;

    /**
     * Распаковывает по алгоритму Шеннона-Фано.
     * @param fin Поток ввода.
     * @param fout Поток вывода.
     * @attention Не проверяет на существование файла.
     */
    void unpackFile(fstream &fin, fstream &fout) override;
};

class Lempel : public Algorithm {
public:
    /**
     * Запаковывает по алгоритму Лемпеля-Зива LZ77.
     * @param fin Поток ввода.
     * @param fout Поток вывода.
     * @attention Не проверяет на существование файла.
     */
    void packFile(fstream &fin, fstream &fout) override;

    /**
     * Распаковывает по алгоритму Лемпеля-Зива LZ77.
     * @param fin Поток ввода.
     * @param fout Поток вывода.
     * @attention Не проверяет на существование файла.
     */
    void unpackFile(fstream &fin, fstream &fout) override;
};


#endif //KDZ_ALGORITHM_H
