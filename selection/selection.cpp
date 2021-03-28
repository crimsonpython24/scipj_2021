#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "selection.h"
#include "../main/readfile.h"
#include "../main/writefile.h"
using namespace std;
using namespace std::chrono;

void Selection::selection(string dirc, string out_dirc, int multi, int cnt) {
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

	wrf.writeresult(out_dirc, nums, n);
	auto dur = duration_cast<microseconds>(end-start);
	if (multi != 1)
		cout << ">>> TIME TAKEN " << dur.count() << "ms USING selection (reg) [" << cnt+1 << "]\n" << endl;
	else
		cout << ">>> TIME TAKEN " << dur.count() << "ms USING insertion (reg)\n" << endl;
}


// FOR TESTING ONLY

// int main() {
//     Selection slc;
// 	slc.selection("");
// 	return 0;
// }
