#pragma once

#ifndef utils_h
#define utils_h

#include <bits/stdc++.h>
#include "../insertion/insertion.h"
#include "../selection/selection.h"
#include "../merge/merge.h"
#include "../quick/quick.h"
#include "../bubble/bubble.h"
using namespace std;


class Utils {
    public:
        map<string, long> choose_algo(string, string, int, int, int, Insertion&, Selection&, Merge&, Quick&, Bubble&);
        bool check_yes(string);
        bool in_array(string&, vector<string>&);
        string map_to_string(map<string, long>);
        void json_parse_child(int, ofstream&, map<string, long>);
        pair<int, int> find_pair_avg(vector<pair<int, int>>);
        void write_file_end(int, ofstream&, pair<int, int>, Utils&, vector<pair<int, int>>, vector<int>);
};

#endif 