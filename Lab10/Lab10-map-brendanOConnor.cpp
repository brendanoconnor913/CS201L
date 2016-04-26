//Brendan O'Connor
//4/11/16
//Lab 10

#include "Word.h"
#include <fstream>
#include <iostream>
#include <string>
#include <map>
using namespace std;



// Starting point
int main()
{
	// File I/O
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	

	// Create map to store words
	map<string, int> wrdMap;
	// Create iterator for looping
	map<string, int>::iterator wM = wrdMap.begin();

	// Read in file
	string wordIn;
	// While there are more words
	while(fin.eof() != true)
	{
		fin >> wordIn;
		if (wrdMap[wordIn] >= 0) {
			wrdMap[wordIn]++;
		}
		else {
			wrdMap.insert(pair<string, int>(wordIn, 1));
		}
		wM = wrdMap.begin();
	}

	// Print list of words and counts

	fout << "Words found: " << wrdMap.size() << endl;

	wM = wrdMap.begin();
	// For each word, print it's word/count pair.
	for (wM; wM != wrdMap.end(); wM++)
	{
		fout << wM->first << " - " << wM->second << endl;
	}
}

