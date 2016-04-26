#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main() {
	// create the files to open the input and output in
	ifstream fin;
	ofstream fout;

	// open the files
	fin.open("input.txt");
	fout.open("output.txt");

	
	// while loop executes until the end of the document reached
	while (fin.good()) {
		// get the dimensions of the matrix
		int x;
		int y;
		fin >> x;
		fin >> y;
		fout << x << " " << y << endl;
	
		// construct the arrays for the matrix
		int m1[20][20];
		int m2[20][20];

		// input all of the values of the first matrix into m1
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				fin >> m1[i][j];
			}
		}

		// input all of the values of the second matrix into m2
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				fin >> m2[i][j];
			}
		}

		// Add each entry at index i,j of both matrixes and output to the file
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				int sum = m1[i][j] + m2[i][j];
				fout << sum << " ";
			}
			fout << endl;
		}
	
		fout << endl;
	}


	// close files
	fin.close();
	fout.close();

	return 0;
}
