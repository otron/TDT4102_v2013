#ifndef OVING03_H_INCLUDED
#define OVING03_H_INCLUDED

#define WEEKDAYS 7

void inputFeedback();
// Part 1
void printArray(int arr[], int size);

// Part 2
void printArray(int arr[][WEEKDAYS], int first, int second);
void randomizeList(int arr[][WEEKDAYS], int first, int numOfCalls);
void printArrayNiceLike(int arr[][WEEKDAYS], int first, int second, int phones[]);
int countCalls(int arr[][WEEKDAYS], int first, int day); 

#endif // OVING03_H_INCLUDED
