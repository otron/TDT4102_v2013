 #include "Vector.h"
#include <cmath>


// Part 5-b: constructorssss
Vector::Vector(unsigned int nRows)
	: Matrix(nRows, 1) { }

Vector::Vector(const Matrix &other) {
		if (other.getWidth() != 1)
			throw invalid_argument("Cannot create with vector COLS != 1");
		Matrix &m = Matrix(other);
		*this = m;
		// which seems really weird I mean why can't I just
		//*this = other;
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