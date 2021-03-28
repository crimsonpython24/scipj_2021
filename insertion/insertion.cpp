#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <map>
#include "insertion.h"
#include "../main/readfile.h"
#include "../main/writefile.h"
using namespace std;
using namespace std::chrono;

map<string, long>  Insertion::insertion(string dirc, string out_dirc, int multi, int cnt) {
	Readfile rdf;
	Writefile wrf;
    vector<int> vec = rdf.readfile(dirc);
    
	int nums[vec.size()];
	copy(vec.begin(), vec.end(), nums);
	int n = sizeof(nums)/sizeof(nums[0]);

	if (multi == 1)
		cout << "\n>>> running..." << endl;
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

	// for (int m = 0; m < n; ++m)
	// 	cout << nums[m] << " "; // debug
	// cout << endl;

	auto dur = duration_cast<microseconds>(end-start);
	
	wrf.writeresult(out_dirc, nums, n);
	if (multi != 1)
		cout << ">>> TIME TAKEN " << dur.count() << "ms USING selection (reg) [" << cnt << "]" << endl;
	else
		cout << ">>> TIME TAKEN " << dur.count() << "ms USING insertion (reg)" << endl;	

	map<string, long> m1 = {{"mem", 0}, {"time", dur.count() }, {"items", n}};
	return m1;
}


// FOR TESTING ONLY

// int main() {
// 	Insertion ins;
// 	ins.insertion("");
// 	return 0;
// }
