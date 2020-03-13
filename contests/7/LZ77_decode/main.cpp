
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

using namespace std;

class Code{
public:
    Code(int _offset, int _length, char _next){
        offset = _offset;
        length = _length;
        next = _next;
    }

    int offset;
    int length;
    char next;
};

string decode(const vector<Code*>& codes){
    string res;
    for(auto& code : codes){
        if(code->length != 0){
            int start_i = res.length() - code->offset;
            for (int i = 0; i < code->length; ++i) {
                res += res[start_i + i % code->length];
            }
        }
        res += code->next;
    }
    return res;
}

int main() {

    int n;
    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open()) {
        fin >> n;
        int offset, length;
        char next;
        vector<Code*> codes(n);
        for (int i = 0; i < n; ++i) {
            fin >> offset;
            fin >> length;
            fin >> next;
            codes[i] = new Code(offset, length, next);
        }
        fin.close();

        fstream fout;
        fout.open("output.txt", ios::out);
        fout << decode(codes) << endl;
        fout.close();

        for (int j = 0; j < n; ++j) {
            delete codes[j];
        }
    }
    return 0;

}

