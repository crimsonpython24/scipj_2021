#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdio.h>
#include "../insertion/insertion.h"
#include "../selection/selection.h"
#include "writefile.h"
using namespace std;

void choose_algo_nofilename(string algoname) {
	Insertion ins;
	Selection slc;
	if (algoname.compare("insertion") == 0)
		ins.insertion("");
	else if (algoname.compare("selection") == 0)
		slc.selection("");
	return;
}

void choose_algo(string algoname) {
	Insertion ins;
	Selection slc;
	if (algoname.compare("insertion") == 0)
		ins.insertion("..\\insertion\\temp.txt");
	else if (algoname.compare("selection") == 0)
		slc.selection("..\\selection\\temp.txt");	
}

void update_nums_defaultdir(string dirc) {
	Writefile wrf;
	wrf.writefiledefaultdir(dirc);
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
	transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {return std::tolower(c);});
	return (str.compare("y") == 0 || str.compare("yes") == 0);
}

void handle_sort_algo(string algoname, string ind) {
	string temp;
	Insertion ins;
	Selection slc;
	while (check_yes(ind)) {
		printf("\n------- CURRENT TOOL %s -------", algoname.c_str());
		cout << "\n>>> Change sort test file? (y/N) ";
		cin >> temp; cout << endl;
		if (check_yes(temp)) {
			cout << "------- CURRENT TOOL updatenum -------" << endl;
			printf(">>> Use default save location (..\\%s\\temp.txt)? (y/n) ", algoname.c_str());
			cin >> temp;
			if (check_yes(temp)) {
				if (algoname.compare("insertion") == 0)
					update_nums_defaultdir("..\\insertion\\temp.txt");
				else if (algoname.compare("selection") == 0)
					update_nums_defaultdir("..\\selection\\temp.txt");

				printf("------- EXIT updatenum -------\n------- RETURN TO %s -------", algoname.c_str());
				choose_algo(algoname);
			} else {
				update_nums();
				choose_algo_nofilename(algoname);
				printf("------- EXIT updatenum;\n------- RETURN TO %s -------", algoname.c_str());
			}
		}
		else {
			printf("\n>>> Using \"..\\%s\\temp.txt\"", algoname.c_str());
			choose_algo(algoname);	
		}
		cout << ">>> Continue with same algorithm? (y/n) ";
		cin >> ind;
	}
}

int main() {
	string parent, child, cmd = "", temp, ind = "yes";

	while (true) {
		if (cmd.compare("quit") == 0 || cmd.compare("q") == 0)
			break;
		else if (cmd.compare("updatenum") == 0) {
			cout << ">>> CURRENT TOOL updatenum;" << endl;
			update_nums();
		}
		else if (cmd.compare("help") == 0) {
			cout << "------- CURRENT TOOL help -------\n" << endl;
			cout << ">>> Type `help` for help (you're here)" << endl;
			cout << ">>> Type `quit` to quit the program" << endl;
			cout << ">>> Available list of algorithm commands: " << endl;
			cout << "    insertion, selection" << endl;
			cout << "\n------- EXIT help -------" << endl;
		}
		else if (cmd.compare("") != 0) {
			handle_sort_algo(cmd, ind);
		}
		cout << ">>> Input command [quit, help, *]: ";
		cin >> cmd;
		transform(cmd.begin(), cmd.end(), cmd.begin(), [](unsigned char c) {return std::tolower(c);});
	}

	return 0;
}
