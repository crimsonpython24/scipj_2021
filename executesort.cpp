#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "insertion/insertion.h"
#include "writefile.h"
using namespace std;

void update_nums_dftdir(string dirc) {
	Writefile wrf;
	wrf.writefiledftdir(dirc);
}

void update_nums() {
	Writefile wrf;
	wrf.writefile();
}

string to_str(char* a) {
    int i;
    string s = "";
    for (i = 0; i < sizeof(a); ++i) 
        s = s + a[i];
    return s;
}

int main() {
	string parent, child, cmd = "", temp;
	Insertion ins;

	while (cmd != "quit") {
		if (cmd.compare("quit") == 0)
			break;
		else if (cmd.compare("insertion") == 0) {
			cout << ">>> CURRENT TOOL insertion;" << endl;
			cout << ">>> Change sort test file? (y/N) ";
			cin >> temp;
			if (temp.compare("y") == 0 || temp.compare("yes") == 0) {
				cout << ">>> CURRENT TOOL updatenum;" << endl;
				cout << ">>> Use default save location (insertion\\temp.txt)? (y/n) ";
				cin >> temp;
				if (temp.compare("y") == 0 || temp.compare("yes") == 0) {
					update_nums_dftdir("insertion\\temp.txt");
					cout << ">>> EXIT updatenum;\n>>> CURRENT TOOL insertion;" << endl;
					ins.insertion("insertion\\temp.txt");
				} else {
					update_nums();
					cout << ">>> EXIT updatenum;\n>>> CURRENT TOOL insertion;" << endl;
					ins.insertion("");
				}
			}
			else
				ins.insertion("");
		}
		else if (cmd.compare("updatenum") == 0) {
			cout << ">>> CURRENT TOOL updatenum;" << endl;
			update_nums();
		}
		cout << ">>> Input command: ";
		// add help/shortcut menu
		cin >> cmd;
		transform(cmd.begin(), cmd.end(), cmd.begin(), [](unsigned char c){ return std::tolower(c); });
	}

	return 0;
}
