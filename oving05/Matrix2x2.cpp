#include "Matrix2x2.h"

namespace matrices {

	void Matrix2x2::setValue(double value, int row, int column) {
		//printf("Setting (%i,%i)[%i] to %f\n", row, column, getPos(row, column), value);
		this->data[getPos(row, column)] = value;
	}

	const double Matrix2x2::getValue(int row, int column) {
		return this->data[getPos(row, column)];
	}

	int Matrix2x2::getPos(int row, int column) {
		return (row*2 + column);
		/* Because:
			0,0 => 0*2 + 0 = 0
			0,1 => 0*2 + 1 = 1
			1,0 => 1*2 + 0 = 2
			1,1 => 1*2 + 1 = 3
			a more general version would be
			row*(column size) + column
		*/
	}

	void Matrix2x2::printMatrix() {
		printf("%f\t%f\n%f\t%f\n",
			data[0], data[1], data[2], data[3]);
	}

	// Part 1-d
	Matrix2x2::Matrix2x2() {
		//the default constructor should init the matrix to the identity matrix
		data[0] = 1;
		data[1] = 0;
		data[2] = 0;
		data[3] = 1;
	}

	// Part 1-e
	Matrix2x2::Matrix2x2(double a, double b, double c, double d) {
		data[0] = a;
		data[1] = b;
		data[2] = c;
		data[3] = d;
	}
	Matrix2x2::Matrix2x2(double arr[]) {
		for (int i = 0; i < 4; i++) {
			data[i] = arr[i];
		}
	}

	// Part 2-a

	Matrix2x2 &Matrix2x2::operator+=(const Matrix2x2 &rhs) {
		for (int i = 0; i < 4; i++) {
			this->data[i] += rhs.data[i];
		}
		return *this;
		/* The return thing works because writing
		 A += B
		 causes the overloaded operator to be called on A
		 which then adds B's values to A's
		 and then A is returned (this is a pointer,
		 *this dereferences it) which means A is set to
		 itself.
		*/
	}

	Matrix2x2 &Matrix2x2::operator-=(const Matrix2x2 &rhs) {
		for (int i = 0; i < 4; i++)
			this->data[i] -= rhs.data[i];
		// How am I allowed to do rhs.data[]?
		// That's supposed to be a private member variable.
		// I haven't gotten the hang of that yet.
		return *this;
	}

	// Part 2-b
	Matrix2x2 Matrix2x2::operator +(const Matrix2x2 &rhs) const {
		/* const at the end of a function means we can't
		 alter member variables inside the function
		 unless they're tagged as mutable.
		 
		 Tagging a paramater with const means we're not
		 allowed to change it within the function body.
		*/
		 return Matrix2x2(*this) += rhs;
	}

	Matrix2x2 Matrix2x2::operator -(const Matrix2x2 &rhs) const {
		return Matrix2x2(*this) -= rhs;
		// That is some pretty gay shit
		// having to write Matrix2x2(*this) -= rhs;
		// to get it to compile.
	}

	Matrix2x2 Matrix2x2::operator *(const Matrix2x2 &rhs) const {
		Matrix2x2 res;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				/* (AB)_ij = \sum_{k=1}^{m} A_{ik}B_{kj}
				 where A is NxM and B is MxP
				 since they're both 2x2, everything just becomes 2.
				 damned magic numbers.
				 more like balls, am I right or am I a potato?
				*/
				double d = 0.0;
				for (int k = 0; k < 2; k++) {
					d += this->data[i*2+k] * rhs.data[k*2+j];
				}
				// Right, so I can only call const methods on a const object.
				// But I CAN just access their private member variables directly
				// ooh but that's okay because they're const so I can't change anything!
				// still I am bummed out that getValue() doesn't work unless I write
				// Matrix2x2(this)->getValue()
				// I mean, come on.
				res.setValue(d, i, j);
				// I like it when the notation matches up like that.
			}
		}
		return res;
	}

	// Part 2-c
	Matrix2x2 &Matrix2x2::operator *=(const Matrix2x2 &rhs) {
		/* Q: Can I reuse code I have used earlier?
			A: Yes: See below.
		   Q: Why can we not implement *= the same way += and -=
		   		were implemented?
		   	A: Because * uses the matrices values more than once.
		*/
		*this = *this * rhs;
		return *this;
	}
	/* A note on const and &:
	  * const prefixing a parameter:
	  	the variable is considered a constant within
	  	the function's body. I assume it can't be passed
	  	as a non-const to another function then.

	  * const postfixing a function:
	  	Only applicable to member functions.
	  	Means altering member variables is not permitted
	  	within the function body, excepting member variables
	  	tagget with mutable.

	  * & prefixing a function
	  	Means the return type of the function is a reference.
	  	'this' is dereferenced in the += and -= operator overloadings
	  	because of, uh... reasons?

	  * & prefixing a paramater
	  	Means the paramater is passed as a reference.
	  	Also known as "call by reference": changes made on the
	  	parameter within the function are applied to the variable,
	  	because it's not just a copy.

	*/

	// Part 2-d
	std::ostream& operator <<(std::ostream& outs, const Matrix2x2 &rhs) {
		// just keep <<'ing stuff into outs.
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				outs << rhs.data[i*2+j] << "\t";
			}
			outs << std::endl;
		}
		return outs;
		// << has to return an ostream otherwise
		// we can't chain <<.
	}

	// Part 4-a
	

}
