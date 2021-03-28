#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "selection.h"
#include "../main/readfile.h"
using namespace std;
using namespace std::chrono;

void Selection::selection(string dirc) {
	Readfile rdf;
    vector<int> vec = rdf.readfile(dirc);
    
	int nums[vec.size()];
	copy(vec.begin(), vec.end(), nums);
	int n = sizeof(nums)/sizeof(nums[0]);

	auto start = high_resolution_clock::now(); // start

	// main sorting algo
	cout << ">>> running..." << endl;
	int i, j, min_idx;
    for (i = 0; i < n-1; ++i) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (nums[j] < nums[min_idx])
                min_idx = j;
  
        int temp = *(&nums[min_idx]);
        *(&nums[min_idx]) = *(&nums[i]);
        *(&nums[i]) = temp;
    }
	auto end = high_resolution_clock::now(); // end

	auto dur = duration_cast<microseconds>(end-start);
	cout << ">>> TIME TAKEN " << dur.count() << "ms USING selection (reg)" << endl;
}


// FOR TESTING ONLY

int main() {
    Selection sec;
	sec.selection("");
	return 0;
}
