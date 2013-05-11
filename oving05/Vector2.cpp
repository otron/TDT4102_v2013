#include <cmath> // sqr and sqrt and stuff.
#include "Vector2.h"

namespace matrices {

using namespace std;
// Part 3-b
double Vector2::dot(const Vector2 &rhs) const {
	double res = 0;
	for (int i = 0; i < 2; i++) {
		res += rhs.data[i] * this->data[i];
	}
	return res;
}

double Vector2::length() const {
	// ooh that's clever.
	return (this->dot(*this));
	// harder to see when it's not in mathematic notation, though.
}

double Vector2::lengthSquared() const {
	return pow(length() ,2);
}

// Part 3-c
ostream &operator <<(ostream &outs, const Vector2 &rhs) {
	outs << "[" << rhs.data[0] << ", " << rhs.data[1] << "]\n";
	return outs;
}

// Part 3-e

Vector2 &Vector2::operator +=(const Vector2 &rhs) {
	data[0] += rhs.data[0];
	data[1] += rhs.data[1];
	return *this;
	// It's kind of weird that I have to dereference this before returning it.
}

Vector2 &Vector2::operator -=(const Vector2 &rhs) {
	data[0] -= rhs.data[0];
	data[1] -= rhs.data[1];
	return *this;
}

Vector2 Vector2::operator +(const Vector2 &rhs) const {
	/* oh now I get the Matrix2x2(*this) thing --
	 it's a call to the default copy constructor, not a cast!
	 because the function is postfixed by const, we can't
	 simply do this += rhs; because that would mean changing this.

	 Let's expand it:
	 1: return (Vector2(*this) += rhs);

	 Vector2 v = Vector2(*this);
	 v += rhs;
	 return v;

	*/
	Vector2 d = Vector2(*this);
	d += rhs;
	return d;
}

Vector2 Vector2::operator -(const Vector2 &rhs) const {
	Vector2 v = Vector2(*this);
	return v+=rhs;
}

Vector2 Vector2::operator -() const {
	Vector2 v(-data[0], -data[1]);
	return v;
}

} //namespace matrices