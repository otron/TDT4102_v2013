#ifndef VECTOR2_H
#define VECTOR2_H

#include <iostream> //ostream

namespace matrices {
	// I don't even remember why I began using namespaces in the first place.
using namespace std;
//see it's even messing with my indentation: I'm starting class declarations
//with the same indentation as the namespace
class Vector2 {
	// Part 3-a: Create a class Vector2 that holds a
	// two-dimensional mathematical vector.
	// So... double [2] is sufficient.
	// That's some less than optional wording.
	// Part 3-a continued: also create getters and setters!
private:
	double data[2];
public:
	void setValue(double value, int index) {
		data[index] = value;
	}
	double getValue(int index) {
		return data[index];
	}
	// that's right, we're doing this in the header now.
	Vector2() {
		data[0] = 0;
		data[1] = 0;
	}
	Vector2(double one, double two) {
		data[0] = one;
		data[1] = two;
	}
	// Part 3-b
	// should return the dot product between this and rhs
	double dot(const Vector2 &rhs) const;
	// returns the length of the vector, squared.
	double lengthSquared() const;
	// returns the length of the vector
	double length() const;
	// Do you see how these three've got const after them?
	// that means they can't alter member variables.

	// Part 3-c
	friend ostream &operator <<(ostream &outs, const Vector2 &rhs);

	// Part 3-e
	// Overload the +=, -=, +, - and unary - operators for Vector2.

	Vector2 &operator +=(const Vector2 &rhs);
	Vector2 &operator -=(const Vector2 &rhs);

	Vector2 operator +(const Vector2 &rhs) const;
	Vector2 operator -(const Vector2 &rhs) const;

	Vector2 operator -() const; // Unary minus


};

}

#endif
