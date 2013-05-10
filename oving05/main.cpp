/*
 * main.cpp
 *
 *  Created on: 10. mai 2013
 *      Author: Odd
 */

#include <time.h> // time
#include <stdlib.h> //srand, rand
#include <stdio.h> //printf?
#include <iostream> //cin, cout
#include <string> //strings
 #include <sstream> //string streams

#include "main.h"
#include "Matrix2x2.h"

using namespace std;
using namespace matrices;

int main() {
	srand(time(0)); // seed the randomizationizer

	for (int i = 0; i < 10; i++) {
		cout << ((double) rand() / (double) RAND_MAX) * (double) rand();
		cout << endl << endl;
	}

	// code to test 2-a and b
	cin.get();
}

string testMatrix2x2Set(Matrix2x2 test) {
	//assumes the get-function works,
	//as we don't have direct access to matrix2x2 private members
	double dat[4];
	for (int i = 0; i < 4; i++) {
		dat[i] = ((double) rand() / (double) RAND_MAX) * (double) rand();

	}
	return "";
}
string testMatrix2x2Get(Matrix2x2 test, double arr[]) {
	string res = ""; // I wonder what the default constructor for string does.
	bool failure = false;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			if (test.getValue(i, j) != arr[i*2+j]) {
				failure = true;
				stringstream ss;
				ss << "(" << i << "," << j << ") was ";
				ss << test.getValue(i, j) << " but should be " << arr[i*2+j];
				ss << endl;
				res += ss.str();
			}
		}
	}
	if (!failure)
		res += "getValue seems to be working.\n";
	return res;
}

