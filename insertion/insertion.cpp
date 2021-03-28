#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "insertion.h"
#include "../main/readfile.h"
using namespace std;
using namespace std::chrono;

void Insertion::insertion(string dirc) {
	Readfile rdf;
    vector<int> vec = rdf.readfile(dirc);
    
	int nums[vec.size()];
	copy(vec.begin(), vec.end(), nums);
	int n = sizeof(nums)/sizeof(nums[0]);

	auto start = high_resolution_clock::now(); // start

	// main sorting algo
	cout << "\n>>> running..." << endl;
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

	// for (int m = 0; m < n; ++m)
	// 	cout << nums[m] << " "; // debug
	// cout << endl;

	auto dur = duration_cast<microseconds>(end-start);
	cout << ">>> TIME TAKEN " << dur.count() << "ms USING insertion (reg)\n" << endl;
}


// FOR TESTING ONLY

// int main() {
// 	Insertion ins;
// 	ins.insertion("");
// 	return 0;
// }
