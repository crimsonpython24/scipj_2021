#include <bits/stdc++.h>
#include "writefile.h"
#include "judge.h"
#include "utils.h"
#include "../insertion/insertion.h"
#include "../selection/selection.h"
#include "../merge/merge.h"
#include "../quick/quick.h"
#include "../bubble/bubble.h"
using namespace std;

#define prl cout<<endl
template <typename T> void message_input(string str1, T& into) {cout << str1; cin >> into;}
vector<int> empty_vec = {};

int handle_sort_algo(string algoname, int md, string ind, bool check, bool empty_json, ofstream& file, int& json_count) {
	string temp, temp2, dir_name, out_name, write_dir;
	int v_result, cnt = 0, multicnt = 1;
	bool multirand = false;
	vector<pair<int, int>> nums = {}; pair<int, int> temp4 {}; pair<string, vector<int>> temp6;
	map<string, long> m1;
	Insertion ins; Selection slc; Merge mrg; Quick quk; Bubble bub;
	Writefile wrf; Judge jdg; Utils uts;

	while (uts.check_yes(ind)) {
		++cnt;
		dir_name = "..\\txt_files\\temp.txt";
		out_name = "..\\txt_files\\out.txt";
		vector<int> conf = {-1, -1, -1, -1};
		printf("\n------- CURRENT TOOL %s -------", algoname.c_str());
		message_input("\n>>> Create multirun process? (y/N) ", temp);

		if (uts.check_yes(temp)) {
			message_input(">>> How many times to run? (positive whole number) ", multicnt);
			message_input(">>> Manually create a new file each time? (y/N) ", temp2);
			if (uts.check_yes(temp2))
				multirand = true;
			prl;
		}
		temp = "";

		if (multicnt == 1) {
			message_input("\n>>> Change sort test file? (y/N) ", temp);
		}
		if (empty_json) {
			file << "\t\"" << json_count << "\": \n\t[" << endl;
			empty_json = false;
		}
		else
			file << "\t,\"" << json_count << "\": \n\t[" << endl;
		++json_count;

		if (uts.check_yes(temp) || multirand == true) { // for both cases, user wants to change input file
			message_input(">>> Use default save location (..\\txt_files\\temp.txt)? (y -> edit current/n -> create new) ", temp);
			if (multicnt != 1)
				cout << "\n>>> Repeating process for " << multicnt << " times...\n" << endl;

			temp2 = (multicnt == 1) ? "\t\t{\"mode\": \"single\", \"algorithm\": \"" + algoname + "\"},\n\t\t[" :
			                         "\t\t{\"mode\": \"multi\", \"algorithm\": \"" + algoname + "\"},\n\t\t[";
			file << temp2 << endl;
			nums = {};
			for (int i = 1; i <= multicnt; ++i) {
				if (!uts.check_yes(temp)) {
					cout << "\n------- CURRENT TOOL writefile -------" << endl;
					temp6 = wrf.writefile(empty_vec);
					write_dir = temp6.first;
					conf = temp6.second;
					cout << "------- EXIT TOOL writefile -------\n" << endl;
				} else {
					conf = wrf.writefiledefaultdir(dir_name, empty_vec);
					write_dir = "";
				}

				m1 = uts.choose_algo(write_dir, algoname, md, multicnt, i, ins, slc, mrg, quk, bub);
				temp4.first = m1.at("items"); temp4.second = m1.at("time"); nums.push_back(temp4);
				uts.json_parse_child(i, file, m1);
				
				if (i < multicnt)
					printf("\n------- RETURN TO %s -------\n", algoname.c_str());
			}
			uts.write_file_end(multicnt, file, temp4, uts, nums, conf);
		}
		else { // repeat itself without changing anything BUT will ask for file input
			message_input(">>> Use default file (..\\txt_files\\temp.txt), not recommended for patched exe? (y/n) ", write_dir);
			string newin, auto_choice, temp5;
			vector<int> config = {0, 0, 0, 0, 0, 0};
			if (multicnt != 1)
				message_input(">>> Automatically generate new test file every time? (y/n) ", newin);

			if (multicnt != 1)
				cout << "\n>>> Repeating process for " << multicnt << " times...\n" << endl;
			if (uts.check_yes(newin)) {
				cout << ">>> Automatic files (taken from config); alt directories are turned off" << endl;
				message_input(">>> Stick with the existing configuration? (y/n) ", temp5);
				if (uts.check_yes(temp5)) 
					cout << ">>> Nevermind. move on" << endl;
				else {
					cout << ">>> How random should the files be? Note: the numbers are in `int`" << endl;
					message_input("     * Enter lower bound for count: ", config[0]);
					message_input("     * Enter upper bound for count: ", config[1]);
					message_input("     * Enter lower bound for range: ", config[2]);
					message_input("     * Enter upper bound for range: ", config[3]);
					message_input("     * Enter range for lower bound (can be negative): ", config[4]);
					message_input("     * Enter range for upper bound (can be negative): ", config[5]);
				}
			}

			if (uts.check_yes(write_dir) || uts.check_yes(newin)) {
				cout << (">>> Using \"..\\txt_files\\temp.txt\"\n"); write_dir = "";
			}
			else {
				message_input(">>> Input text file directory: ", write_dir);
				printf(">>> Using \"%s\"\n", write_dir.c_str());
			}
			temp2 = (multicnt == 1) ? "\t\t{\"mode\": \"single\", \"algorithm\": \"" + algoname + "\"},\n\t\t[" :
									"\t\t{\"mode\": \"multi\", \"algorithm\": \"" + algoname + "\"},\n\t\t[";
			file << temp2 << endl;
			nums = {};
			for (int i = 1; i <= multicnt; ++i) {
				if (uts.check_yes(newin)) {
					conf = wrf.writefiledefaultdir(dir_name, config);
					m1 = uts.choose_algo("", algoname, md, multicnt, i, ins, slc, mrg, quk, bub);
				} else {
					m1 = uts.choose_algo(write_dir, algoname, md, multicnt, i, ins, slc, mrg, quk, bub);
				}
				temp4.first = m1.at("items"); temp4.second = m1.at("time"); nums.push_back(temp4);
				uts.json_parse_child(i, file, m1);
			}
			uts.write_file_end(multicnt, file, temp4, uts, nums, conf);
		}

		if (check) {
			cout << "------- REDIRECT verification -------" << endl;
			cout << ">>> Change verification settings by typing \"updateverify\"" << endl;
			v_result = jdg.judge(dir_name, out_name);

			temp = (v_result == 1) ? ">>> Verification passed!\n" : ">>> Verification failed\n";
			cout << temp << endl;
		}

		message_input(">>> Continue with same algorithm? (y/n) ", ind);
		multicnt = 1; multirand = false; prl;
	}

	return cnt;
}

int main() {
	string parent, child, cmd = "", temp, ind = "yes";
	vector<string> avbcommands = {"insertion", "selection"}, usedcommands = {};
	Writefile wrf; Utils uts;
	bool check = false, empty_json = true;	
	int json_count = 0;

	ofstream file;
	file.open("test.json");
	file << "{" << endl;

	cout << "------ WARNING ------" << endl;
	cout << "Do NOT close the program using ctrl+C!\nThe JSON file depends on the last bracket, ";
	cout << "so exit using `q` or `quit.`\nBlame me for using my least familiarized language...\n";
	cout << "Take your time and enter the commands carefully. There's no return!\n";
	cout << "------ END WARNING ------\n" << endl;

	while (true) {
		if (cmd.compare("quit") == 0 || cmd.compare("q") == 0)
			break;
		else if (cmd.compare("updatenum") == 0) {
			cout << ">>> CURRENT TOOL updatenum;" << endl;
			wrf.writefile(empty_vec);
		}
		else if (cmd.compare("updateverify") == 0) {
			check = !check;
			printf(">>> Verify has been toggled from %d to %d\n\n", !check, check);
		}
		else if (cmd.compare("help") == 0) {
			cout << "\n------- CURRENT TOOL help -------\n" << endl;
			cout << ">>> Type `help` for help (you're here)" << endl;
			cout << ">>> Type `quit` to quit the program" << endl;
			cout << ">>> Type `updateverify` to toggle sort-judging process" << endl;
			cout << ">>> Type `env` or `environ` to show program configurations" << endl;
			cout << ">>> Type `writefile` or `updatenums` to update test list" << endl;
			cout << ">>> Available list of algorithm commands: " << endl;
			cout << "    insertion, selection" << endl;
			cout << "\n------- EXIT help -------\n" << endl;
		}
		else if (cmd.compare("environ") == 0 || cmd.compare("env") == 0) {
			cout << "\n------- CURRENT TOOL environ -------\n" << endl;
			cout << "   - Verify sort results: " << check << endl;
			cout << "   - Used algorithms, in sequence: " << endl;
			for (unsigned int i = 0; i < usedcommands.size(); ++i)
				cout << "      " << i+1 << ". " << usedcommands[i] << endl;
			cout << "\n------- EXIT environ -------\n" << endl;
		}
		else if (cmd.compare("writefile") == 0 || cmd.compare("updatenums") == 0) {
			cout << "\n------ CURRENT TOOL writefile -------" << endl;
			cout << ">>> Note: don't forget folder name i.e., \"..\\insertion\\temp.txt\" or \"..\\selection\\temp.txt\"" << endl;
			wrf.writefile(empty_vec);
			cout << "------ EXIT writefile -------\n" << endl;
		}
		else if (cmd.compare("") != 0) {
			if (!uts.in_array(cmd, avbcommands))
				cout << ">>> Please input an available command; type `help` for help\n" << endl;
			else {
				int md;
				message_input("    >>> Enter mode (1-normal, 2-recursive, 3-modular): ", md);
				int x = handle_sort_algo(cmd, md, ind, check, empty_json, file, json_count);
				empty_json = false;
				usedcommands.push_back(cmd + " (x" + to_string(x) + ")");
			}
		}
		message_input(">>> Input command [quit, help, *]: ", cmd);
		transform(cmd.begin(), cmd.end(), cmd.begin(), [](unsigned char c) {return std::tolower(c);});
	}
	
	file << "}" << endl;
	file.close();
	return 0;
}
