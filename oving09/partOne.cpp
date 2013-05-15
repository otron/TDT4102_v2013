#include <iostream> //cin
#include <stdio.h> // printf
#include <stdlib.h> //srand, rand
#include <time.h> // time
#include <string>

using namespace std;


// Part 1-a: write a template function that shuffles an array.
// its two parameters should be the array and the array's size.
template<class T> //this has to be right above the function for some reason
void shuffle(T arr[], int size) {
	//again with the fisher-yates shuffle
	for (int i = size-1; i > -1; i--) {
		int j = rand() % (size - i);
		T temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void shuffleTest(){
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	shuffle(a, 7);
	printf("Shuffling a...\n");
	for (int i = 0; i < 7; i++)
		printf("%i, ", a[i]);

	double b[] = {1.2, 2.2, 3.2, 4.2};
	shuffle(b, 4);
	printf("\nshuffling b...\n");
	for (int i = 0; i < 4; i++)
		cout << b[i] << ", ";

	string c[] = {"one", "two", "three", "four"};
	printf("\nshuffling c...\n");
	shuffle(c, 4);
	for (int i = 0; i < 4; i++)
		printf("%s, ", c[i].c_str());
	cout << endl;
}


// Part 1-b:
// template function, maximum.
template<class T>
T maximum(T a, T b) {
	return (a > b ? a : b);
}

void testmax() {
	int a = 1, b = 2, c = maximum(a,b);
	printf("c should be 2, is %i\n", c);

	double d = 2.4, e = 3.2, f = maximum(e,d);
	printf("f should be 3.2, is %f\n", f);
}

int main() {
	srand(time(0)); // seed the randomizer

	shuffleTest();
	testmax();
	cin.get();
}