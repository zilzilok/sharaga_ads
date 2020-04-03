#include "FileArchiver.h"

int main() {
    string input = "../../data/abc.txt";
    string output = "../../data/abc.shan";
    FileArchiver fileArchiver(input, output);
    fileArchiver.packFile();
}
