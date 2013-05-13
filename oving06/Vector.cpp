 #include "Vector.h"
#include <cmath>


// Part 5-b: constructorssss
Vector::Vector() 
	: Matrix() {} //So that's what the syntax for calling the super's
	//constructor is in this language.

Vector::Vector(unsigned int nRows)
	: Matrix(nRows, 1) { }

Vector::Vector(const Matrix &other) 
	: Matrix() {
		// this is now an invalid matrix
		Matrix &m = *this; // remember that this is a pointer and & prefixing a variable name means it's a reference
		// in order to access Matrix's operator= we need to create
		// a Matrix object that's a reference to this vector.
		if (other.getWidth() == 1 || other.isValid()) {
			m = other;
			// which seems really weird I mean why can't I just
			//*this = other;
		}
}

// Part 5-d: dot, length and lengthsquared
double Vector::dot(const Vector &rhs) const {
	if (this->getHeight() != rhs.getHeight()) {
		return RAND_MAX; // lol.
	}
	double sum = 0;
	for (int i = 0; i < this->getHeight(); i++) {
		sum += this->getElement(i) * rhs.getElement(i);
	}
	return sum;
}

double Vector::lengthSquared() const {
	//A * A == |A|*|A|
	return this->dot(*this);
}

double Vector::length() const {
	// sqrt(|A|*|A|) = |A|
	return sqrt(this->lengthSquared());
}