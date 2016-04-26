//Brendan O'Connor
//4/11/16
//Lab 10

#include "Word.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;



// Starting point
int main()
{
	// File I/O
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	

	// Create vector to store words
	vector<Word> wrdVec;
	// Create iterator for looping
	vector<Word>::iterator wV = wrdVec.begin();

	// Read in file
	string wordIn;
	// While there are more words
	while(fin.eof() != true)
	{
		fin >> wordIn;
		// It's not found by default
		bool found = false;
		
		// For each element in the array, if it exists, increment its count, and mark it as found
		for(wV; wV != wrdVec.end(); wV++)
		{
			if(wV->getWord() == wordIn)
			{
				wV->increment();
				found = true;
				// Quit for loop early
				break;
			}
		}

		// If not found, add it. If array is full, resize it first.
		if(!found)
		{
			Word w(wordIn);
			w.increment();
			wrdVec.push_back(w);
		}
		wV = wrdVec.begin();
	}

	// Print list of words and counts

	fout << "Words found: " << wrdVec.size() << endl;

	// For each word, print it's word/count pair.
	for (wV; wV != wrdVec.end(); wV++)
	{
		fout << wV->getWord() << " - " << wV->getCount() << endl;
	}
}

