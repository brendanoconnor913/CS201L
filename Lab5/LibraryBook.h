// Brendan O'Connor
// 2/22/16
// Lab #5

// Ensure class isn't added more than once
#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H

#include <string>
using namespace std;

// Write LibraryBook class here
class LibraryBook {
public:
	LibraryBook();
	LibraryBook(string title, string author, string ISBN);
	string getTitle();
	string getAuthor();
	string getISBN();
	void checkOut();
	void checkIn();
	bool isCheckedOut();
private:
	string m_title;
	string m_author;
	string m_ISBN;
	bool checkedOut;
};

// Define LibraryBook functions here


// This matches #ifndef at beginning of the file, so leave it in
#endif