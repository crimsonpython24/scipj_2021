#pragma once

#ifndef writefile_h
#define writefile_h

#include <bits/stdc++.h>
#include "writefile.h"
using namespace std;

class Writefile {
    public:
        string writefile(vector<int>);
        void writefiledefaultdir(string, vector<int>);
        void writeresult(string, vector<int>);
        void write_all_results(string, vector<int>, int, long long int, int);
        void write(string, vector<int>);
};

#endif 