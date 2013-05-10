#ifndef MASTERMIND_H_INCLUDED
#define MASTERMIND_H_INCLUDED

void playMastermind();
char randomChar();
void readInput(char arr[]);
bool isValidInput(char c);
int checkCharacters(char guess[], char code[]);
int checkCharactersAndPosition(char guess[], char code[]);
void printCode(char arr[]);
#endif
