// Brendan O'Connor
// 4/4/2016
// Lab 9
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

string quineTester(string line) {
	string A = "";
	string B = "";
	string F = "";
	int qcount = 0;
	int i = 0;
	
	// Don't try to work with the examples that break my code
	if (line[i] != '"' || line == "\"\"") {
		return "";
	}
	
	// Get the string inbetween the two quotes
	while (qcount < 2){
		if (line[i] == '"'){
			qcount++;
			i++;
			continue;
		}
		A += line[i];
		i++;
	}

	// Get the string after the quotes
	while (i < line.length()) {
		B += line[i];
		i++;
	}
	// Remove the space from B
	for (int i = 1; i < B.length(); i++) {
		F += B[i];
	}
	// Use the string without the space for comparison
	B = F;
	// Remove more cases that break the quine rules
	if (A[0] == ' ' || A[A.length() - 1] == ' ' || A == "") {
		return "";
	}
	// See if the strings match
	if (A == B) {
		return A;
	}
	else {
		return "";
	}
}

int main() {
	ifstream fin("inputname.txt");
	ofstream fout("outputname.txt");
	
	string line;
	string result;
	while (fin.eof() != true){
		getline(fin, line);
		// Dont check the last line
		if (line == "END") {
			break;
		}
		
		result = quineTester(line);
		if (result == "") {
			fout << "not a quine" << endl;
		}
		else {
			fout << "Quine(" + result + ")" << endl;
		}
	}

	return 0;
}

