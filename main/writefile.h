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
        void writefile();
        void writefiledefaultdir(string);
        void writeresult(string, int*, int);
    private:
        void write(string);
};

#endif 