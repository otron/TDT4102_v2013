#include <stdio.h> // NULL, printf, some other stuff
#include <math.h>
#include <cmath> // ????

#include "oving02.h"

int findLargestPrimeFac_bVal(int input) {
	int counter = input/2; //integer division is automagically 'floored'
	while (counter > 1) {
		if (input % counter == 0)
			if (findLargestPrimeFac_bVal(counter) == 1) {
				//we are only supposed to return prime numbers
				//this could be optimized a great deal.
				return counter;
			}
		counter--;
	}
	return counter; // it's prime, jim.
}

void findLargestPrimeFac_bRef(int &input) {
	input = findLargestPrimeFac_bVal(input);
	//ha-ha.
}

void testEight() {
	int test = 8;
	printf("Testing Part 8 \n");
	printf("%i >> %i\n", test, findLargestPrimeFac_bVal(test));
	test = 10;
	printf("%i >> %i\n", test, findLargestPrimeFac_bVal(test));
	test = 42;
	printf("%i >> %i\n", test, findLargestPrimeFac_bVal(test));
	test = 11;
	printf("%i >> %i\n", test, findLargestPrimeFac_bVal(test));
}