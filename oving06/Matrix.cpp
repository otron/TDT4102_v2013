#include "Matrix.h"


// Part 2-b: Constructing the constructors.
Matrix::Matrix() {
	//The hint said something about using NULL pointers to indicate
	//that a matrix is invalid.
	//ooohhh.
	data = 0;
}

// for some reason the keyword 'explicit' is only supposed to be
// used in the function's declaration, not in its definition.
// ...
Matrix::Matrix(unsigned int nRows) {
	// Should initialize an nR x nR identity matrix.
	rows = nRows;
	columns = nRows;
	data = new double[rows*columns];

	// set everything to 0.
	for (unsigned int i = 0; i < rows*columns; i++) {
		data[i] = 0;
	}
	// set the diagonal to 1.
	for (unsigned int i = 0; i < rows; i++) {
		setElement(1,i,i);
	}
}

Matrix::Matrix(unsigned int nR, unsigned int nC) {
	rows = nR;
	columns = nC;
	data = new double[rows*columns];
	for (unsigned int i = 0; i < rows*columns; i++)
		data[i] = 0;
}

int Matrix::getPos(int row, int column) const {
	return (rows*row + column);
}

// Part 2-c: gettin' & settin'
double Matrix::getElement(int row, int column) const {
	return this->data[getPos(row, column)];
}

void Matrix::setElement(double val, int row, int column) {
	this->data[getPos(row,column)] = val;
}

// Part 2-e: overloading <<
ostream &operator <<(ostream &outs, const Matrix &rhs) {
	if (!rhs.isValid()) { // if it's not valid we'll just get gibberish.
		outs << "Invalid matrix\n";
		return outs;
	}
	for (int i = 0; i < rhs.getHeight(); i++) {
		for (int j = 0; j < rhs.getWidth(); j++) {
			outs << rhs.getElement(i,j) << "\t";
			// we have to print it line by line,
			// which means 
		}
		outs << endl;
	}
	return outs;
}

// Part 3-a: the deepest of copies
Matrix &Matrix::operator =(const Matrix &rhs) {
	this->rows = rhs.getHeight();
	this->columns = rhs.getWidth();
	return *this;
}

