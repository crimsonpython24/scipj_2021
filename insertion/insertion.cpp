#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "insertion.h"
using namespace std;
using namespace std::chrono;

void Insertion::insertion() {
	string fn;
	cout << "Input file name: "; cin >> fn; cout << endl;
	ifstream infile(fn);
	string line;
	vector<int> ints;

	while (getline(infile, line)) {
		istringstream iss(line);
		for (string k; iss >> k; )
			ints.push_back(stoi(k));
	}

	int nums[ints.size()];
	copy(ints.begin(), ints.end(), nums);
	int n = sizeof(nums)/sizeof(nums[0]);

	auto start = high_resolution_clock::now(); // start

	// main sorting algo
	int i, key, j;
	for (i = 1; i < n; ++i) {
		key = nums[i];
		j = i - 1;
		while (j >= 0 && nums[j] > key) {
			nums[j + 1] = nums[j];
			--j;
		}
		nums[j + 1] = key;
	}

	auto end = high_resolution_clock::now(); // end

	for (int m = 0; m < n; ++m)
		cout << nums[m] << " "; // debug
	cout << endl;

	auto dur = duration_cast<microseconds>(end-start);
	cout << "time taken " << dur.count() << "ms" << endl;
}

int main() {
	Insertion ins;
	ins.insertion();
	return 0;
}