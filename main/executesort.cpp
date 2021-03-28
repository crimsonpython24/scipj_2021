#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "../insertion/insertion.h"
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

bool check_yes(string str) {
	return (str.compare("y") == 0 || str.compare("yes") == 0);
}

int main() {
	string parent, child, cmd = "", temp, ind = "yes";
	Insertion ins;

	while (cmd != "quit") {
		if (cmd.compare("quit") == 0)
			break;
		else if (cmd.compare("insertion") == 0) {
			while (check_yes(ind)) {
				cout << "------- CURRENT TOOL insertion -------" << endl;
				cout << ">>> Change sort test file? (y/N) ";
				cin >> temp;
				if (check_yes(temp)) {
					cout << "------- CURRENT TOOL updatenum -------" << endl;
					cout << ">>> Use default save location (..\\insertion\\temp.txt)? (y/n) ";
					cin >> temp;
					if (check_yes(temp)) {
						update_nums_dftdir("..\\insertion\\temp.txt");
						cout << "------- EXIT updatenum -------\n------- CURRENT TOOL insertion -------" << endl;
						ins.insertion("..\\insertion\\temp.txt");
					} else {
						update_nums();
						cout << "------- EXIT updatenum;\n------- CURRENT TOOL insertion -------" << endl;
						ins.insertion("");
					}
				}
				else {
					cout << ">>> Using \"..\\insertion\\temp.txt\"" << endl;
					ins.insertion("..\\insertion\\temp.txt");
				}
				cout << "Continue? (y/n) ";
				cin >> ind;
			}
		}
		else if (cmd.compare("updatenum") == 0) {
			cout << ">>> CURRENT TOOL updatenum;" << endl;
			update_nums();
		}
		else if (cmd.compare("help") == 0) {
			cout << "------- CURRENT TOOL help -------\n" << endl;
			cout << ">>> Type `help` for help (you're here)" << endl;
			cout << ">>> Type `quit` to quit the program" << endl;
			cout << ">>> Available list of algorithm commands: " << endl;
			cout << "    insertion" << endl;
			cout << "\n------- EXIT help -------" << endl;
		}
		cout << ">>> Input command [quit, help, *]: ";
		cin >> cmd;
		transform(cmd.begin(), cmd.end(), cmd.begin(), [](unsigned char c) {return std::tolower(c);});
	}

	return 0;
}
