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
		double getValue(int row, int column);
		void printMatrix();
		//couldn't figure out how to test set/get without direct access to the data
};

}




#endif /* MATRIX2X2_H_ */
