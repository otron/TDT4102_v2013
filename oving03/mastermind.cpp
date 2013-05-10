#include <iostream> // std and stuff
#include <stdlib.h> // srand, rand
#include <time.h> // gettime function or something.
#include <map> // maps!
#include "oving03.h"
#include "mastermind.h"

using namespace std;
//defining constants because the exercise text said I should do so
//in a hint.
#define SIZE 4
#define LETTERS 6
#define GUESSES 10
#define DEBUG 1


void playMastermind() {
	char replay = 'y';
	while (replay == 'y') {

		srand(time(0)); //init random
		// init
		char code[SIZE]; //holds the answer key
		char guess[SIZE]; //holds the player's guess
		//populate the answer key array with random characters
		for (int i = 0; i < SIZE; i++) {
			code[i] = randomChar();
		}

		for (int i = 0; i < GUESSES; i++) {
			readInput(guess); //read input from player
			int correct = checkCharactersAndPosition(guess, code);
			int cChars = checkCharacters(guess, code);
			printf("You guessed: ");
			printCode(guess);
			if (DEBUG) {
				printf("Answer: ");
				printCode(code);
			}
			printf("Correct chars: %i\nCorrect placement: %i\n", cChars, correct);
			if (correct == SIZE) {
				printf("Congratulations, Jonny, you did it!\n");
				break;
			}
		}
		printf("Play again? y/n ");
		cin >> replay;
	}
}

// counts the number of correct characters in guess, ignoring placement.
int checkCharacters(char guess[], char code[]) {
	int occurG[LETTERS], occurC[LETTERS];
	for (int i = 0; i < LETTERS; i++) {
		occurG[i] = 0;
		occurC[i] = 0;
	}
	for (int i = 0; i < SIZE; i++) {
		occurG[guess[i]-65]++;
		occurC[code[i]-65]++;
	}
	int res = 0;
	for (int i = 0; i < LETTERS; i++) {
		if (occurC[i] > 0)
			res += min(occurC[i], occurG[i]);
	}
	return res;
}

//counts the number of correctly guessed characters.
int checkCharactersAndPosition(char guess[], char code[]) {
	int res = 0;
	for (int i = 0; i < SIZE; i++) {
		if (guess[i] == code[i])
			res++;
	}
	return res;
}

void printCode(char arr[]) {
	for (int i = 0; i < SIZE; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");
}

void readInput(char arr[]) {
	printf("Enter %i letters between A and %c.\nPress the carriage return key between each letter.\n", SIZE, 'A'+LETTERS-1);
	for (int i = 0; i < SIZE; i++) {
		char c;
		cin >> c;
		if (isValidInput(c)) {
			arr[i] = c;
		} else {
			printf("Please try again.\n");
			i--;
			/* it would probably be more efficient to do this as a while loop,
			and just not increment the counter if it's not valid.
			But then again it might not matter at all due to the process
			includes evaluating user input so we'll probably get a lot of
			branch-misses anyway.
			*/
		}
	}
}

//checks if c is in [65, 65+LETTERS-1]
bool isValidInput(char c) {
	if (c >= 'A' && c <= 'A'+LETTERS-1)
		return true;
	return false;
}

//returns a random uppercase character in the range [A, A+LETTERS]
char randomChar() {
	//A has ASCII value 65
	//get random number in [0, LETTERS)
	char res = rand() % LETTERS;
	//add 65 to result.
	return res + 65;
	//it's okay, chars work like this in C++.
}
