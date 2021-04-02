#pragma once

#ifndef selection_h
#define selection_h

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Selection {
    public:
        map<string, long> selection(string, string, int, int);
        map<string, long> selection_recur(string, string, int, int);
        map<string, long> selection_modular(string, string, int, int);
};

#endif 