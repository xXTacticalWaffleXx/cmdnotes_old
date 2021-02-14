#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// this is the source code for cmdnotes alpha 1.3, it will almost certainly be awful, i apologise for the pain reading this code may cause.

int main()
{
	string input;
	vector <string> Notes;
	int SaveNoteOnLine = 0;
	string output; //a var needed for specific situations, not used for all output
	string NoteToDump;
	int PrintNote; //also used for the delete command

	cout << "welcome to cmdnotes alpha v1.3 <3\n";
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
		else if (input == "-see") {
			cout << "what note do you want\n";
			cin >> PrintNote;
			cout << Notes.at(PrintNote) << endl;
		}
		else if (input == "-delete") {
			cout << "what note do you want to delete, type -1 to cancel\n";
			cin >> PrintNote;
			if (PrintNote == -1) {
				//does nothing
			}
			else {
				Notes.erase(Notes.begin() + PrintNote);
				SaveNoteOnLine = SaveNoteOnLine - 1;
			}
		}
		else if (input == "-mknote"){
			getline(cin, input);
			Notes.push_back(input);
			cout << "saved on line " << SaveNoteOnLine << endl;
			SaveNoteOnLine++;
		}
		else {
			//do nothing
		}
	}
}
