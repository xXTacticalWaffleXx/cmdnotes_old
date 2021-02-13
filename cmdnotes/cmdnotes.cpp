#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// this is the source code for cmdnotes alpha 1.2, it will almost certainly be awful, i apologise for the pain reading this code may cause.

int main()
{
	string input;
	vector <string> Notes;
	int SaveNoteOnLine = 0;
	string output; //a var needed for specific situations, not used for all output
	string NoteToDump;
	int PrintNote;

	cout << "welcome to cmdnotes alpha v1.2\n";
	while (true) {
		getline(cin, input);
		if (input == "-list") {
			for (int i = 0; i < SaveNoteOnLine; i++) {
				cout << i << " " << Notes.at(i) << endl;
			}
		}
		else if (input == "-exit") {
			return 0;
		}
		else if (input.substr(0, 4) == "-see") {
			cout << "what note do you want\n";
			cin >> PrintNote;
		}
		else {
			Notes.push_back(input);
			cout << "saved on line " << SaveNoteOnLine << endl;
			SaveNoteOnLine++;
		}
	}
}
