/*
 * main.cpp
 *
 *  Created on: 10. mai 2013
 *      Author: Odd
 */

#include <time.h> // time
#include <stdlib.h> //srand, rand

#include "main.h"
#include "Matrix2x2.h"

using namespace std;
using namespace matrices;

int main() {
	srand(time(0)); // seed the randomizationizer

	// Part 1-c.
	// "Test the code you've written so far by creating
	// a 2x2 matrix and printing it to the console."
	printf("Part 1-c: Does the matrix thing work?\n");
	Matrix2x2 dicks;
	dicks.printMatrix();
	cout << endl;
	dicks.setValue((double) 3, 0,0);
	dicks.setValue((double) -1, 0,1);
	dicks.setValue((double) 0, 1,0);
	dicks.setValue((double) 5, 1,1);
	// dicks should now be [[3, -1],[0,5]
	dicks.printMatrix();
	cout << endl;
	double pew[] = {-1.0, 2.0, 15.0, -0.3};
	Matrix2x2 herp(pew);
	dicks += herp;
	dicks.printMatrix();

	// Testing *operator
	printf("\nTesting *operator overloading\n");
	dicks.printMatrix();
	Matrix2x2 ident;
	dicks = dicks * ident;
	dicks.printMatrix();
	cin.get();
}

