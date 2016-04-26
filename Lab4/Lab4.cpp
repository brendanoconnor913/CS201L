// Brendan O'Connor
// 2/15/16
// Lab #4

#include <cmath>
#include <iostream>
#include <fstream>
#include "Point.h"

using namespace std;


int main()
{
    // File input/output variables
	ifstream fin("input.txt");
	ofstream fout("output.txt");

    // If we can't find the input file, quit with error message.
	if(!fin)
	{
		cout << "Input file not opened!" << endl;
		exit(1);
	}

	// Construct an array of 20 points
	Point set[20];
	double x;
	double y;
	double z;
	int k = 0;

	// Store all of the points in the set (the array of points)
	while (fin >> x >> y >> z){
		set[k].setCoordinates(x, y, z);
		k++;
	}

	// Loop through each point and output it's distance from the origin
	fout << "Distance from origin:" << endl;
	for (int i = 0; i < k; i += 2){
		fout << set[i].calcDistance() << " " << set[i + 1].calcDistance() << endl;
	}
	fout << endl;

	// Loop through each point and calculate the distance from the next point in file
	fout << "Distances from each other:" << endl;
	for (int i = 0; i < k; i += 2){
		fout << set[i].calcDistance(set[i+1]) << endl;
	}


    // Close our files to ensure we save our data
	fin.close();
	fout.close();

    // End program
	return 0;
}

