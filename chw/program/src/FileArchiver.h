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

    FileArchiver(string &f, string &pf, string &unf, Algorithm *a = new Shannon) :
            file(f),
            packedFile(pf),
            unpackedFile(unf),
            algorithmType(a) {}

    /**
     * Запаковывает переданный файл.
     */
    void packFile();

    /**
     * Распаковывает переданный файл.
     */
    void unpackFile();

    Algorithm *getAlgoType() {
        return algorithmType;
    }

private:
    string file;                 // путь к изначальному файлу
    string packedFile;           // путь к запакованному файлу
    string unpackedFile;         // путь к распакованному файлу
    Algorithm *algorithmType;    // тип алгоритма сжатия
};

#endif //KDZ_FILEARCHIVER_H
