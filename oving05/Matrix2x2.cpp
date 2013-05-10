#include "Matrix2x2.h"

namespace matrices {

	void Matrix2x2::setValue(double value, int row, int column) {
		//printf("Setting (%i,%i)[%i] to %f\n", row, column, getPos(row, column), value);
		this->data[getPos(row, column)] = value;
	}

	double Matrix2x2::getValue(int row, int column) {
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
}
