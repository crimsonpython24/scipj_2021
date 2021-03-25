# scipj_2021: Speed Comparison of Sorting Algorithms

> This experiment will be testing the speed of differnent algorithms using different implementations


## Background information
_Include the following information so the audience can have a better understanding of sorting algorithms_
* Why is sorting important?
* Introduction of structure


## Experiment
### Things to Keep in Mind
1. Create essential questions and hypotheses
2. Keep the number of questions small
3. Track potential shortcomings and add to "further research"
4. Control environmental variables
    1. Use duplicates of the original array (reduce differences from varying memory address)
    2. Monitor the resources consumed; place caps or use virtual machines if required
### Upon Completion
1. Analyze into detail (experiment's results)
2. Answer the essential questions


## Main Structure
Types of Algorithms/Implementations | Selection Sort | Merge Sort | Insertion Sort | Bubble Sort | Quick Sort |
------------ | ------------- | ------------- | ------------- | ------------- | -------------
**Minimized Implementation** | [1] |
**Recursive Implementation** |
**Modular Implementation ** |

[1] Details of each test:
 - [ ] Different cases like increasing, decreasing, evenly distributed, and random will be tested
     - Data types are ignored as the execution speed depends more on the sequence than on the types of data
     - The process will adopt `16-bit unsigned integers (0 to 65,535)` among all tests
     - Definitions of "evenly distributed" and "random" will be elaborated in the experiment
 - [ ] The original values (mentioned above) will not be altered; copies will be used instead
 - [ ] Stats like the number of comparisons storage operations will be recorded for analyses during execution


## Generic Sort Algorithms
Language | Function Name | Algorithm Name | Algorithm Details | Ref
-------- | -------- | -------- | -------- | --------
C | `qsort` | Quick Sort | Sorting algorithm with a lot of pivots | [Link](https://stackoverflow.com/questions/3893937/sorting-an-array-in-c)
C++ | `std::sort` | Intro Sort | Mix of quick, heap, and insertion sort | [Link](https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/)
Python | `sort()` | Tim Sort[2] | Mix of merge and insertion sort (named after its inventor, Tim Peters) | [Link](https://stackoverflow.com/questions/10948920/what-algorithm-does-pythons-sorted-use)
Java | `Arrays.sort(T[])` | Tim Sort | Mix of merge and insertion sort | [Link](https://stackoverflow.com/questions/14322585/collections-sort-implementation/14322664)
Javascript | `Array.prototype.sort` | Tim Sort | See above | [Link](https://medium.com/tds-note/how-array-prototype-sort-works-in-v8-d69ff0a7b663)
Go | (import) `src/sort/sort.go` | Various | A collection of algorithms in a library, import as needed | [Link](https://golang.org/src/sort/sort.go)
Rust | `[T]::sort` | Tim Sort | See above | [Link](https://stackoverflow.com/questions/54852554/what-sorting-algorithm-does-rusts-built-in-sort-use)


[2] The Python version of Tim Sort is written and optimized in C



***Implementations are all open-source!*** **☭ <- our_data**
