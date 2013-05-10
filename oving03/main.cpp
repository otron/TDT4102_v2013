#include "oving03.h"
#include "mastermind.h"
#include <iostream> // std and stuff
#include <stdlib.h> // srand, rand
#include <time.h> // gettime function or something.

using namespace std;

// without using namespace std == std::cin.get()


int main() {
	srand(time(0)); //init randomization

	playMastermind();
	cin.get();

	// contains the stuff Part 1 told me to do.
	int phoneNumbers[5] = {66778899, 12345678, 44335522, 69523113, 99775533};

	int records[5][WEEKDAYS];
	//need to set all these elements to 0, apparently.
	for (int i = 0; i < 5; i ++) 
		for (int j = 0; j < WEEKDAYS; j++) 
			records[i][j] = 0;

	randomizeList(records, 5, 100);
	printArray(records, 5, WEEKDAYS);
	printArrayNiceLike(records, 5, WEEKDAYS, phoneNumbers);
	cin.get();
	return 0;
}

// Part 2

int countCalls(int arr[][WEEKDAYS], int first, int day) {
	int res = 0;
	for (int i = 0; i < first; i++) {
		res += arr[i][day];
	}
	return res;
}

void randomizeList(int arr[][WEEKDAYS], int first, int numOfCalls) {
	for (int i = 0; i < numOfCalls; i++) {
		arr[rand() % first][rand() % 7]++;
		//generate two random numbers: a = [0, first-1], b = [0, 6]
	}
}

// prints the records array all nice like.
void printArrayNiceLike(int arr[][WEEKDAYS], int first, int second, int phones[]) {
	printf("Phone#\t\tMon\tTue\tWed\tThu\tFri\tSat\tSun\n");
	for (int i = 0; i < first; i++) {
		printf("%i\t", phones[i]);
		for (int j = 0; j < second; j++) {
			printf("%i\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("Total\t\t");
	for (int i = 0; i < WEEKDAYS; i++) {
		printf("%i\t", countCalls(arr, first, i));
	}
	printf("\n");
}

void printArray(int arr[][WEEKDAYS], int first, int second) {
	//Prints a two dimensional array.
	for (int i = 0; i < first; i++) {
		for (int j = 0; j < second; j++) {
			printf("%i\t", arr[i][j]);
		}
		cout << endl;
	}
	cout << endl;
}

// Part 1

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%i\n", arr[i]);
	}
}

void inputFeedback() {
	while (true) {
		for (int i = 0; i < 5; i++) {
			cout << cin.get() << ", ";
		}
		cout << endl;
	}
}