// Brendan O'Connor
// 2/22/16
// Lab #5

#include "LibraryBook.h"
#include <string>
using namespace std;

// Define LibraryBook functions here

// initialize library book with blank values
LibraryBook::LibraryBook() {
	m_title = "";
	m_author = "";
	m_ISBN = "";
	checkedOut = false;
}

// initialize library book with passed parameters
LibraryBook::LibraryBook(string title, string author, string ISBN) {
	m_title = title;
	m_author = author;
	m_ISBN = ISBN;
	checkedOut = false;
}

// return the title
string LibraryBook::getTitle() {
	return m_title;
}

// return the author
string LibraryBook::getAuthor() {
	return m_author;
}

// return the isbn
string LibraryBook::getISBN() {
	return m_ISBN;
}

// tell us whether a book is checked in or not
void LibraryBook::checkOut() {
	checkedOut = true;
}

// change status of checked out to false
void LibraryBook::checkIn() {
	checkedOut = false;
}

// return value of checked out
bool LibraryBook::isCheckedOut() {
	return checkedOut;
}
