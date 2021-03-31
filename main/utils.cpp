#include <bits/stdc++.h>
#include "utils.h"
#include "../insertion/insertion.h"
#include "../selection/selection.h"
#include "readfile.h"
using namespace std;


template<typename T> T variance(const vector<T> &vec) {
    const size_t sz = vec.size();
    if (sz == 1)
        return 0.0;

    // Calculate the mean
    const T mean = accumulate(vec.begin(), vec.end(), 0.0) / sz;

    // Now calculate the variance
    auto variance_func = [&mean, &sz](T accumulator, const T& val) {
        return accumulator + ((val - mean)*(val - mean) / (sz - 1));
    };

    return accumulate(vec.begin(), vec.end(), 0.0, variance_func);
}

map<string, long> Utils::choose_algo(string in_dir, string algoname, int multi, int cnt, Insertion& ins, Selection& slc) {
	map<string, long> m1;
	string temp3;
	temp3 = (in_dir.compare("") == 0) ? ("..\\txt_files\\temp.txt") : in_dir;

	m1 = ins.insertion(temp3, "..\\txt_files\\out.txt", multi, cnt);
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


pair<int, int> Utils::find_pair_avg(vector<pair<int, int>> vec) {
	pair<int, int> temp(0, 0);
	for (int i = 0; i < vec.size(); ++i) {
		temp.first += vec[i].first;
		temp.second += vec[i].second;
	}
	temp.first = temp.first / vec.size();
	temp.second = temp.second / vec.size();
	return temp;
}

void Utils::write_file_end(int multicnt, ofstream& file, pair<int, int> temp4, Utils& uts, vector<pair<int, int>> nums, vector<int> conf) {
	Readfile rdf;
	vector<int> vec0 = rdf.readfile("..\\txt_files\\temp.txt");
	vector<double> vec(vec0.begin(), vec0.end());
	if (multicnt == 1) {
		file << "\t\t]," << endl;
		file << "\t\t{\"mode\": " + to_string(conf[0]) + ", \"cnt\": " + to_string(conf[1]) + ", \"lo\": "
						+ to_string(conf[2]) + ", \"hi\": " + to_string(conf[3]) + "}";
		file << "\n\t]" << endl; 
		cout << endl;
	} else {
		temp4 = uts.find_pair_avg(nums);
		file << "\t\t]," << endl;
		file << "\t\t{\"mode\": " + to_string(conf[0]) + ", \"cnt\": " + to_string(conf[1]) + ", \"lo\": "
						+ to_string(conf[2]) + ", \"hi\": " + to_string(conf[3]) + "},\n";
		file << "\t\t{\"items\": " + to_string(temp4.first) + ", \"avg time (microseconds)\": "
						+ to_string(temp4.second) + ", \"std dev\": " + to_string(variance(vec)) + "}";
		file << "\n\t]" << endl;
		cout << endl;	
	}
}