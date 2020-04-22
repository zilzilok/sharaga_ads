#include <fstream>
#include <map>
#include "FileArchiver.h"

void FileArchiver::packFile() {
    fstream fin;
    fin.open(file, ios::in | ios::binary);
    if (fin.is_open()) {
        fstream fout;
        fout.open(packedFile, ios::out | ios::binary);
        algorithmType->packFile(fin, fout);
        fin.close();
        fout.close();
    }
}

void FileArchiver::unpackFile() {
    fstream fin;
    fin.open(packedFile, ios::in | ios::binary);
    if (fin.is_open()) {
        fstream fout;
        fout.open(unpackedFile, ios::out | ios::binary);
        algorithmType->unpackFile(fin, fout);
        fin.close();
        fout.close();
    }
}

