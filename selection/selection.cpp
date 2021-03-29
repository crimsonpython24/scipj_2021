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

	if (multi == 1)
		cout << "\n>>> running..." << endl;
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
	unsigned int i, j;
	int min;
    for (i = 0; i < vec.size()-1; ++i) {
        min = i;
        for (j = i+1; j < vec.size(); j++)
            if (vec[j] < vec[min])
                min = j;
  
        int temp = *(&vec[min]);
        *(&vec[min]) = *(&vec[i]);
        *(&vec[i]) = temp;
    }
	auto end = high_resolution_clock::now(); // end

	auto dur = duration_cast<microseconds>(end-start);
	
	wrf.writeresult(out_dirc, vec);
	if (multi != 1)
		cout << ">>> TIME TAKEN " << dur.count() << "ms USING selection (reg) [" << cnt << "]" << endl;
	else
		cout << ">>> TIME TAKEN " << dur.count() << "ms USING insertion (reg)" << endl;
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T physMemUsedByMe = pmc.WorkingSetSize;

	map<string, long> m1 = {{"mem", physMemUsedByMe}, {"time", dur.count() }, {"items", vec.size()}};

	return m1;
}


// FOR TESTING ONLY

// int main() {
//     Selection slc;
// 	slc.selection("");
// 	return 0;
// }
