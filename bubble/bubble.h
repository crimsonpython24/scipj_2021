#pragma once

#ifndef bubble_h
#define bubble_h

#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

class Bubble {
    public:
        map<string, long> bubble(string, string, int, int);
        map<string, long> bubble_recur(string, string, int, int);
        map<string, long> bubble_modular(string, string, int, int);
};

#endif 