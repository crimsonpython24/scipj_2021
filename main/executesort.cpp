#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <stdio.h>
#include "../insertion/insertion.h"
#include "../selection/selection.h"
#include "writefile.h"
#include "judge.h"
using namespace std;

void choose_algo_nofilename(string algoname) {
	Insertion ins;
	Selection slc;
	if (algoname.compare("insertion") == 0)
		ins.insertion("", "..\\insertion\\out.txt");
	else if (algoname.compare("selection") == 0)
		slc.selection("", "..\\selection\\out.txt");
	return;
}

void choose_algo(string algoname) {
	Insertion ins;
	Selection slc;
	if (algoname.compare("insertion") == 0)
		ins.insertion("..\\insertion\\temp.txt", "..\\insertion\\out.txt");
	else if (algoname.compare("selection") == 0)
		slc.selection("..\\selection\\temp.txt", "..\\selection\\out.txt");	
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

bool in_array(const string &value, const vector<std::string> &array) {
    return std::find(array.begin(), array.end(), value) != array.end();
}

int handle_sort_algo(string algoname, string ind, bool check) {
	string temp, dir_name, out_name;
	int v_result, cnt = 0;
	Insertion ins;
	Selection slc;
	Judge jdg;
	while (check_yes(ind)) {
		++cnt;
		dir_name = "..\\" + algoname + "\\temp.txt";
		out_name = "..\\" + algoname + "\\out.txt";
		printf("\n------- CURRENT TOOL %s -------", algoname.c_str());
		cout << "\n>>> Change sort test file? (y/N) ";
		cin >> temp; cout << endl;
		if (check_yes(temp)) {
			cout << "------- CURRENT TOOL updatenum -------" << endl;
			printf(">>> Use default save location (..\\%s\\temp.txt)? (y/n) ", algoname.c_str());
			cin >> temp;
			if (check_yes(temp)) {
				update_nums_defaultdir(dir_name);
				printf("------- RETURN TO %s -------", algoname.c_str());
				choose_algo(algoname);
			} else {
				update_nums();
				choose_algo_nofilename(algoname);
				printf("------- RETURN TO %s -------", algoname.c_str());
			}
		}
		else {
			printf("\n>>> Using \"..\\%s\\temp.txt\"", algoname.c_str());
			choose_algo(algoname);	
		}

		if (check) {
			cout << "------- REDIRECT verification -------" << endl;
			cout << ">>> Change verification settings by typing \"updateverify\"" << endl;
			v_result = jdg.judge(dir_name, out_name);
			if (v_result == 1)
				cout << ">>> Verification passed!\n" << endl;
			else
				cout << ">>> Verification failed!\n" << endl;
		}

		cout << ">>> Continue with same algorithm? (y/n) ";
		cin >> ind;
	}
	return cnt;
}

int main() {
	string parent, child, cmd = "", temp, ind = "yes";
	vector<string> avbcommands = {"insertion", "selection"}, usedcommands = {};
	bool check = false;

	while (true) {
		if (cmd.compare("quit") == 0 || cmd.compare("q") == 0)
			break;
		else if (cmd.compare("updatenum") == 0) {
			cout << ">>> CURRENT TOOL updatenum;" << endl;
			update_nums();
		}
		else if (cmd.compare("updateverify") == 0) {
			check = !check;
			printf(">>> Verify has been toggled from %d to %d\n\n", !check, check);
		}
		else if (cmd.compare("help") == 0) {
			cout << "------- CURRENT TOOL help -------\n" << endl;
			cout << ">>> Type `help` for help (you're here)" << endl;
			cout << ">>> Type `quit` to quit the program" << endl;
			cout << ">>> Type `updateverify` to toggle sort-judging process" << endl;
			cout << ">>> Type `env` or `environ` to show program configurations" << endl;
			cout << ">>> Available list of algorithm commands: " << endl;
			cout << "    insertion, selection" << endl;
			cout << "\n------- EXIT help -------" << endl;
		}
		else if (cmd.compare("environ") == 0 || cmd.compare("env") == 0) {
			cout << "\n------- CURRENT TOOL environ -------" << endl;
			cout << "   - Verify sort results: " << check << endl;
			cout << "   - Used algorithms, in sequence: " << endl;
			for (int i = 0; i < usedcommands.size(); ++i) {
				cout << "      " << i+1 << ". " << usedcommands[i] << endl;
			}
		}
		else if (cmd.compare("") != 0) {
			if (!in_array(cmd, avbcommands))
				cout << ">>> Please input an available command; type `help` for help\n" << endl;
			else {
				int x = handle_sort_algo(cmd, ind, check);
				usedcommands.push_back(cmd + " (x" + to_string(x) + ")");
			}
		}
		cout << ">>> Input command [quit, help, *]: ";
		cin >> cmd;
		transform(cmd.begin(), cmd.end(), cmd.begin(), [](unsigned char c) {return std::tolower(c);});
	}

	return 0;
}
