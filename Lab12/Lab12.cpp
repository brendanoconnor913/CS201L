// Brendan O'Connor	
// 4/25/16
// Lab 12

#include <string>
#include <list>
#include <fstream>
#include <iostream>
using namespace std;

// use this function to fill the list that is passed with all the characters in the string passed
void fillList(list<char>& charlist, string stringadd) {
	string::iterator strItr = stringadd.begin();
	for (strItr; strItr != stringadd.end();strItr++) {
		char charinst = *strItr;
		charlist.push_back(charinst);
	}
}

// print all of the characters in the list
void printList(list<char> charlist, ostream& out) {
	list<char>::iterator charItr = charlist.begin();
	if (charlist.size() == 0) {
		out << 0;
	}
	else {
		for (charItr; charItr != charlist.end(); charItr++) {
			out << "[" << *charItr << "] -> ";
		}
		out << "0";
	}
}

// remove the character passed from the list passed
void removeCharacter(list<char>& charlist, char rmchar) {
	list<char>::iterator charItr = charlist.begin();
	if (!(charlist.size() == 0)) {
		for (charItr; charItr != charlist.end(); charItr++) {
			if (*charItr == rmchar) {
				charlist.erase(charItr);
				if (charlist.size() == 0) {
					break;
				}
				charItr = charlist.begin();
			}
		}
	}
}

int main() {
	// load files for io
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string input;
	string vowels = "aeiouAEIOU"; // used to remove from strings passed in
	while (fin.eof() != true) {
		getline(fin, input);
		if (input == "END") {
			break;
		}
		// create a list with each string passed then remove all vowels from the strings
		list<char> charlist;
		string::iterator strItr = vowels.begin();
		fillList(charlist, input);
		for (strItr; strItr != vowels.end(); strItr++) {
			removeCharacter(charlist, *strItr);
		}
		printList(charlist, fout); // output result
		fout << endl;
		fout << endl;
	}
	return 0;
}