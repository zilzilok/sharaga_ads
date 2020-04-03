#include <map>
#include <sstream>
#include "Algorithm.h"

typedef map<char, pair<int, string>> custom_map;

custom_map dict;

custom_map::iterator findMedian(custom_map::iterator left, custom_map::iterator right) {
    if (distance(left, right) >= 2) {
        int lSum1 = (*left).second.first;
        int rSum1 = 0;
        for (auto it = next(left, 1); it != next(right, 1); ++it) {
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

void generate(custom_map::iterator left, custom_map::iterator right) {
    if (left != right) {
        auto med = findMedian(left, right);
        for (auto it = left; it != next(med, 1); ++it) {
            (*it).second.second += "0";
        }
        generate(left, med);

        for (auto it = next(med, 1); it != next(right, 1); ++it) {
            (*it).second.second += "1";
        }
        generate(next(med, 1), right);
    }
}

void Shannon::packFile(fstream &fin, fstream &fout) {
    char tmp;
    string input;
    while (fin.get(tmp))
        input += tmp;
    for (char &ch : input) {
        if (dict.find(ch) == dict.end())
            dict[ch] = make_pair(1, "");
        else
            dict[ch].first++;
    }
    generate(dict.begin(), next(dict.end(), -1));

    fout << dict.size() << "\n";
    for (auto &i : dict) {
        fout << i.first << " " << i.second.second << "\n";
    }
    for (char &ch : input) {
        fout << dict[ch].second;
    }
    dict.clear();
}

void Shannon::unpackFile(fstream &fin, fstream &fout) {
    map<string, char> mdict;
    int n;
    fin >> n;
    char ch;
    string code;
    for (int i = 0; i < n; ++i) {
        fin.get(ch);
        fin.get(ch);
        fin >> code;
        mdict[code] = ch;
    }

    char tmp;
    string input;
    fin.get(tmp);
    while (fin.get(tmp))
        input += tmp;

    code = "";
    for (char &i : input) {
        code += i;
        if (mdict.find(code) != mdict.end()) {
            fout << mdict[code];
            code = "";
        }
    }
    mdict.clear();
}