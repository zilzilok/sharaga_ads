// КДЗ по дисциплине Алгоритмы и структуры данных, 2019-2020 уч.год
// Сафин Тагир Наилевич, группа БПИ-181, дата (7.04.2020)
// Clion 2019.3.5
// Состав проекта (файлы *.cpp и *.h)
// Что сделано:
// 1. сжатие и распаковка методом Шеннона - Фано;
// 2. проведен вычислительный эксперимент;
// 3. построены таблицы и графики;
// 4. для измерения времени выполнения использовалось std::chrono::high_resolution_clock;
// 5. оформлен отчет;
// Что не сделано:
// 1. сжатие и распаковка методом LZ77;
// 2. сжатие и распаковка методом LZW;
#include <chrono>
#include <map>
#include <vector>
#include <cmath>
#include "FileArchiver.h"

void pack(string &filename, FileArchiver &fileArchiver, fstream &fout, int count) {
    fout << filename << ";packing;";
    long long sum = 0;
    for (int i = 0; i < count; ++i) {
        auto begin = std::chrono::high_resolution_clock::now();
        fileArchiver.packFile();
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        fout << elapsed_ms.count() << ";";
        sum += elapsed_ms.count() / count;
    }
    fout << sum << ";";
}

void unpack(string &filename, FileArchiver &fileArchiver, fstream &fout, int count) {
    fout << filename << ";unpacking;";
    int sum = 0;
    for (int i = 0; i < count; ++i) {
        auto begin = std::chrono::high_resolution_clock::now();
        fileArchiver.unpackFile();
        auto end = std::chrono::high_resolution_clock::now();
        auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
        fout << elapsed_ms.count() << ";";
        sum += elapsed_ms.count();
    }
    fout << (double) sum / count << ";";
}

int getFileSize(string &fn) {
    fstream file(fn);
    file.seekg(0, std::ios::end);
    int size = file.tellg();
    file.close();
    return size;
}

void shannonFanoExperiment(vector<string> &files, int count) {
    fstream fout;
    fout.open("../../data/shan_res.csv", ios::out);
    fout << "File name; Type;";
    for (int j = 0; j < count; ++j)
        fout << "Time " << j + 1 << " (ns);";
    fout << "Average time;File size (bytes); Packed file size (bytes); coefficient\n";

    cout << "Shannon-Fano:\n";
    for (int i = 0; i < files.size(); ++i) {
        string add = to_string((i + 1)) + "/" + files[i];
        string file = "../../data/" + add;
        string packedFile = "../../data/" + add + ".shan";
        string unpackedFile = "../../data/" + add + ".unshan";
        FileArchiver fileArchiver(file, packedFile, unpackedFile);
        pack(files[i], fileArchiver, fout, count);
        int size = getFileSize(file);
        int packedSize = getFileSize(packedFile);
        fout << size << ";" << packedSize << ";" << (double) packedSize / size << "\n";
        unpack(files[i], fileArchiver, fout, count);
        fout << "-;-;-\n";
        cout << i + 1 << "/" << files.size() << " completed.\n";
    }
    fout.close();
}

#define BYTES 1024

void lz77Experiment(vector<string> &files, int dictLen, int lookheadLen, int count) {
    fstream fout;
    int winLen = dictLen + lookheadLen;
    fout.open("../../data/lz77" + to_string(winLen) + "_res.csv", ios::out);
    fout << "File name; Type;";
    for (int j = 0; j < count; ++j)
        fout << "Time " << j + 1 << " (ns);";
    fout << "Average time;File size (bytes); Packed file size (bytes); coefficient\n";

    cout << "LZ77 with " << winLen << " KB window size:\n";
    for (int i = 0; i < files.size(); ++i) {
        string add = to_string((i + 1)) + "/" + files[i];
        string file = "../../data/" + add;
        string packedFile = "../../data/" + add + ".lz77" + to_string(winLen);
        string unpackedFile = "../../data/" + add + ".unlz77" + to_string(winLen);
        FileArchiver fileArchiver(file, packedFile, unpackedFile,
                                  new Lempel(dictLen * BYTES, lookheadLen * BYTES));
        pack(files[i], fileArchiver, fout, count);
        int size = getFileSize(file);
        int packedSize = getFileSize(packedFile);
        fout << size << ";" << packedSize << ";" << (double) packedSize / size << "\n";
        unpack(files[i], fileArchiver, fout, count);
        fout << "-;-;-\n";
        cout << i + 1 << "/" << files.size() << " completed.\n";
    }
    fout.close();
}

map<unsigned char, int> getFrequency(string &file, long &count) {
    fstream fin;
    fin.open(file, ios::in | ios::binary);
    map<unsigned char, int> dict;
    if (fin.is_open()) {
        unsigned char tmp;
        string input;
        while (fin >> noskipws >> tmp) {
            count++;
            dict[tmp]++;
        }
        fin.close();
    }
    return dict;
}

void checkFilesFrequency(vector<string> &files) {
    fstream fout;
    fout.open("../../data/files_char_frequency.csv", ios::out);
    fout << "File name;";
    vector<map<unsigned char, int>> filesFreq;
    vector<long> counts;
    for (int i = 0; i < files.size(); ++i) {
        fout << files[i] << ";";
        string add = to_string((i + 1)) + "/" + files[i];
        string file = "../../data/" + add;
        long count = 0;
        map<unsigned char, int> dict = getFrequency(file, count);
        counts.push_back(count);
        filesFreq.push_back(dict);
    }
    fout << "\nSymbol\n";
    vector<double> entropy(files.size());
    for (int i = 0; i < 256; ++i) {
        fout << i << ";";
        for (int j = 0; j < filesFreq.size(); ++j) {
            double fileFreq = (double) filesFreq[j][i] / counts[j];
            fout << fileFreq << ";";
            if (fileFreq != 0)
                entropy[j] += fileFreq * log2(fileFreq);
        }
        fout << "\n";
    }
    fout << "Entropy;";
    for (double i : entropy) {
        fout << -i << ";";
    }
    fout << "\n";
    cout << "Counting the symbol frequency of files is complete.\n";
    fout.close();
}

int main() {
    vector<string> files{"1.docx", "2.pptx", "3.pdf", "4.txt", "5.exe",
                         "6.jpg", "7.bmp", "8.jpg", "9.bmp"};

    shannonFanoExperiment(files, 10);
//    lz77Experiment(files, 4, 1, 10);
//    lz77Experiment(files, 8, 2, 10);
//    lz77Experiment(files, 16, 4, 10);
//    checkFilesFrequency(files);
    return 0;
}
