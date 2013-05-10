#include "oving04.h"
#include "CardDeck.h"
#include <stdio.h> // printf
#include <iostream>


using namespace Cards;

int main() {
	//testOne();
	//testTwo();
	//testThree();
	testFive();
	cin.get();
}

// Part 5
void testFive() {
	printf("\n\nTESTING PART FIVE\n\n");
	Card allCards[DECKSIZE]; //still with that constant.
	CardDeck derp;
	printf("Printing unshuffled deck\n");
	derp.dealHand(allCards, DECKSIZE);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			printf("%s, ", allCards[j+13*i].getFace().c_str());
		}
		printf("\n");
	}
	
	derp.shuffle();
	derp.dealHand(allCards, DECKSIZE);
	printf("\nPrinting shuffled deck\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			printf("%s, ", allCards[j+13*i].getFace().c_str());
		}
		printf("\n");
	}
}


// Part 3
string nameFixer(string name) {
	// assumes name is on the form "%s1 %s2"
	// should return a string on the form "%s2, %s1"
	int pos = name.find(" "); // position of the space
	if (pos < 0)
		return NULL; //this isn't supposed to happen. We haven't gotten to exceptions yet though so let's not spend too much time on this.
	//first name = [0, pos]
	//a three char long first name means pos == 3, because of 0-indexing.
	string fname = name.substr(0, pos);
	//last name = [pos+1, length-(pos+1)]
	// first char of lname is the one after the space
	// last char of lname is the last char in the string
	// for a given position, p, in an array, the part after p is [p+1, l-(p+1)]
	string lname = name.substr(pos+1, name.length() - (pos+1));

	lname.append(", ");
	lname.append(fname);
	return lname;
}

void testThree() {
	string s[] = { "Dick Jones", "James J.", " spacefirst" };
	string q[] = { "Jones, Dick", "J., James", "spacefirst, " };
	int n = 3;
	
	printf("\nTESTING PART THREE\n");
	printf("in\t\texp.\t\tres\t\t\n");
	for (int i = 0; i < n; i++) {
		/* right, printf("%s") takes a c-string.
		   That's why this shit's been junk.
		*/
		printf("%s\t%s\t%s\n", s[i].c_str(), q[i].c_str(), nameFixer(s[i]).c_str());
	}
}

// Part 2
int totalBeardLength(Band band) {
	// this function relies on a magic number: 4, which we have defined to be the number of band members
	// ...
	if (band.rockBand == false) 
		return -1; //this is how the world works.
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		//Stardate 2013-05-07 12:36, I restarted VS 2010 because intellisense had stopped working.
		sum += band.members[i].beardLength;
	}
	return sum;
}

void testTwo() {
	printf("Testing the totalBeardLength function...\n");
	// create musicians and set their beardlengths
	Musician bob, james, rick, roll, dick;
	bob.beardLength = 10;
	james.beardLength = 4;
	rick.beardLength = 0;
	roll.beardLength = -3;
	dick.beardLength = 15;

	Band band1;
	band1.members[0] = bob;
	band1.members[1] = james;
	band1.members[2] = rick;
	band1.members[3] = dick;
	band1.rockBand = true;
	// bL = 29
	printf("tBL should be 29, is %i\n", totalBeardLength(band1));
	band1.members[0] = roll;
	printf("tBL should be 16, is %i\n", totalBeardLength(band1));
	band1.rockBand = false;
	printf("tBL should be -1, is %i\n", totalBeardLength(band1));
	
}

// Part 1
void testOne() {
	printf("Testing Part 1.\n");
	printf("Paul & Ringo should be alive, and they are %s & %s\n", (isAlive(PAUL))?"alive":"dead", (isAlive(RINGO))?"alive":"dead");
	printf("John & George should be dead, and they are %s & %s\n", (isAlive(JOHN))?"alive":"dead", (isAlive(GEORGE))?"alive":"dead");
}


bool isAlive(Beatle beatle) {
	switch (beatle) {
		case JOHN:
		case GEORGE:
			return false; //utilizing fall-through!
		case PAUL:
		case RINGO:
		default:
			return true;
	}
}

