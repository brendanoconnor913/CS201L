// Brendan O'Connor
// 4/18/16
// Lab 11

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// function swaps object at pos1 with pos2
template < class T > 
void mySwap(T ary[], int pos1, int pos2) {
	T v1 = ary[pos1];
	T v2 = ary[pos2];
	ary[pos1] = v2;
	ary[pos2] = v1;
}

// gets the minimum object in the array
template<class T>
T myMin(T ary[]) {
	T min;
	
	min = ary[0];
	for (int i = 0; i < 100; i++) {
		if (ary[i] < min) {
			min = ary[i];
		}
	}
	return min;
}

// gets the maximum object in the array
template<class T>
T myMax(T ary[]) {
	T max;
	max = ary[0];
	for (int i = 0; i < 100; i++) {
		if (ary[i] > max) {
			max = ary[i];
		}
	}
	return max;
}

// searches array and returns index of first object matching search
template<class T>
int mySearch(T ary[], T search) {
	int index = -1;
	for (int i = 0; i < 100; i++) {
		if (ary[i] == search) {
			index = i;
			break;
		}
	}
	return index;
}

int main() {
	// open all the input and output files
	ifstream fint("integers.txt");
	ifstream fdubs("doubles.txt");
	ifstream fstr("strings.txt");
	ofstream fout("output.txt");
	// initialize all the arrays we will use
	int intArray[100];
	double dblArray[100];
	string strArray[100];
	// fill all of the arrays
	for (int i = 0; i < 100; i++) {
		fint >> intArray[i];
	}
	for (int i = 0; i < 100; i++) {
		fdubs >> dblArray[i];
	}
	for (int i = 0; i < 100; i++) {
		fstr >> strArray[i];
	}

	// provide the output requested for each data type
	fout << "Integers:" << endl;
	fout << "Swapped items at positions 10 and 20" << endl;
	fout << "Before: [10] " << intArray[10] << " [20] " << intArray[20] << endl;
	mySwap(intArray, 10, 20);
	fout << "After: [10] " << intArray[10] << " [20] " << intArray[20] << endl;
	fout << "Minimum: " << myMin(intArray) << endl;
	fout << "Maximum: " << myMax(intArray) << endl;
	fout << "The number 1 is at position " << mySearch(intArray, 1) << endl;;
	fout << "The number 5 is at position " << mySearch(intArray, 5) << endl;
	fout << endl;

	fout << "Doubles:" << endl;
	fout << "Swapped items at positions 10 and 20" << endl;
	fout << "Before: [10] " << dblArray[10] << " [20] " << dblArray[20] << endl;
	mySwap(dblArray, 10, 20);
	fout << "After: [10] " << dblArray[10] << " [20] " << dblArray[20] << endl;
	fout << "Minimum: " << myMin(dblArray) << endl;
	fout << "Maximum: " << myMax(dblArray) << endl;
	fout << "The number 4.62557 is at position " << mySearch(dblArray, 4.62557) << endl;;
	fout << "The number 1.23456 is at position " << mySearch(dblArray, 1.23456) << endl;
	fout << endl;

	fout << "Strings:" << endl;
	fout << "Swapped items at positions 10 and 20" << endl;
	fout << "Before: [10] " << strArray[10] << " [20] " << strArray[20] << endl;
	mySwap(strArray, 10, 20);
	fout << "After: [10] " << strArray[10] << " [20] " << strArray[20] << endl;
	fout << "Minimum: " << myMin(strArray) << endl;
	fout << "Maximum: " << myMax(strArray) << endl;
	string s1 = "Shoes";
	string s2 = "Pumpkin";
	fout << "The word Shoes is at position " << mySearch(strArray, s1) << endl;;
	fout << "The word Pumpkin 5 is at position " << mySearch(strArray, s2) << endl;
	fout << endl;

	return 0;
}