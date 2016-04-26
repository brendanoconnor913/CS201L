// Brendan O'Connor
// Lab 6
// 2.29.16

#include "Word.hpp"
#include <string>
using namespace std;

// initialize to default elements if no string given
Word::Word() {
	m_word = "";
	m_wcount = 0;
}

// if string passed set it to m_word
Word::Word(string word) {
	m_word = word;
	m_wcount = 0;
}

// add 1 to the word count
void Word::increment() {
	m_wcount += 1;
}

// set the word
void Word::setWord(string word) {
	m_word = word;
}

// set the count
void Word::setCount(int count) {
	m_wcount = count;
}

// get the word 
string Word::getWord() {
	return m_word;
}

// get the count
int Word::getCount() {
	return m_wcount;
}