#include <iostream>
#include <fstream>
#include <random>
#include <string>
#include <stdlib.h>
#include "writefile.h"
using namespace std;

#define prl cout<<endl

void Writefile::write(string filename) {
	int mode, cnt;
	string temp;
	cout << ">>> Choose 1 for linear, 2 for random (q/quit to quit): "; cin >> temp;

	if (temp.compare("quit") == 0|| temp.compare("q") == 0) {
		exit(0);
		cout << "------ EXIT writefile ------\n" << endl;
	}
	else
		mode = stoi(temp);

	cout << ">>> Input number of numbers: "; cin >> cnt;

	ofstream file;
	file.open(filename);

	if (mode == 1) {
		for (int i = 0; i < cnt; ++i)
			file << i << " ";
	} else if (mode == 2) {
		int lo, hi;
		cout << ">>> Input lower and upper bound, separate with \'enter\': ";
		cin >> lo >> hi;
		random_device rand;

		for (int i = 0; i < cnt; ++i) {
			mt19937 rng(rand());
			uniform_int_distribution<mt19937::result_type> dist6(lo, hi);
			file << dist6(rng) << " ";
		}
	}
	file.close();
	return;
}

string Writefile::writefile() {
	string filename;
	cout << ">>> Input file name: "; cin >> filename;
	write(filename);
	return filename;
}

void Writefile::writefiledefaultdir(string filename) {
	write(filename);
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
// 	wrf.writefile();
// 	return 0;
// }	
