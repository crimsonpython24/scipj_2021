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
	cout << "\n>>> running..." << endl;
	int i, j, min;
    for (i = 0; i < n-1; ++i) {
        min = i;
        for (j = i+1; j < n; j++)
            if (nums[j] < nums[min])
                min = j;
  
        int temp = *(&nums[min]);
        *(&nums[min]) = *(&nums[i]);
        *(&nums[i]) = temp;
    }
	auto end = high_resolution_clock::now(); // end

	auto dur = duration_cast<microseconds>(end-start);
	cout << ">>> TIME TAKEN " << dur.count() << "ms USING selection (reg)\n" << endl;
}


// FOR TESTING ONLY

// int main() {
//     Selection slc;
// 	slc.selection("");
// 	return 0;
// }
