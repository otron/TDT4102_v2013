#ifndef VECTOR_H
#define VECTOR_H

#include "Matrix.h"

class Vector : public Matrix {
public:
	Vector(unsigned int nRows); // inits a nR x 1 0-matrix
	Vector(const Matrix &other);
		// copies the matrix if it is valid and has columns == 1

	// Part 5-c: get set radio future
	void setElement(double value, unsigned int row) {
		Matrix::setElement(value, row, 1);
	}
	double getElement(unsigned int row) const { 
		return Matrix::getElement(row, 1);
	}

	//Part 5-d: dot, length and lengthsquared
	double dot(const Vector &rhs) const;
	double lengthSquared() const;
	double length() const;

};

#endif