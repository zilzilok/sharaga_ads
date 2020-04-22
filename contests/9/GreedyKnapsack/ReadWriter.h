#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

bool comp(std::pair<int, int>& left, std::pair<int, int>& right)
{
    if (left.first != right.first)
        return left.first > right.first;
    return left.second > right.second;

}
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
    void readArr(std::pair<int, int>* arr, int n)
    {
        if (!fin.is_open())
            throw std::ios_base::failure("file not open");

        std::string s;
        //weight
        for (int i = 0; i < n; i++)
            fin >> arr[i].first;
        std::getline(fin, s); //read empty line
        //cost
        for (int i = 0; i < n; i++)
            fin >> arr[i].second;
    }

    //write vector<pair<int, int>> results
    void writeVector(std::vector<std::pair<int, int>>& res)
    {
        if (!fout.is_open())
            throw std::ios_base::failure("file not open");
        //sort vector to have the same answer
        std::sort(res.begin(), res.end(), comp);
        //write weight
        for (int i = 0; i < res.size(); i++)
            fout << res[i].first << " ";
        fout << "\n";
        //write cost
        for (int i = 0; i < res.size(); i++)
            fout << res[i].second << " ";
    }

    void writeInt(int a)
    {
        if (!fout.is_open())
            throw std::ios_base::failure("file not open");

        fout << a << "\n";
    }
};