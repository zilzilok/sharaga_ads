#include <fstream>
#include "FileArchiver.h"

void FileArchiver::packFile() {
    fstream fin;
    fstream fout;
    fin.open(fileNameIn, ios::in | ios::binary);
    fout.open(fileNameOut, ios::out | ios::binary);
    if (fin.is_open()) {
        algorithmType->packFile(fin, fout);
        fin.close();
        fout.close();
    }
}

void FileArchiver::unpackFile() {
    fstream fin;
    fstream fout;
    fin.open(fileNameOut, ios::in | ios::binary);
    fout.open(fileNameIn, ios::out | ios::binary);
    if (fin.is_open()) {
        algorithmType->unpackFile(fin, fout);
        fin.close();
        fout.close();
    }
}

