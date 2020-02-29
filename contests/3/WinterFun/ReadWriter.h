#include <iostream>
#include <fstream>
#include "Student_and_Ski.h"

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

    int readInt()
    {
        if (!fin.is_open())
            throw std::ios_base::failure("file not open");

        int n = 0;
        fin >> n;
        return n;
    }

    //формат: 1 140; 2 156; 3 187; 4 198;
    //This method only fill array. You should create it with operator (new) before call this method.
    void readStudents(Student* arr, int length)
    {
        if (!fin.is_open())
            throw std::ios_base::failure("file not open");

        char ch;
        for (int i = 0; i < length; i++)
        {
            fin >> arr[i].id;
            fin >> arr[i].height;
            fin >> ch; // ;
        }
    }

    //формат: 1 140; 2 156; 3 187; 4 198;
    //This method only fill array. You should create it with (new) operator before call this method.
    void readSkis(Ski* arr, int length)
    {
        if (!fin.is_open())
            throw std::ios_base::failure("file not open");

        char ch;
        for (int i = 0; i < length; i++)
        {
            fin >> arr[i].id;
            fin >> arr[i].length;
            fin >> ch; // ;
        }
    }

    //формат: 1 3; 2 1; 3 56; 4 13;
    void writeStudentsAndSkis(Student* students, Ski* skis, int n)
    {
        if (!fout.is_open())
            throw std::ios_base::failure("file not open");

        for (int i = 0; i < n; i++)
            fout << students[i].id << " " << skis[i].id << ";" << " ";
    }
};
