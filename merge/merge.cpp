#include <bits/stdc++.h>
#include "windows.h"
#include "psapi.h"
#include "merge.h"
#include "../main/readfile.h"
#include "../main/writefile.h"
#include "../main/judge.h"
using namespace std;
using namespace std::chrono;

#define prep(multi) Readfile rdf; Writefile wrf; if (multi == 1) cout << "\n>>> running..." << endl

void merge(vector<int>& arr, int l, int m, int r) {
    int a1 = m - l + 1;
    int a2 = r - m;
 
    // create temp array and copy data 
    // YAY NO NEED TO WORRY ABOUT MOVING MEMORY
    int L[a1], R[a2];
    for (int i = 0; i < a1; ++i)
        L[i] = arr[l + i];
    for (int j = 0; j < a2; ++j)
        R[j] = arr[m + 1 + j];
 
    // Initial indices 
    int i = 0, j = 0, k = l;
    while (i < a1 && j < a2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i]; i++;
        }
        else {
            arr[k] = R[j]; j++;
        }
        k++;
    }
 
    // copy remaining numbers in l to main
    while (i < a1) {
        arr[k] = L[i];
        i++; k++;
    }
 
    // copy remaining numbers in r to main
    while (j < a2) {
        arr[k] = R[j];
        j++; k++;
    }
}

void mrg_recur(vector<int>& arr, int l, int r) {
    if (l >= r)
        return; //returns recursively
    int m = l + (r-l)/2;
    mrg_recur(arr, l, m);
    mrg_recur(arr, m+1, r);
    merge(arr, l, m, r);
}

void remove_ends(vector<int>& temp, vector<int>& arr, int& i, int& j, int& k, int mid, int to) {
	while (i <= mid && j <= to)
        temp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
}

void comb(vector<int>& arr, vector<int>& temp, int from, int mid, int to) {
	int k = from, i = from, j = mid + 1;

    remove_ends(temp, arr, i, j, k, mid, to);
	while (i < arr.size() && i <= mid)
		temp[k++] = arr[i++];

	for (int i = from; i <= to; i++)
		arr[i] = temp[i];
}

map<string, long> Merge::merge(string dirc, string out_dirc, int multi, int cnt) {
	prep(multi);

    vector<int> vec = rdf.readfile(dirc);
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
    const int lo = 0, hi = vec.size() - 1;
    int mid, stop;
    vector<int> temp1 = vec;
    for (int m = 1; m <= hi - lo; m = 2*m) {

        // all even iterations starting from 0
        for (int i = lo; i < hi; i += 2*m) {
            mid = i + m - 1;
            stop = (i + 2*m - 1 < hi) ? i + 2*m - 1 : hi;

            int k = i, l = i, f = mid + 1;

            // loop until all elements within bound is correctly placed
            while (l <= mid && f <= stop) 
                temp1[k++] = (vec[l] < vec[f]) ? vec[l++] : vec[f++];

            // copy first half of remaining elements (second half=done)
            while (l < vec.size() && l <= mid) 
                temp1[k++] = vec[l++];

            // copy sorted nums to original array
            for (int l = i; l <= stop; l++) 
                vec[l] = temp1[l];
        }
    }

	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "merge (reg)");

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

map<string, long> Merge::merge_recur(string dirc, string out_dirc, int multi, int cnt) {
	prep(multi);

    vector<int> vec = rdf.readfile(dirc);
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
    mrg_recur(vec, 0, vec.size() - 1);

	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "merge (recur)");

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

map<string, long> Merge::merge_modular(string dirc, string out_dirc, int multi, int cnt) {
	prep(multi);

    vector<int> vec = rdf.readfile(dirc);
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
    const int lo = 0, hi = vec.size() - 1;
    int mid, stop;
    vector<int> temp1 = vec;
    for (int m = 1; m <= hi - lo; m = 2*m) {

        // all even iterations starting from 0
        for (int i = lo; i < hi; i += 2*m) {
            mid = i + m - 1;
            stop = (i + 2*m - 1 < hi) ? i + 2*m - 1 : hi;

            comb(vec, temp1, i, mid, stop);
        }
    }

	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "merge (mod)");

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

// FOR TESTING ONLY

// int main() {
//     Merge mrg;
// 	Judge jdg;
// 	mrg.merge("temp.txt", "out.txt", 1, 0); // localized test files
// 	cout << jdg.judge("temp.txt", "out.txt") << endl;
// 	mrg.merge_recur("temp.txt", "out.txt", 1, 0); // localized test files
// 	cout << jdg.judge("temp.txt", "out.txt") << endl;
// 	mrg.merge_modular("temp.txt", "out.txt", 1, 0); // localized test files
// 	cout << jdg.judge("temp.txt", "out.txt") << endl;
// 	return 0;
// }
