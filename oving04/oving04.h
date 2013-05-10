#ifndef OVING04_H_INCLUDED
#define OVING04_H_INCLUDED

#ifndef STRINGS_INCLUDED
#define STRINGS_INCLUDED

#include <string> // strings!
using namespace std; //need this in the header file or else we get C4430 on all string declarations here.

#endif


// Part 5
void testFive();

// Part 3
string nameFixer(string name);
void testThree();

// Part 2
struct Musician {
	string name;
	int weight;
	int height;
	int beardLength;
};

struct Band {
	string name;
	bool rockBand;
	int releases;
	Musician members[4]; //"All real bands have four members".
};
void testTwo();
int totalBeardLength(Band band);

// Part 1
// right, this has to be in the header file. I guess because it's a declaration?
// Trial & error is pretty nice.
enum Beatle {
	JOHN,
	PAUL,
	GEORGE,
	RINGO
};
bool isAlive(Beatle beatle);
void testOne();

#endif
