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

int Matrix::getPos(int r, int c) const {
	return (rows*r + c);
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
	if (!rhs.isValid) {
		this->invalidate();
		return *this;
	}

	// is the appropriate amount of memory already allocated?
	if (this->getHeight() != rhs.getHeight() || this->getWidth() != rhs.getHeight()) {
		this->rows = rhs.rows;
		this->columns = rhs.columns;
		this->data = new double*[rows*columns];
	}

	// all right then now to copy the values from rhs over to this
	for (int i = 0; i < this->getHeight(); i++) {
		for (int j = 0; j < this->getWidth(); j++) {
			this->setElement(rhs.getElement(i,j), i, j);
			// copy those values over B-)
		}
	}
	// The copying could be done with just one for-loop
	// iterating over data directly. But then what's the point of
	// all this encapsulation if it's never used?
	// the compiler and/or preprocessor should take care of it anyway.
	return *this;
}

Matrix::Matrix(const Matrix &target)
	//here's a new thing I just found out about: list initialization.
	: rows(target.rows)
	, columns(target.columns)
	{
		if (!target.isValid) {
			this->data = 0;
			return; // that's all we need to do for invalid matrices.
		}
		// for valid ones, however, we need to copy the data from target to this.
		this->data = new double*[rows*columns];
		for (int r = 0; r < rows; r++)
			for (int c = 0; c < columns; c++)
				setElement(target.getElement(r,c), r, c);
	// aand that's it.
}

// invalidates a matrix.
void Matrix::invalidate() {
	if (this->data)
		delete data;
	this->rows = 0;
	this->columns = 0;
}

