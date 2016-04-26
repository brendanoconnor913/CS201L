// Brendan O'Connor
// 2/22/16
// Lab #5

#include "LibraryBook.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
	// File stream variables
    ifstream finBooks("books.txt");
	ifstream finISBN("isbns.txt");
	ofstream fout("checkedout.txt");

	// Check for file errors first
	if(!finBooks || !finISBN)
	{
		cout << "Error opening input files!\n";
		system("pause");
		return 1;
	}


    // Initalize needed variables and librarybook array
	LibraryBook library[15];
	int i = 0;
	string title;
	string author;
	string ISBN;

	// Read all the data into their respective arrays
	while (!finBooks.eof()) {
		getline(finBooks, title);
		getline(finBooks, author);
		getline(finBooks, ISBN);
		library[i] = LibraryBook(title, author, ISBN);
		i++;
	}


	// For each isbn in isbn input switch status of checked out
	string ISBNline;
	while (!finISBN.eof()) {
		finISBN >> ISBNline;
		for (int i = 0; i < 15; i++) {
			if (library[i].getISBN() == ISBNline) {
				if (library[i].isCheckedOut() == true) {
					library[i].checkIn();
				}
				else {
					library[i].checkOut();
				}
			}
		}
	}

	// Make report
	fout << "Books checked out:" << endl;
	fout << "-------------------" << endl;
	fout << endl;
	fout << "Title \t Author \t ISBN" << endl;
	for (int i = 0; i < 15; i++) {
		if (library[i].isCheckedOut()) {
			fout << library[i].getTitle() << "\t" << library[i].getAuthor() << "\t" << library[i].getISBN() << endl;
		}
	}

	// Close the files at the end
	finBooks.close();
	finISBN.close();
	fout.close();

    // End program
	return 0;
}
