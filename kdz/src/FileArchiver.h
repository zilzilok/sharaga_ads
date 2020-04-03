#ifndef KDZ_FILEARCHIVER_H
#define KDZ_FILEARCHIVER_H

#include <string>
#include <utility>
#include "Algorithm.h"

class FileArchiver {
public:
    ~FileArchiver() {
        delete algorithmType;
    }

    FileArchiver(string& fin, string &fout, Algorithm *a = new Shannon) :
            fileNameIn(fin),
            fileNameOut(fout),
            algorithmType(a) {}

    /**
     * Запаковывает переданный файл.
     */
    void packFile();

    /**
     * Распаковывает переданный файл.
     */
    void unpackFile();

private:
    string fileNameIn;            // путь к файлу
    string fileNameOut;           // путь к файлу
    Algorithm *algorithmType;     // тип алгоритма сжатия
};

#endif //KDZ_FILEARCHIVER_H
