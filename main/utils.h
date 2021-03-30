#pragma once

#ifndef utils_h
#define utils_h

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdio.h>
#include <map>
#include "../insertion/insertion.h"
#include "../selection/selection.h"
using namespace std;


class Utils {
    public:
        map<string, long> choose_algo(string, string, int, int, Insertion&, Selection&);
        bool check_yes(string);
        bool in_array(string&, vector<string>&);
        string map_to_string(map<string, long>);
        void json_parse_child(int, ofstream&, map<string, long>);
        pair<int, int> find_pair_avg(vector<pair<int, int>>);
};

#endif 