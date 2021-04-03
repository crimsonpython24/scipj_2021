#pragma once

#ifndef quick_h
#define quick_h

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Quick {
    public:
        map<string, long> quick(string, string, int, int);
        map<string, long> quick_recur(string, string, int, int);
        map<string, long> quick_modular(string, string, int, int);
};

#endif 