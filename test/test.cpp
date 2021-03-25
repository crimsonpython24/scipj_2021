// C++ program to find out execution time of
// of functions
#include <algorithm>
#include <chrono>
#include <iostream>
#include<vector>
using namespace std;
using namespace std::chrono;
  
// For demonstration purpose, we will fill up
// a vector with random integers and then sort
// them using sort function. We fill record
// and print the time required by sort function
int main()
{
  
    vector<int> values(10000);
  
    // Generate Random values
    auto f = []() -> int { return rand() % 10000; };
  
    // Fill up the vector
    generate(values.begin(), values.end(), f);
  
    // Get starting timepoint
    auto start = high_resolution_clock::now();
  
    // Call the function, here sort()
    sort(values.begin(), values.end());
  
    // Get ending timepoint
    auto stop = high_resolution_clock::now();
  
    // Get duration. Substart timepoints to 
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
         
	// test 2
	 vector<int> val(1000);
  
    // Generate Random values
    auto f1 = []() -> int { return rand() % 10000; };
  
    // Fill up the vector
    generate(val.begin(), val.end(), f1);
  
    // Get starting timepoint
    auto start1 = high_resolution_clock::now();
  
    // Call the function, here sort()
    sort(val.begin(), val.end());
  
    // Get ending timepoint
    auto stop1 = high_resolution_clock::now();
  
    // Get duration. Substart timepoints to 
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
  
    cout << "Time taken by function: "
         << duration1.count() << " microseconds" << endl;
         
    //TEST 3	
     vector<int> val2(100000);
  
    // Generate Random values
    auto f2 = []() -> int { return rand() % 10000; };
  
    // Fill up the vector
    generate(val2.begin(), val2.end(), f2);
  
    // Get starting timepoint
    auto start2 = high_resolution_clock::now();
  
    // Call the function, here sort()
    sort(val2.begin(), val2.end());
  
    // Get ending timepoint
    auto stop2 = high_resolution_clock::now();
  
    // Get duration. Substart timepoints to 
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
  
    cout << "Time taken by function: "
         << duration2.count() << " microseconds" << endl;
  
    return 0;
}
