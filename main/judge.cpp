#include <bits/stdc++.h>
#include "readfile.h"
#include "judge.h"
using namespace std;

bool Judge::judge(string filein, string fileout) {
    Readfile rdf;
    vector<int> v1, v2;
    v1 = rdf.readfile(filein);
    v2 = rdf.readfile(fileout);
    sort(v1.begin(), v1.end());

    for (unsigned int i = 0; i < v2.size(); ++i) {
        if (v2[i] != v1[i])
            return false;
    }
    return true;
}

// int main() {
//     Judge jdg;
//     cout << jdg.judge("..\\insertion\\temp.txt", "..\\insertion\\out.txt") << endl;
//     return 0;
// }