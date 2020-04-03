#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <map>
#include <iterator>

using namespace std;

typedef map<char, pair<int, string>> custom_map;
typedef custom_map::iterator custom_iterator;

class ShannonFano {
public:
    ~ShannonFano() {}

    ShannonFano(string &input) {
        for (char &ch : input) {
            if (dict.find(ch) == dict.end())
                dict[ch] = make_pair(1, "");
            else
                dict[ch].first++;
        }
    }

    custom_iterator findMedian(custom_iterator left, custom_iterator right) {
        if (distance(left, right) >= 2) {
            int lSum1 = (*left).second.first;
            int rSum1 = 0;
            for (custom_iterator it = next(left, 1); it != next(right, 1); ++it) {
                rSum1 += (it)->second.first;
            }
            int abs1 = abs(lSum1 - rSum1);

            int lSum2 = lSum1, rSum2 = rSum1, abs2, dif = 1;

            while (next(left, dif) != right) {
                int tmp = (*next(left, dif)).second.first;
                lSum2 += tmp;
                rSum2 -= tmp;
                abs2 = abs(lSum2 - rSum2);

                if (abs1 <= abs2)
                    break;

                abs1 = abs2;
                dif++;
            }
            return next(left, dif - 1);
        }
        return left;
    }

    void generate(custom_iterator left, custom_iterator right) {
        if (left != right) {
            custom_iterator med = findMedian(left, right);
            for (custom_iterator it = left; it != next(med, 1); ++it) {
                (*it).second.second += "0";
            }
            generate(left, med);

            for (custom_iterator it = next(med, 1); it != next(right, 1); ++it) {
                (*it).second.second += "1";
            }
            generate(next(med, 1), right);
        }
    }

    void generate() {
        generate(dict.begin(), next(dict.end(), -1));
    }

    void print(fstream &fout) {
        for (auto &it : dict)
            fout << it.first << "\t" << it.second.first << " " << it.second.second << "\n";
    }

private:
    custom_map dict;
};


int main() {
    fstream fin;
    fin.open("input.txt", ios::in);
    if (fin.is_open()) {
        string str;
        getline(fin, str);
        fin.close();

        ShannonFano *shf = new ShannonFano(str);
        shf->generate();

        fstream fout;
        fout.open("output.txt", ios::out);
        shf->print(fout);
        fout.close();
        delete shf;
    }
    return 0;
}