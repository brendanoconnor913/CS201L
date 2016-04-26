// Brendan O'Connor
// Lab 6
// 2.29.16

#ifndef _WORD
#define _WORD

#include <string>
using namespace std;

class Word {
public:
	Word();
	Word(string word);
	void increment();
	void setWord(string word);
	void setCount(int count);
	string getWord();
	int getCount();
private:
	string m_word;
	int m_wcount;

};

#endif