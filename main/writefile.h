#pragma once

#ifndef writefile_h
#define writefile_h

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include "writefile.h"
using namespace std;

class Writefile {
    public:
        string writefile();
        void writefiledefaultdir(string);
        void writeresult(string, vector<int>);
        void write_all_results(string, vector<int>, int, long long int, int);
    private:
        void write(string);
};

#endif 