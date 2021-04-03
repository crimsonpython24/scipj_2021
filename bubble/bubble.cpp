#include <bits/stdc++.h>
#include "windows.h"
#include "psapi.h"
#include "bubble.h"
#include "../main/readfile.h"
#include "../main/writefile.h"
#include "../main/judge.h"
using namespace std;
using namespace std::chrono;

#define prep(multi) Readfile rdf; Writefile wrf; if (multi == 1) cout << "\n>>> running..." << endl

void swap_vecint(int&a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

unsigned bub_recur(vector<int>& arr, int n, unsigned int a) {
    // Base case
    if (n == 1)
        return a;
 
    // One pass of bubble sort. After
    // this pass, the largest element
    // is moved (or bubbled) to end.
    for (int i = 0; i < n-1; ++i)
        if (arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
 
    // Largest element is fixed,
    // recur for remaining array
    bub_recur(arr, n-1, n*a);
}

unsigned int tail_recur_bub(vector<int>& arr, unsigned int n) {
	return bub_recur(arr, n, 1);
}

map<string, long> Bubble::bubble(string dirc, string out_dirc, int multi, int cnt) {
	prep(multi);

    vector<int> vec = rdf.readfile(dirc);
	auto start = high_resolution_clock::now(); // start

	// main sorting algo

    // optimize if array is already sirted
    bool swapped; int temp;
    for (int i = 0; i < vec.size()-1; ++i) {
        swapped = false;
        for (int j = 0; j < vec.size()-i-1; j++) {
            if (vec[j] > vec[j + 1]) {
                // weird type errors
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                swapped = true;
            }
        }

        // break if no two el;ements are swapped in inner loop
        if (swapped = false)
            break;
    }

	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "bubble (reg)");

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

map<string, long> Bubble::bubble_recur(string dirc, string out_dirc, int multi, int cnt) {
	prep(multi);

    vector<int> vec = rdf.readfile(dirc);
	auto start = high_resolution_clock::now(); // start

	// main sorting algo

    // optimize if array is already sirted
	tail_recur_bub(vec, vec.size());

	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "bubble (reg)");

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

map<string, long> Bubble::bubble_modular(string dirc, string out_dirc, int multi, int cnt) {
	prep(multi);

    vector<int> vec = rdf.readfile(dirc);
	auto start = high_resolution_clock::now(); // start

	// main sorting algo

    // optimize if array is already sirted
    bool swapped; int temp;
    for (int i = 0; i < vec.size()-1; ++i) {
        swapped = false;
        for (int j = 0; j < vec.size()-i-1; j++) {
            if (vec[j] > vec[j + 1]) {
                // weird type errors
                swap_vecint(vec[j], vec[j+1]);
                swapped = true;
            }
        }

        // break if no two el;ements are swapped in inner loop
        if (swapped = false)
            break;
    }

	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "bubble (mod)");

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

// FOR TESTING ONLY

int main() {
    Bubble bub;
	Judge jdg;
	bub.bubble("temp.txt", "out.txt", 1, 0); // localized test files
	cout << jdg.judge("temp.txt", "out.txt") << endl;
	bub.bubble_recur("temp.txt", "out.txt", 1, 0); // localized test files
	cout << jdg.judge("temp.txt", "out.txt") << endl;
	bub.bubble_modular("temp.txt", "out.txt", 1, 0); // localized test files
	cout << jdg.judge("temp.txt", "out.txt") << endl;
	return 0;
}
