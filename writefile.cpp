#include <iostream>
#include <fstream>
#include <random>
using namespace std;

#define prl cout<<endl

int main() {
	string filename;
	int mode, cnt;
	cout << "Input file name: "; cin >> filename;
	cout << "Choose 1 for linear, 2 for random: "; cin >> mode;
	cout << "Input number of numbers: "; cin >> cnt;

	ofstream file;
	file.open(filename);

	if (mode == 1) {
		for (int i = 0; i < cnt; ++i)
			file << i << " ";
	} else if (mode == 2) {
		int lo, hi;
		cout << "Input lower and upper bound, separate with \'enter\': ";
		cin >> lo >> hi;
		
		random_device rand;

		for (int i = 0; i < cnt; ++i) {
			mt19937 rng(rand());
			uniform_int_distribution<mt19937::result_type> dist6(lo, hi);
			file << dist6(rng) << " ";
		}
	}

	file.close();
	return 0;
}	
