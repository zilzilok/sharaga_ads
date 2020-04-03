#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
        //empty line read
        std::string s;
        std::getline(fin, s);
        return n;
    }

    //read data in arr, arr should be initialized before this method
    void readArr(int* arr, int n)
    {
        if (!fin.is_open())
            throw std::ios_base::failure("file not open");

        for (int i = 0; i < n; i++)
            fin >> arr[i];
    }

    //write vector<int> results
    void writeVector(std::vector<int>& res)
    {
        if (!fout.is_open())
            throw std::ios_base::failure("file not open");

        for (int i = 0; i < res.size(); i++)
            fout << res.at(i) << " ";
    }

    void writeInt(int a)
    {
        if (!fout.is_open())
            throw std::ios_base::failure("file not open");

        fout << a << "\n";
    }
};