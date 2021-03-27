#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include "insertion/insertion.h"
using namespace std;

int main() {
	string parent, child, cmd = "";
	
	while (cmd != "quit") {
		if (cmd.compare("quit") == 0)
			break;
		else if (cmd.compare("insertion") == 0) {
			Insertion ins;
			ins.insertion();
		}
		cout << "Input command: "
		// add help/shortcut menu
		cin >> cmd;
		transform(cmd.begin(), cmd.end(), cmd.begin(), [](unsigned char c){ return std::tolower(c); });
	}

	return 0;
}
