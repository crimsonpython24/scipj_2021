#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdio.h>
#include <map>
#include "utils.h"
#include "../insertion/insertion.h"
#include "../selection/selection.h"
using namespace std;

map<string, long> Utils::choose_algo(string in_dir, string algoname, int multi, int cnt, Insertion& ins, Selection& slc) {
	map<string, long> m1;
	string temp3;
	temp3 = (in_dir.compare("") == 0) ? ("..\\" + algoname + "\\temp.txt") : in_dir;

	if (algoname.compare("insertion") == 0)
		m1 = ins.insertion(temp3, "..\\insertion\\out.txt", multi, cnt);
	else if (algoname.compare("selection") == 0)
		m1 = slc.selection(temp3, "..\\selection\\out.txt", multi, cnt);
	return m1;
}

bool Utils::check_yes(string str) {
	transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return std::tolower(c);});
	return (str.compare("y") == 0 || str.compare("yes") == 0);
}

bool Utils::in_array(string &value, vector<string> &array) {
    return std::find(array.begin(), array.end(), value) != array.end();
}

string Utils::map_to_string(map<string, long> m1) {
	string output = "",  result = "";
	for (auto it = m1.cbegin(); it != m1.cend(); ++it) 
		output += "\"" + (it->first) + "\":" + (to_string(it->second)) + ", ";
	result = output.substr(0, output.size() - 2 );
    return result;
}

void Utils::json_parse_child(int k, ofstream& file, map<string, long> m1) {
	string temp3;
	temp3 = (k != true) ? "\t\t\t,{" + map_to_string(m1) + "}" : "\t\t\t{" + map_to_string(m1) + "}";
	file << temp3 << endl;
	return;
}
