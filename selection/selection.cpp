#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include "windows.h"
#include "psapi.h"
#include "selection.h"
#include "../main/readfile.h"
#include "../main/writefile.h"
using namespace std;
using namespace std::chrono;

map<string, long> Selection::selection(string dirc, string out_dirc, int multi, int cnt) {
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

	auto dur = duration_cast<microseconds>(end-start);
	
	wrf.writeresult(out_dirc, nums, n);
	if (multi != 1)
		cout << ">>> TIME TAKEN " << dur.count() << "ms USING selection (reg) [" << cnt << "]" << endl;
	else
		cout << ">>> TIME TAKEN " << dur.count() << "ms USING insertion (reg)" << endl;
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T physMemUsedByMe = pmc.WorkingSetSize;

	map<string, long> m1 = {{"mem", physMemUsedByMe}, {"time", dur.count() }, {"items", n}};

	return m1;
}


// FOR TESTING ONLY

// int main() {
//     Selection slc;
// 	slc.selection("");
// 	return 0;
// }
