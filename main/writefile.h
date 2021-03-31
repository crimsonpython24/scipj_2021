#pragma once

#ifndef writefile_h
#define writefile_h

#include <bits/stdc++.h>
#include "writefile.h"
using namespace std;

class Writefile {
    public:
        vector<int> write(string, vector<int>);
        pair<string, vector<int>> writefile(vector<int>);
        vector<int> writefiledefaultdir(string, vector<int>);
        void writeresult(string, vector<int>);
        void write_all_results(string, vector<int>, int, long long int, int);
};

#endif 