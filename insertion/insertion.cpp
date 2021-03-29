#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "windows.h"
#include "psapi.h"
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

	if (multi == 1)
		cout << "\n>>> running..." << endl;
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
	unsigned int i, j;
	int key;
	for (i = 1; i < vec.size(); ++i) {
		key = vec[i];
		j = i - 1;
		while (j >= 0 && vec[j] > key) {
			vec[j + 1] = vec[j];
			--j;
		}
		vec[j + 1] = key;
	}

	auto end = high_resolution_clock::now(); // end

	auto dur = duration_cast<microseconds>(end-start);
	
	wrf.writeresult(out_dirc, vec);
	if (multi != 1)
		cout << ">>> TIME TAKEN " << dur.count() << "ms USING insertion (reg) [" << cnt << "]" << endl;
	else
		cout << ">>> TIME TAKEN " << dur.count() << "ms USING insertion (reg)" << endl;	

	PROCESS_MEMORY_COUNTERS_EX pmc;
	SIZE_T physMemUsedByMe = pmc.WorkingSetSize;

	map<string, long> m1 = {{"mem", physMemUsedByMe}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}


// FOR TESTING ONLY

// int main() {
// 	Insertion ins;
// 	ins.insertion("");
// 	return 0;
// }
