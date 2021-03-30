#include <bits/stdc++.h>
#include "readfile.h"
using namespace std;

vector<int> Readfile::readfile (string dirc) {
    string fn;
	if (dirc.compare("") == 0) {
		cout << ">>> Input file name: "; cin >> fn;
	}
	else
		fn = dirc;

	ifstream infile(fn);
	string line;
	vector<int> ints;

	while (getline(infile, line)) {
		istringstream iss(line);
		for (string k; iss >> k; )
			ints.push_back(stoi(k));
	}

	return ints;
}

// int main() {
//     Readfile rdf;
//     rdf.readfile("..\\insertion\\temp.txt");
//     return 0;
// }