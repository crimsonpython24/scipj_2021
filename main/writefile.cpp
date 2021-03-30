#include <bits/stdc++.h>
#include "writefile.h"
using namespace std;

#define prl cout<<endl

int generate_random(int lower, int upper) {
	mt19937 rng(rand());
	uniform_int_distribution<mt19937::result_type> dist6(lower, upper);
	return dist6(rng);
}

void Writefile::write(string filename, vector<int> def_choice) {
	int mode, cnt, lo, hi; bool all_zero = true;
	string temp, line; vector<int> vals;
	ofstream file; random_device rand;

	if (def_choice.size() == 0) {
		cout << ">>> Menu: " << endl;
		cout << "      * 1: linear\n      * 2: random\n    \"-1\" to load config and \"q\" to quit\n(input) ";
		cin >> temp;
	}
	else {
		mode = -1; cnt = generate_random(def_choice[0], def_choice[1]); lo = def_choice[2]; hi = def_choice[3];
	}
	if (temp.compare("quit") == 0 || temp.compare("q") == 0) {
		exit(0);
		cout << "------ EXIT writefile ------\n" << endl;
	} else if (def_choice.size() != 0) {        // DO NOT edit the value of temp! will be used for config
		for (int i=0; i<def_choice.size(); ++i) {
			if (def_choice[i] != 0) 
				all_zero = false;
		}
		if (all_zero) {
			ifstream config_file (filename.substr(0, filename.size()-4) + "_config.txt");
			if (config_file.is_open()) {
				while (getline(config_file, line)) {
					istringstream iss(line);
					for (string k; iss >> k; )
						vals.push_back(stoi(k));
				}
			}
			cnt = vals[1]; lo = vals[2]; hi = vals[3];
			config_file.close();
		}
		else
			vals = def_choice;

		file.open(filename);
		for (int i = 0; i < cnt; ++i) {
			mt19937 rng(rand());
			uniform_int_distribution<mt19937::result_type> dist6(lo, hi);
			file << dist6(rng) << " ";
		}
		file.close();
	}
	else {
		mode = stoi(temp);
		cout << ">>> Input number of numbers: "; cin >> cnt;
		file.open(filename);

		if (mode == 1) {
			for (int i = 0; i < cnt; ++i)
				file << i << " ";
		} else if (mode == 2) {
			cout << ">>> Input lower and upper bound, separate with \'enter\': ";
			cin >> lo >> hi;

			for (int i = 0; i < cnt; ++i) {
				mt19937 rng(rand());
				uniform_int_distribution<mt19937::result_type> dist6(lo, hi);
				file << dist6(rng) << " ";
			}
		}
		file.close();
	}
	
	ofstream out((filename.substr(0, filename.size()-4) + "_log.txt"), ios_base::app);
	auto end = chrono::system_clock::now();
    std::time_t end_time = chrono::system_clock::to_time_t(end);
	out << ctime(&end_time) << temp << " " << cnt << " " << lo << " " << hi << endl;
	out.close();

	return;
}

string Writefile::writefile(vector<int> mode) {
	string filename;
	cout << ">>> Input file name: "; cin >> filename;
	write(filename, mode);
	return filename;
}

void Writefile::writefiledefaultdir(string filename, vector<int> mode) {
	write(filename, mode);
	return;
}

void Writefile::writeresult(string filename, vector<int> nums) {
	ofstream file;
	file.open(filename);
	for (unsigned int i = 0; i < nums.size(); ++i)
		file << nums[i] << " ";
	file.close();
	return;
}

void Writefile::write_all_results(string out_dirc, vector<int> vec, int multi, long long int dur, int cnt) {
	Writefile wrf;
	string pr;
	wrf.writeresult(out_dirc, vec);
	pr = (multi != 1) ? ">>> TIME TAKEN " + to_string(dur) + "ms USING insertion (reg) [" + to_string(cnt) + "]" :
	      ">>> TIME TAKEN " + to_string(dur) + "ms USING insertion (reg)";
	cout << pr << endl;
	return;
}

// FOR TESTING ONLY

// int main() {
// 	Writefile wrf;
// 	wrf.write("..\\insertion\\temp.txt");
// 	return 0;
// }	
