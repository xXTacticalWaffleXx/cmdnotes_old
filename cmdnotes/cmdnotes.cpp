#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

// this is the source code for cmdnotes alpha v2, it will almost certainly be awful, i apologise for the pain reading this code may cause.

int main()
{
	string input;
	vector <string> Notes;
	int SaveNoteOnLine = 0;
	string output; //a var needed for specific situations, not used for all output
	string NoteToDump;
	int PrintNote; //also used for the delete command

	// imports any notes the user has saved in prior sessions
	ifstream in("cmdnotes_data.txt");
	string str;
	// Read the next line from File untill it reaches the end.
	while (getline(in, str))
	{
		// Line contains string of length > 0 then save it in vector
		if (str.size() > 0)
			Notes.push_back(str);
	}
	in.close();
	SaveNoteOnLine = Notes.size();
	
	// the main code that the user interacts with
	cout << "welcome to cmdnotes beta v1 <3\ntype -help for a list of commands\n";
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
		else if (input == "-save") {

			ofstream outFile("cmdnotes_data.txt"); 
			for (const auto &e : Notes) outFile << e << "\n";
			cout << "done, you will have to exit this program to actually save your file\n"; // -save only tells the program what to save when it exits, it doesnt do the saving there and then
		}
		else if (input == "-help") {
			// lists the commands
			cout << "-exit: closes the program" << endl << "-see: lets you print a specific note" << endl << "-delete lets you delete a note" << endl << "-mknote: lets you make a new note" << endl << "-save: saves your notes to a file (please keep in mind this doesnt keep the notes safe from your computer crashing, to do that please restart the program)" << endl;
		}
		else {
			//do nothing
		}
	}
}
