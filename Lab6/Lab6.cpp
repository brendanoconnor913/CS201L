#include <iostream>
#include <string>
#include <fstream>
#include "Word.hpp"
using namespace std;

void resizeArray(Word*& wlist, int& size) {
	Word* tmpArray = new Word[size * 2];

	for (int i = 0; i < size;i++) {
		tmpArray[i] = wlist[i];
	}

	size *= 2;
	delete [] wlist;
	wlist = tmpArray;
	tmpArray = NULL;
}

// Brendan O'Connor
// Lab 6
// 2.29.16

int main() {
	// declare/initialize all the variables we will need
	int arraysize = 10;
	int wordsinarray = 0;
	string word;
	Word* wlist = new Word[10];
	// get the files for input and output open
	ifstream fin;
	ofstream fout;
	fin.open("input.txt");
	fout.open("output.txt");

	// iterate through the entire file
	while (fin.eof() != true) {
		fin >> word;
		// insert first word because we know its not in list
		if (wordsinarray == 0) {
			Word tmpword(word);
			wlist[0] = tmpword;
			wordsinarray++;
		}
		// put each word into our list
		for (int k = 0; k < wordsinarray; k++) {
			if (word == wlist[k].getWord()) {
				wlist[k].increment();
				break;
			}
			// if word not found in array add word to array
			else if (k == wordsinarray - 1) {
				// resize if not array not big enough to add more
				if (wordsinarray == arraysize) {
					resizeArray(wlist, arraysize);
				}
				Word tmpword(word);
				wlist[wordsinarray] = tmpword;
				wordsinarray++;
			}
		}
	}

	// output word data
	fout << "Words found: " << wordsinarray << endl;
	fout << "Array's max size: " << arraysize << endl;
	fout << endl;
	// output each word with count to file
	for (int i = 0; i < wordsinarray; i++) {
		fout << wlist[i].getWord() << " - " << wlist[i].getCount() << endl;
	}



	fin.close();
	fout.close();
	return 0;
}