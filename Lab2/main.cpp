// Brendan O'Connor
// 2-1-16
// The purpose of this lab is to create a program to calculate the distance between two points in three dimensional space.

#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;

double calcDistance(double x1, double y1, double z1, double x2, double y2, double z2) {
	// A fucntion to take 6 parameters (coordiantes of 2 points in 3d space) and calculate the distance	
	double distance;
	// To simplify we will store the delta of each coordiante before calculating distance.
	double dx;
	double dy;
	double dz;

	dx = x1 - x2;
	dy = y1 - y2;
	dz = z1 - z2;

	distance = pow((dx*dx + dy*dy + dz*dz), (.5));	

	return distance;
};

int main() {
	// Create input and output file variables
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	// Create arrays to store coordiante info to be used for calcing distance
	
	int filelength = 0;
	double x;
	// Getting the lenth of the file
	while (!fin.eof()) {
		fin >> x;
		filelength += 1;
	}

	int points = filelength / 6;

	// declaring arrays
	double xcords[40];
	double ycords[40];
	double zcords[40];

	int point = 0;
	int ir;

	// entering in each point into the array
	for (int i = 0; i < filelength; i++) {
		ir = i % 3;
		switch (ir){
		case 0:
			fin >> xcords[point];
			cout << xcords[point] << endl;
			break;
		case 1:
			fin >> ycords[point];
			cout << ycords[point] << endl;
			break;
		case 2:
			fin >> zcords[point];
			cout << zcords[point] << endl;
			break;
		}
		
		if (ir == 2) {
			point++;
		}
	}

	// calculating distance from arrays
	for (int i = 0; i < 20; i += 2){
		fout << calcDistance(xcords[i], ycords[i], zcords[i], xcords[i+1], ycords[i+1], zcords[i+1]);
	}
	

	system("pause");
	return 0;
};