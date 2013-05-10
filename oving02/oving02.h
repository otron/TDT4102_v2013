#ifndef OVING02_H_INCLUDED
#define OVING02_H_INCLUDED

void tests();

// Part 1
double hypotenuse(double side1, double side2);
// returns sqrt(side1**2+side2**2)
int sum(int x, int y, int z);
// 
void instructions();
// ??
double intToDouble(int number);
// ...

// Part 2
void printTime(int hour, int minute, int second);

void getTime(int seconds);

// Part 3

int randomTenToFifty();
double checkTrigonometry(double in);
char changeCase(char input);

// Part 4
bool sameCase(char a, char b);
int getNumberOfDigits(int num);
float getAverage(float a, float b);
void test4();

// Part 5
int fiveByValue(int input);
void testFive();
void fiveByRef(int &input);

// Part 6
int add(int a, int b);
double add(double a, double b);
void add(int &a, int &b, int &c, int &d);
void testSix();

// Part 8
int findLargestPrimeFac_bVal(int input);
void findLargestPrimeFac_bRef(int &input);
void testEight();

#endif // OVING02_H_INCLUDED
