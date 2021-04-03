#include <bits/stdc++.h>
#include "windows.h"
#include "psapi.h"
#include "quick.h"
#include "../main/readfile.h"
#include "../main/writefile.h"
#include "../main/judge.h"
using namespace std;
using namespace std::chrono;

#define prep(multi) Readfile rdf; Writefile wrf; if (multi == 1) cout << "\n>>> running..." << endl

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* This function is same in both iterative and recursive*/
int partition(vector<int>& arr, int& l, int& h) {
    int x = arr[h];
    int i = (l - 1);
  
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= x) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]);
    return (i + 1);
}

void recur(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[p] is now at right place 
        int pi = partition(arr, low, high);
 
        // Separately sort elements before partition and after partition
        recur(arr, low, pi - 1);
        recur(arr, pi + 1, high);
    }
}

void push_left(vector<int>& stack, int p, int l, int& top) {
    if (p - 1 > l) {
        stack[++top] = l; stack[++top] = p - 1;
    }
    return;
}

void push_right(vector<int>& stack, int p, int h, int& top) {
    if (p + 1 < h) {
        stack[++top] = p + 1; stack[++top] = h;
    }
    return;
}

map<string, long> Quick::quick(string dirc, string out_dirc, int multi, int cnt) {
	prep(multi);

    vector<int> vec = rdf.readfile(dirc);
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
    int l = 0, h = vec.size() - 1;

    // Create an auxiliary stack
    vector<int> stack(h - l + 1);
  
    // initialize top of stack
    int top = -1;
  
    // push initial values of l and h to stack
    stack[++top] = l;
    stack[++top] = h;
  
    // Keep popping from stack while is not empty
    while (top >= 0) {
        // Pop h and l
        h = stack[top--]; l = stack[top--];
  
        // Set pivot element at its correct position in sorted array
        int p = partition(vec, l, h);
  
        // If there are elements on left side of pivot, then push left side to stack
        if (p - 1 > l) {
            stack[++top] = l; stack[++top] = p - 1;
        }
        // If there are elements on right side of pivot, then push right side to stack
        if (p + 1 < h) {
            stack[++top] = p + 1; stack[++top] = h;
        }
    }
    // optimize if array is already sirted
    

	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "quick (reg)");

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

map<string, long> Quick::quick_recur(string dirc, string out_dirc, int multi, int cnt) {
	prep(multi);

    vector<int> vec = rdf.readfile(dirc);
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
    recur(vec, 0, vec.size()-1);
    
	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "quick (rec)");

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

map<string, long> Quick::quick_modular(string dirc, string out_dirc, int multi, int cnt) {
	prep(multi);

    vector<int> vec = rdf.readfile(dirc);
	auto start = high_resolution_clock::now(); // start

	// main sorting algo
    int l = 0, h = vec.size() - 1;
    vector<int> stack(h - l + 1);
    int top = -1;
  
    stack[++top] = l; stack[++top] = h;
  
    while (top >= 0) {
        h = stack[top--]; l = stack[top--]; 
        int p = partition(vec, l, h);

        push_left(stack, p, l, top);
        push_right(stack, p, h, top);
    }

	auto end = high_resolution_clock::now(); // end
	auto dur = duration_cast<microseconds>(end-start);
	
	PROCESS_MEMORY_COUNTERS_EX pmc;
	wrf.write_all_results(out_dirc, vec, multi, dur.count(), cnt, "quick (mod)");

	map<string, long> m1 = {{"mem", pmc.WorkingSetSize}, {"time", dur.count() }, {"items", vec.size()}};
	return m1;
}

// FOR TESTING ONLY

// int main() {
//     Quick quk;
// 	Judge jdg;
// 	quk.quick("temp.txt", "out.txt", 1, 0); // localized test files
// 	cout << jdg.judge("temp.txt", "out.txt") << endl;
// 	quk.quick_recur("temp.txt", "out.txt", 1, 0); // localized test files
// 	cout << jdg.judge("temp.txt", "out.txt") << endl;
// 	quk.quick_modular("temp.txt", "out.txt", 1, 0); // localized test files
// 	cout << jdg.judge("temp.txt", "out.txt") << endl;
// 	return 0;
// }
