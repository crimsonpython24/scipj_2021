#include <bits/stdc++.h>
#include "windows.h"
#include "psapi.h"
#include "insertion.h"
#include "../main/readfile.h"
#include "../main/writefile.h"
#include "../main/judge.h"
using namespace std;
using namespace std::chrono;

#define prep(multi) Readfile rdf; Writefile wrf; if (multi == 1) cout << "\n>>> running..." << endl

unsigned ins_recur(vector<int>& arr, int n, unsigned int a) {
	// base case
	if (n <= 1)
		return a;

	// sort all except for the last element
	ins_recur(arr, n-1, n*a);

	// insert last element at its correct position in array
	int last = arr[n - 1];
	int k = n - 2;

	// move elements to one position ahead of its current (if satisfy)
	while (k >= 0 && arr[k] > last) {
		arr[k + 1] = arr[k];
		--k;
	}
	arr[k + 1] = last;
}

unsigned int tail_recur_ins(vector<int>& arr, unsigned int n) {
	return ins_recur(arr, n, 1);
}

void move_element(int& j, vector<int>& vec, int key) {
	while (j >= 0 && vec[j] > key) {
		vec[j + 1] = vec[j];
		--j;
	}
}

map<string, long>  Insertion::insertion(string dirc, string out_dirc, int multi, int cnt) {
	prep(multi);

    vector<int> vec = rdf.readfile(dirc);
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
	int i, j;
	int key;
	for (i = 1; i < vec.size(); ++i) {
		key = vec[i];
		j = i - 1;

		// move each element of index j to its sorted position
		while (j >= 0 && vec[j] > key) {
			vec[j + 1] = vec[j];
			--j;
		}
		vec[j + 1] = key;
	}

	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "insertion (reg)");
	PROCESS_MEMORY_COUNTERS_EX pmc;

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

map<string, long>  Insertion::insertion_recur(string dirc, string out_dirc, int multi, int cnt) {
	prep(multi);

    vector<int> vec = rdf.readfile(dirc);
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
	tail_recur_ins(vec, vec.size());

	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "insertion (recur)");
	PROCESS_MEMORY_COUNTERS_EX pmc;

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

map<string, long>  Insertion::insertion_modular(string dirc, string out_dirc, int multi, int cnt) {
	prep(multi);

    vector<int> vec = rdf.readfile(dirc);
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
	int i, j;
	int key;
	for (i = 1; i < vec.size(); ++i) {
		key = vec[i];
		j = i - 1;

		// move each element of index j to its sorted position
		move_element(j, vec, key);
		vec[j + 1] = key;
	}

	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "insertion (mod)");
	PROCESS_MEMORY_COUNTERS_EX pmc;

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

// FOR TESTING ONLY

// int main() {
// 	Insertion ins;
// 	Judge jdg;
// 	ins.insertion("temp.txt", "out.txt", 1, 0); // localized test files
// 	cout << jdg.judge("temp.txt", "out.txt") << endl;
// 	ins.insertion_recur("temp.txt", "out.txt", 1, 0);
// 	cout << jdg.judge("temp.txt", "out.txt") << endl;
// 	ins.insertion_modular("temp.txt", "out.txt", 1, 0);
// 	cout << jdg.judge("temp.txt", "out.txt") << endl;
// 	return 0;
// }
