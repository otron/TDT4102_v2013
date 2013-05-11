#include <iostream>
#include <ctype.h> //islower, isupper, isdigit and stuff

using namespace std;



// Part 1-b
void getInput(char* arr, int size) {
	cin.getline(arr, size);
	//istream::getline(char* c, int n)
	// c is the target array/c-string
	// n is how many chars it should put in it.
}

// Part 1-c
// "Write a function that counts the characters in a C-string.
//  Use of strlen is considered cheating.
//	Cheating is punishable by segfaults."
int countCharacters(char* arr) {
	int i;
	char c = ' ';
	for (i = 0; c != '\0'; i++) {
		c = arr[i];
	}
	return --i; //if a c-string contains n elements, \0 is element #n+1, and the for-loop will increment i to n+1 before finding \0.
}

// Part 1-d
void checkPassword(char* arr) {
	// input needs to contain 6 or more characters,
	// have at least one upper and lower case char,
	// and contain a number.
	int minLength = 6, length = countCharacters(arr);
	if (length < minLength) {
		cout << "Minimum password length is " << minLength << ".\n";
		cout << "Your password contains " << length << " characters.\n";
	}
	bool cNumber = false, cLow = false, cHi = false;
	for (int i = 0; i < length; i++) {
		if (!cNumber && isdigit(arr[i]))
			cNumber = true;
		if (!cLow && islower(arr[i]))
			cLow = true;
		if (!cHi && isupper(arr[i]))
			cHi = true;
	}
	if (!cHi)
		cout << "Your password needs to contain at least one upper case character.\n";
	if (!cLow)
		cout << "Your password needs to contain at least one lower case character.\n";
	if (!cNumber)
		cout << "Your password needs to contain at least one number.\n";
}

void doThePassword() {
	// Part 1
	// do a bunch of crap in the main function.
	// I moved it to its own file.

	// Part 1-a
	// Q: What's a c-string?
	// A: A char-array.


	/* Okay, so I have to set some upper limit on the c-string
		that's to be used in Part 1.
		Because while a c-string has no problems containing fewer
		characters than it has room for everything crashes and burns
		if we attempt to put more characters than that into it.
	*/
	int arbitrary = 128;
	char c[128];
	cout << "Yo guy enter a password: ";
	getInput(c, arbitrary);
	checkPassword(c);
}