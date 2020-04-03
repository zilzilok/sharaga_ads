#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

int getLCS(string& x, string& y){
    int** l = new int*[x.length() + 1];
    for(int i = 0; i <= x.length(); ++i)
        l[i] = new int[y.length() + 1]{};

    for (int i = 1; i <= x.length(); ++i) {
        for (int j = 1; j <= y.length(); ++j) {
            if(x[i - 1] == y[j - 1])
                l[i][j] = l[i - 1][j - 1] + 1;
            else
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);
        }
    }
    int res = l[x.length()][y.length()];

    for (int i = 0; i <= x.length(); ++i)
        delete[] l[i];
    delete[] l;

    return res;
}

int main()
{
	string x;
	string y;
	int res;

	ifstream fin;
	fin.open("input.txt");
	if (fin.is_open())
	{
		getline(fin, x);
		getline(fin, y);
		fin.close();
	}

	res = getLCS(x, y);

	fstream fout;
	fout.open("output.txt", ios::out);
	fout << res;
	fout.close();

	return 0;
}