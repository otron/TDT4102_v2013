#include "Matrix.h"
#include "Vector.h"
#include <iostream> // cout
#include <time.h> // time
#include <stdlib.h> //srand, rand

using namespace std;
void matrixTests();
void testFour();
void testSix();

int main() {
	//matrixTests();
	//testFour();
	testSix();
	
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

// Part 4-d
void testFour() {
	Matrix A = Matrix(2,2), B = Matrix(2,2), C = Matrix(2,2);
	double d = 1;
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++) {
			A.setElement(d, i, j);
			B.setElement(5-d, i, j);
			d++;
		}
	C.setElement(1.0, 0, 0);
	C.setElement(3.0, 0, 1);
	C.setElement(1.5, 1, 0);
	C.setElement(2.0, 1, 1);

	Matrix D = Matrix(2,2);
	cout << A-B; // OK!
	D = A+B;
	cout << D << endl;
	D = A*B;
	D *= B;
	D -= A;
	D += C;
	cout << D << endl;
	cout << "Data entry is boring. I don't know what this is supposed to equal.\n";
}

// Part 6: Understanding what you have done.
// YOU FOOL! YOU HAVE UNLEASHED THE STRENGTH OF OBJECT ORIENTED PROGRAMMING!
void testSix() {
	srand(time(0));
	Matrix m = Matrix(4,4);
	Vector v = Vector(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			double d = (rand() / RAND_MAX) * 10;
			m.setElement(d, i, j);
		}
		double d = (rand() / RAND_MAX) * 10;
		v.setElement(d, i);
	}
	cout << "The matrix\n" << m << "\nThe vector\n" << v << endl;

	cout << "The result!\n" << m*v;
}