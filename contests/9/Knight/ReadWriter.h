#include <iostream>
#include <fstream>
#include <string>

class ReadWriter
{
private:

    std::fstream fin;
    std::fstream fout;

public:

    ~ReadWriter()
    {
        fin.close();
        fout.close();
    }

    ReadWriter()
    {
        fin.open("input.txt", std::ios::in);
        fout.open("output.txt", std::ios::out);
    }

    // read 1 int value and empty line
    int readInt()
    {
        if (!fin.is_open())
            throw std::ios_base::failure("file not open");

        int n;
        fin >> n;
        return n;
    }

    void writeLongLong(long long a)
    {
        if (!fout.is_open())
            throw std::ios_base::failure("file not open");

        fout << a;
    }
};