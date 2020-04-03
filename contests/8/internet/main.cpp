#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

const int N = 31;

int countMinSum(int seconds, vector<int>& values)
{
//	int** A = new int*[N];
//    for (int i = 0; i < N; ++i)
//        A[i] = new int[seconds];
    for (int i = 1; i < N; ++i) {
        if(values[i - 1] * 2 > values[i])
            values[i] = values[i - 1] * 2;
    }

    int res = 0;
    for (int i = N - 1; i >= 0; --i) {
        if(seconds >= values[i]){
            seconds -= values[i];
            res += 1 << i;
        }
    }
    if(seconds > 0) res++;

    return res;
}

 class kek{

};


int main()
{
	vector<int> values;
	int value = 0, seconds = 0;
	
	ifstream fin;
	fin.open("input.txt");
	if (fin.is_open())
	{
		fin >> seconds;
		for (int i = 0; i < N; i++)
		{
			fin>>value;
			values.push_back(value);
		}
		fin.close();
	}
	
	int res = countMinSum(seconds, values);
	
	fstream fout;
	fout.open("output.txt", ios::out);
	fout << res;
	fout.close();
	
	return 0;
}
