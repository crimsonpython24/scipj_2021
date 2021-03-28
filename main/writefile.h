#pragma once

#ifndef writefile_h
#define writefile_h

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "writefile.h"
using namespace std;

class Writefile {
    public:
        void writefile();
        void writefiledftdir(string);
    private:
        void write(string);
};

#endif 