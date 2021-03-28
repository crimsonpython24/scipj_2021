#pragma once

#ifndef selection_h
#define selection_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <string>
#include <map>
using namespace std;
using namespace std::chrono;

class Selection {
    public:
        map<string, long> selection(string, string, int, int);
};

#endif 