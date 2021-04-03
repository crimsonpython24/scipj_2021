#pragma once

#ifndef merge_h
#define merge_h

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Merge {
    public:
        map<string, long> merge(string, string, int, int);
        map<string, long> merge_modular(string, string, int, int);
        map<string, long> merge_recur(string, string, int, int);
};

#endif 