#ifndef MATRIX2X2_H
#define MATRIX2X2_H

#include <iostream> //cin, cout
#include <string> //strings
#include <sstream> //string streams
#include <stdio.h> //printf?

namespace matrices {

class Matrix2x2 {
	private:
		double data[4];
		int getPos(int row, int column);
	public:
		void setValue(double value, int row, int column);
		const double getValue(int row, int column);
		void printMatrix();
		Matrix2x2();
		Matrix2x2(double a, double b, double c, double d);
		Matrix2x2(double arr[]);

		//Overloading them operators, yo.
		// Part 2-a
		Matrix2x2 &operator +=(const Matrix2x2 &rhs);
		Matrix2x2 &operator -=(const Matrix2x2 &rhs);
		// Part 2-b
		Matrix2x2 operator +(const Matrix2x2 &rhs) const;
		Matrix2x2 operator -(const Matrix2x2 &rhs) const;
		Matrix2x2 operator *(const Matrix2x2 &rhs) const;
		// wait why is there a & preceding operator in
		// the declaration of += but not +?
		// it means it returns a reference to a private member.
		// Perhaps to avoid copying it?
		// Man, suddenly pointers and references and shit.
		// I'm don't feel ready for this.

		// Part 2-c
		Matrix2x2 &operator *=(const Matrix2x2 &rhs);

		// Part 2-d
		friend std::ostream& operator <<(std::ostream& outs, const Matrix2x2 &rhs);

};

}




#endif /* MATRIX2X2_H_ */
