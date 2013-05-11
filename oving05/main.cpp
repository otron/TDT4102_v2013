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
#include "Vector2.h"

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

	dicks *= herp;
	dicks.printMatrix();

	// Testing *operator
	printf("\nTesting *operator overloading\n");
	//dicks.printMatrix();
	cout << dicks;
	Matrix2x2 ident;
	dicks = dicks * ident;
	dicks.printMatrix();
	cout << dicks;

	// Part 2-e
	printf("\nBEHOLD: PART 2-E\n\n");
	Matrix2x2 A(1, 2, 3, 4);
	cout << "A\n" << A << endl;
	Matrix2x2 B(4, 3, 2, 1);
	cout << "B\n" << B << endl;
	Matrix2x2 C(1.0, 3.0, 1.5, 2.0);
	cout << "C\n" << C << endl;

	Matrix2x2 D;
	cout << "D = A + B\n";
	D = A + B;
	cout << D << endl;
	cout << "D = D * B - A + C\n";
	D = D * B - A + C;
	cout << D << endl;

	// Testing Part 3
	Vector2 vec;
	vec.setValue(3.4, 0);
	vec.setValue(5, 1);
	cout << vec;
	cin.get();
}

