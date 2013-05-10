#ifndef MATRIX2X2_H
#define MATRIX2X2_H

namespace matrices {

class Matrix2x2 {
	private:
		double data[4];
		int getPos(int row, int column);
	public:
		void setValue(double value, int row, int column);
		double getValue(int row, int column);
};

// tests
bool testMatrix2x2Get(Matrix2x2 test, double arr[]);
bool testMatrix2x2Set(Matrix2x2 test);
}




#endif /* MATRIX2X2_H_ */
