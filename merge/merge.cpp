#include <bits/stdc++.h>
#include "windows.h"
#include "psapi.h"
#include "merge.h"
#include "../main/readfile.h"
#include "../main/writefile.h"
#include "../main/judge.h"
using namespace std;
using namespace std::chrono;

// unsigned int tail_recur(vector<int>& arr, unsigned int n) {
// 	return sel_recur(arr, n, 0, 1);
// }

void comb(vector<int>& A, vector<int>& temp, int from, int mid, int to)
{
	int k = from, i = from, j = mid + 1;

	// loop till no elements are left in the left and right runs
	while (i <= mid && j <= to)
	{
		if (A[i] < A[j]) {
			temp[k++] = A[i++];
		}
		else {
			temp[k++] = A[j++];
		}
	}

	// copy remaining elements
	while (i < A.size() && i <= mid) {
		temp[k++] = A[i++];
	}

	/* no need to copy the second half (since the remaining items
	   are already in their correct position in the temporary array) */

	// copy back to the original array to reflect sorted order
	for (int i = from; i <= to; i++) {
		A[i] = temp[i];
	}
}

map<string, long> Merge::merge(string dirc, string out_dirc, int multi, int cnt) {
	Readfile rdf;
	Writefile wrf;
    vector<int> vec = rdf.readfile(dirc);

	if (multi == 1)
		cout << "\n>>> running..." << endl;
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
            while (l <= mid && f <= stop) {
                if (vec[l] < vec[f]) 
                    temp1[k++] = vec[l++];
                else 
                    temp1[k++] = vec[f++];
            }

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


// FOR TESTING ONLY

int main() {
    Merge mrg;
	Judge jdg;
	mrg.merge("temp.txt", "out.txt", 1, 0); // localized test files
	cout << jdg.judge("temp.txt", "out.txt") << endl;
	return 0;
}
