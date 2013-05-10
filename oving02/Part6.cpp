#include <iostream>
#include <stdlib.h> // srand, rand
#include <time.h> // gettime function or something.
#include <stdio.h> // NULL, printf, some other stuff
#include <math.h> // math and stuff: http://www.cplusplus.com/reference/cmath/
#include <cctype>	// "Character library" - Needed for character operations, like tolower(char c)
#include <assert.h> // assertin shit yo.

#include "oving02.h"
using namespace std;
// Part 6
int add(int a, int b) {
	return a+b;
}
double add(double a, double b) {
	return a+b;
}

void add(int &a, int &b, int &c, int &d) {
	b += a;
	c += b;
	d += c;
	// a = a, b = a+b, c = b+c == a+b+c, d = c+d == a+b+c+d
	return;
}

void testSix() {
	int a = 1, b = 0, c = 0, d = 0;
	//a = 1;
	printf("Before: a = %i, b = %i, c = %i, d = %i\n", a, b, c, d);
	add(a, b, c, d);
	printf("After: a = %i, b = %i, c = %i, d = %i \n", a, b, c, d);
	add(a, b, c, d);
	printf("After: a = %i, b = %i, c = %i, d = %i \n", a, b, c, d);
	add(a, b, c, d);
	printf("After: a = %i, b = %i, c = %i, d = %i \n", a, b, c, d);
	add(a, b, c, d);
	printf("After: a = %i, b = %i, c = %i, d = %i \n", a, b, c, d);
	add(a, b, c, d);
	printf("After: a = %i, b = %i, c = %i, d = %i \n", a, b, c, d);
	add(a, b, c, d);
	printf("After: a = %i, b = %i, c = %i, d = %i \n", a, b, c, d);
}