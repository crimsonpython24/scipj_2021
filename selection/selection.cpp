#include <bits/stdc++.h>
#include "windows.h"
#include "psapi.h"
#include "selection.h"
#include "../main/readfile.h"
#include "../main/writefile.h"
#include "../main/judge.h"
using namespace std;
using namespace std::chrono;

int find_min(vector<int> vec, int i, int j) {
    if (i == j)
        return i;
  
    // Find min of the remaining nums
    int k = find_min(vec, i + 1, j);
  
    // Return the absolute min
    return (vec[i] < vec[k]) ? i : k;
}

unsigned sel_recur(vector<int>& arr, int n, int idx, unsigned int a) {
	// Base case
    if (idx == n)
       return a;
  
    // Find the min
	int k = find_min(arr, idx, n-1);
	
    // Swapping if two index are not same (not min)
    if (k != idx)	
       swap(arr[k], arr[idx]);
  
    // Recursive call
    sel_recur(arr, n, idx + 1, a);
}

unsigned int tail_recur(vector<int>& arr, unsigned int n) {
	return sel_recur(arr, n, 0, 1);
}

map<string, long> Selection::selection(string dirc, string out_dirc, int multi, int cnt) {
	Readfile rdf;
	Writefile wrf;
    vector<int> vec = rdf.readfile(dirc);

	if (multi == 1)
		cout << "\n>>> running..." << endl;
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
	int i, j;
	int min;
    for (i = 0; i < vec.size()-1; ++i) {
        min = i;
        for (j = i+1; j < vec.size(); j++)
            if (vec[j] < vec[min])
                min = j;
  
		swap(vec[min], vec[i]);
    }
	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "insertion (recur)");

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}


map<string, long> Selection::selection_recur(string dirc, string out_dirc, int multi, int cnt) {
	Readfile rdf;
	Writefile wrf;
    vector<int> vec = rdf.readfile(dirc);

	if (multi == 1)
		cout << "\n>>> running..." << endl;
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
	tail_recur(vec, vec.size());

	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "insertion (recur)");

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

map<string, long> Selection::selection_modular(string dirc, string out_dirc, int multi, int cnt) {
	Readfile rdf;
	Writefile wrf;
    vector<int> vec = rdf.readfile(dirc);

	if (multi == 1)
		cout << "\n>>> running..." << endl;
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
	int i, j;
	int min;
    for (i = 0; i < vec.size()-1; ++i) {
        min = i;
        for (j = i+1; j < vec.size(); j++)
            if (vec[j] < vec[min])
                min = j;
  
		swap(vec[min], vec[i]);
    }
	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "insertion (recur)");

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

// FOR TESTING ONLY

// int main() {
//     Selection slc;
// 	Judge jdg;
// 	slc.selection("temp.txt", "out.txt", 1, 0); // localized test files
// 	cout << jdg.judge("temp.txt", "out.txt") << endl;
// 	slc.selection_recur("temp_short.txt", "out.txt", 1, 0);
// 	cout << jdg.judge("temp_short.txt", "out.txt") << endl;
// 	// slc.selection_modular("temp.txt", "out.txt", 1, 0);
// 	// cout << jdg.judge("temp.txt", "out.txt") << endl;
// 	return 0;
// }
