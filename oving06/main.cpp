#include "Matrix.h"
#include <iostream>
using namespace std;
void matrixTests();

int main() {
	matrixTests();
	
	cin.get();
}

// Part 2-f
// Test the three constructors. Test yo functions. Test yo attitude.
void matrixTests() {
	Matrix neo; // default constructor, should be invalid.
	cout << "Default constructor\n" << neo;

	Matrix morph = Matrix(4); // identity matrix
	Matrix trin = Matrix(2,5); // 2x5 matrix with 0 in all places

	cout << "4x4 Identity matrix\n" << morph << endl;

	cout << "2x5 0 matrix\n" << trin << endl;

	// As the << overloading makes use of getElement and the NxN 
	// constructor makes use of setElement, I'll go ahead and assume
	// my member functions work as intended if the tests are a-go.

	// I could write some proper tests here, that check the values
	// of each cell in each matrix, but that is sadly outside the course's
	// curriculum so I'm just making this note of it.


}