#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

// this is the source code for cmdnotes beta v4, it will almost certainly be awful, i apologise for the pain reading this code may cause.
// this program and code is under the unlicence and therefore in the public domain

int main()
{
	//sets up varibles that the program needs
	string input;
	vector <string> Notes;
	int SaveNoteOnLine = 1;
	string output; //a var needed for specific situations, not used for all output
	string NoteToDump;
	int PrintNote; //also used for the delete command
	bool rollback = false;

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
	cout << "welcome to cmdnotes beta v4 <3\ntype -help for a list of commands\n";
	while (true) {
		getline(cin, input);
		if (input == "-list") {
			for (int i = 0; i < SaveNoteOnLine; i++) {
				cout << i + 1 << " " << Notes.at(i) << endl;
			}
		}
		else if (input == "-exit") {
			return 0;
		}
		else if (input == "-see") {
			cout << "what note do you want\n";
			cin >> PrintNote;
			if (PrintNote > SaveNoteOnLine) {
				cout << "Sorry! that note doesnt exist\n";
			}
			else {
				cout << Notes.at(PrintNote - 1) << endl;
			}
		}
		else if (input == "-delete") {
			cout << "what note do you want to delete, type -1 to cancel\n";
			cin >> PrintNote;
			if (PrintNote == -1) {
				//does nothing
			}
			else if (PrintNote > SaveNoteOnLine) {
				cout << "Sorry! that note doesnt exist\n";
			}
			else {
				Notes.erase(Notes.begin() + (PrintNote - 1));
				SaveNoteOnLine = SaveNoteOnLine - 1;
			}
			// saves the vector to the file
			if (rollback == false) {
				ofstream outFile("cmdnotes_data.txt");
				for (const auto &e : Notes) outFile << e << "\n";
				cout << "vector saved to file\n";
				outFile.close();
			}

		}
		else if (input == "-mknote") {
			getline(cin, input);
			Notes.push_back(input);
			cout << "saved on line " << SaveNoteOnLine + 1 << endl;
			SaveNoteOnLine++;
			//save the vector to file
			if (rollback == false) {
				ofstream outFile("cmdnotes_data.txt");
				for (const auto &e : Notes) outFile << e << "\n";
				cout << "vector saved to file\n";
				outFile.close();
			}
		}
		else if (input == "-help") {
			// lists the commands
			cout << "-exit: closes the program" << endl;
			cout << "-see: lets you print a specific note" << endl;
			cout << "-delete lets you delete a note" << endl; 
			cout << "-mknote: lets you make a new note" << endl;
			cout << "-transaction: starts a transaction allowing you to rollback changes" << endl;
			cout << "-commit: saves your changes in a transaction to file" << endl;
			cout << "-rollback: reverts your changes";
		}
		else if (input == "-transaction") {
			if (rollback == true) {
				cout << "there is already a transaction in progress\n";
			}
			else {
				cout << "transaction started\n";
				rollback = true;
			}
		}
		else if (input == "-commit") {
			if (rollback == false) {
				cout << "no transaction in progress\n"; 
			}
			else {
				// saves the vector to a file
				ofstream outFile("cmdnotes_data.txt");
				for (const auto &e : Notes) outFile << e << "\n";
				cout << "vector saved to file\n";
				outFile.close();
				rollback 
= false;
			}
		}
		else if (input == "-rollback") {
			// lets the user rollback there changes if they have a transaction
			if (rollback == false) {
				cout << "there is no transaction in progress\n";
			}
			else {
				// clears the vector then restores it from the file
				Notes.clear();
				// restores the vector from the file
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
				// tells other parts of the program that there isnt a transaction going on any more
				rollback = false;
			}
		}
		else {
			//do nothing
		}
	}
}
