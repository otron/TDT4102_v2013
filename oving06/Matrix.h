#ifndef MATRIX_H
#define MATRIX_H

#include <iostream> //ostream
using namespace std;

// Part 2
// "Dynamic variables are created and destroyed while the program is running."
class Matrix {
private:
	unsigned int rows, columns; //that's how I'll store the dimensions.
	double* data; //who needs doublepointers man those things are wack anyway.
	int getPos(int r, int c) const; //converts i,j to a position in data
	double &refToElement(int r, int c) const;
	bool hasSameDimensions(const Matrix &other) const; // returns true if other and this have equal rows and columns
public:
	// Part 2-b: Constructing the constructors.
	Matrix();
		//Default constructor, should initialize the matrix into the invalid state.
	explicit Matrix(unsigned int nRows);
		/*Should construct a valid nRows x nRows Matrix, init'd as an identity
		  matrix. While the explicit keyword is not in the syllabus,
		  it is used here...
		
			explicit prevents implicit type conversion like this guy on
			stackoverflow explains: http://stackoverflow.com/questions/121162/what-does-the-explicit-keyword-in-c-mean
		*/
	Matrix(unsigned int nR, unsigned int nC);
		// should construct a valid nR x nC Matrix, init'd as a Zero matrix.
	~Matrix() {
		if (data)
			delete data;
	} //The destructor. Should delete any dynamically allocated memory.

	// Part 2-c: gettin' & settin'
	void setElement(double val, int row, int column);
	double getElement(int row, int column) const;
	int getHeight() const { return rows; }
	int getWidth() const { return columns; }

	// Part 2-d: validation
	bool isValid() const {return (data == 0 ? false : true); }

	// Part 2-e: overloading <<
	friend ostream &operator <<(ostream &outs, const Matrix &rhs);
	//the 'friend' keyword is used before functions placed inside
	// a class that aren't member functions, yet for some reason
	// could use access to the class' private members.

	// Part 3: the deepest of copies
	Matrix &operator =(const Matrix &rhs);
	Matrix(const Matrix &target); // copy constructor.
	void invalidate(); //wait should this even be public?

	// Part 4: Overloading operators.
	// Part 4-a
	Matrix &operator +=(const Matrix &rhs);
	Matrix &operator -=(const Matrix &rhs);

	// Part 4-b
	Matrix operator -(const Matrix &rhs) const;
	Matrix operator +(const Matrix &rhs) const;
	Matrix operator *(const Matrix &rhs) const;
};

#endif 