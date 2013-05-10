#include <iostream>
#include <stdlib.h> // srand, rand
#include <time.h> // gettime function or something.
#include <stdio.h> // NULL, printf, some other stuff
#include <math.h> // math and stuff: http://www.cplusplus.com/reference/cmath/
#include <cctype>	// "Character library" - Needed for character operations, like tolower(char c)
#include <assert.h> // assertin shit yo.

#include "oving02.h" //"" when the header file is within the same project, I guess? Or you know, nearby.
using namespace std;



int main() {
	//printTime(3, 5, 9);
	srand(time(NULL)); // inits the random seed thing
	//srand sets the seed, the first number generated from some seed is always the same.
	//time(NULL) is constant, apparently.
	testEight();
	cin.get(); // prevents the console from closing instantly.
	return 0;
}

void tests() {
	//4a
	while(true) {
		char e, f;
		cin >> e;
		cin >> f;
		cout << sameCase(e, f) << endl;
	}
	//3c
	char dicks[] = {'a', 'b', 'u', '-', 'R', '4', '{', 'F'};
	for (int i = 0; i < 8; i++) {
		cout << dicks[i] << + " > " << changeCase(dicks[i]) << endl;
	}

	//3b
	for (int i = 0; i < 100; i++) {
		double d = (double) randomTenToFifty();
		cout << d << " :> " << checkTrigonometry(d) << endl;
	}
}

// Part 5
int fiveByValue(int input) {
	return (int) (pow((double) input, 2) + 10) * 2;
}
//call by reference implementation of fiveByValue()
void fiveByRef(int &input) {
	int temp = (int) (pow((double) input, 2) + 10) * 2;
	input = temp;
	return;

	//alternative implementation:
	// input = fiveByValue(input);
	// return;
}

void testFive() {
	printf("Testing 5-a: \n");
	printf("A = 2,\t 28:%i \n", fiveByValue(2));
	printf("A = -4,\t 52:%i \n", fiveByValue(-4));
	printf("A = 0,\t 20:%i \n", fiveByValue(0));
	cout << endl << endl;
	printf("Testing 5-b: \n");
	int A = 5;
	fiveByRef(A);
	printf("A = 5,\t 70:%i \n", A);
	printf("A is now %i \n", A);
	cout << "A = " << A << ",\t result: ";
	fiveByRef(A);
	cout << A << endl;
	cout << "Call by reference is pretty cool.";
	//printf("A = %i,\t 70:%i \n", A, );
}

// Part 4
float getAverage(float a, float b) {
	return ((a+b)/2);
}

int getNumberOfDigits(int num) {
	int retval = 0;
	if (num < 0)
		num = -num; // num = num*-1. This simplifies things.
	while (num > 1) {
		num = num/10;
		retval++;
	}
	return retval;
}

bool sameCase(char a, char b) {
	//check if both characters are letters
	if (toupper(a) == tolower(a) || toupper(b) == tolower(b))
		return false;
	// if tolower(a) == toupper(a) then a isn't a character.

	//check if both characters are the same case
	if (islower(a) && islower(b))
		return true;
	if (isupper(a) && isupper(b))
		return true;
	return false;
}

void test4() {
	//test number of digits
	assert(getNumberOfDigits(0) == 0);
	assert(getNumberOfDigits(3000) == 4);
	assert(getNumberOfDigits(-382910) == 6);
	assert(getNumberOfDigits(3) == 1);

	//test sameCase
	assert(sameCase('f', 'F') == 0);
	assert(sameCase('e', 'k') == 1);
	assert(sameCase(',', ',') == 0);
	assert(sameCase('a', 'a') == 1);
	
	//test avg
	assert(fabs(getAverage(1, 2) - 1.5) < 0.0001);
	assert(fabs(getAverage(3.3, 4.5) - 3.9) < 0.0001);
	assert(fabs(getAverage(0, 0)) == 0);
}


// Part 3
int randomTenToFifty() {
	//random init stuff grabbed from http://www.cplusplus.com/reference/cstdlib/srand/
	return ((rand() % 41) + 10);
}

double checkTrigonometry(double in) {
	double c, s, t, retval;
	c = cos(in);
	s = sin(in);
	t = tan(in);
	// debug code
	// cout << "c: " << c << ", s: " << s << ", t: " << t << ", s/c: " << s/c << endl;
	retval = t - (s/c);

	return 0;
}

char changeCase(char input) {
	//oh wow there's built in functions for this.
	if (islower(input))
		return toupper(input);
	if (isupper(input))
		return tolower(input);

	return input;
}
// Part 2
void printTime(int hour, int minute, int second) {
	cout << hour << " hours, " << minute << " minutes and " << second << " seconds" << endl;
}

void getTime(int seconds) {
	//we can exploit how integer division works.
	int hours = (seconds/3600);
	int minutes = (seconds/60) % 60;
	seconds = seconds % 60;
	printTime(hours, minutes, seconds); //refactoring, yay!
}