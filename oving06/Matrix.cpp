#include "Matrix.h"


// Part 2-b: Constructing the constructors.
Matrix::Matrix() {
	//The hint said something about using NULL pointers to indicate
	//that a matrix is invalid.
	//ooohhh.
	data = 0;
	columns = 0;
	rows = 0;
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
	if (rhs.isValid() == false) {
		this->invalidate();
		return *this;
	}

	// is the appropriate amount of memory already allocated?
	if (this->getHeight() != rhs.getHeight() || this->getWidth() != rhs.getHeight()) {
		this->rows = rhs.rows;
		this->columns = rhs.columns;
		this->data = new double[rows*columns];
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
	, data(0)
	{
		if (target.isValid() == false) {
			return; // that's all we need to do now;
			//we've already copied rhs' width and height.
		}
		//this->columns = target.columns;
		//this->rows = target.rows;
		// for valid ones, however, we need to copy the data from target to this.
		this->data = new double[rows*columns];
		for (unsigned int r = 0; r < rows; r++)
			for (unsigned int c = 0; c < columns; c++)
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

// Part 4-a
Matrix &Matrix::operator +=(const Matrix &rhs) {
	// we can't add two matrices together unless their sizes match up
	if (getHeight() != rhs.getHeight() || getWidth() != getHeight()) {
		// although the text doesn't specify what's to happen if this is the case.
		this->invalidate(); //eh.
		return *this;
	}
	// The matrices have the same dimensions so let's apply some addition.
	for (int r = 0; r < this->getWidth(); r++)
		for (int c = 0; c < this->getHeight(); c++) {
			this->setElement(this->getElement(r,c) + rhs.getElement(r,c),
				r, c);
			// hrm, that's cumbersome to type.
	}

}

double &Matrix::refToElement(int r, int c) const {

	return data[getPos(r, c)];
	// it's slightly confusing how I don't have to specify that
	// the return value is a reference inside the function's body.
}

bool Matrix::hasSameDimensions(const Matrix &other) const {
	if (this->getHeight() != other.getHeight() || this->getWidth() != other.getWidth()) {
		return false;
	}
	return true;
}

Matrix &Matrix::operator -=(const Matrix &rhs) {
	if (this->hasSameDimensions(rhs) == false) {
		this->invalidate();
		return *this;
	}
	for (int r = 0; r < this->getWidth(); r++)
		for (int c = 0; c < this->getHeight(); c++) {
			this->refToElement(r,c) -= rhs.getElement(r,c);
		}
}

// Part 4-b
Matrix Matrix::operator -(const Matrix &rhs) const {
	if (this->hasSameDimensions(rhs) == false)
		return Matrix();
	// Remember how we expanded that expression back in Vector2.cpp?
	Matrix m = Matrix(*this);
	m -= rhs;
	return m;
}

Matrix Matrix::operator +(const Matrix &rhs) const {
	if (this->hasSameDimensions(rhs) == false)
		return Matrix();
	Matrix m = Matrix(*this);
	m += rhs;
	return m;
}

Matrix Matrix::operator *(const Matrix &rhs) const {
	// matrix multiplication is only allowed with an MxN and NxP matrix.
	// The result is an MxP matrix.
	if (this->isValid() == false || this->getHeight() != rhs.getWidth()) {
		//the default constructor creates an invalid matrix.
		return Matrix();
	}
	Matrix m = Matrix(this->getWidth(), rhs.getHeight());
	int n = this->getHeight();
	for (int i = 0; i < m.getWidth(); i++) {
		for (int j = 0; j < m.getHeight(); j++) {
			double sum = 0;
			for (int r = 0; r < n; r++) {
				sum += this->getElement(i, r) * rhs.getElement(r, j);
			} //for r
			m.setElement(sum, i, j);
		} //for j
	} //for i
	return m;
}

// Part 4-c
Matrix &Matrix::operator *=(const Matrix &rhs) {
	return *this = (*this * rhs);
	//return *this;
}

// Part "this could be useful"
void Matrix::fill(double value) {
	for (int i = 0; i < rows*columns; i++)
		this->data[i] = value;
}