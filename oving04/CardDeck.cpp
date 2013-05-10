#include "CardDeck.h"
#include <stdlib.h> // srand, rand
#include <time.h> // gettime function or something.

namespace Cards {

// Part 5-b
void CardDeck::buildDeck() {
	string s[] = {"S", "H", "C", "D"};
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; j++) {
			//Card cd (s[i], j);
			this->cards[i*13+j-1] = Card (s[i], j);
			//will the above work?
			//perhaps we'll find out.
		}
	}
	this->numberDealt = 0;
}

// Part 5-f
// deals the hand if there's enough cards left.
void CardDeck::dealHand(Card hand[], int cardsToDeal) {
	// hand isn't passed as a reference because it's an array
	// and arrays are mutable.
	// wait, does that make sense in C++?
	// eh, whatever.
	if (cardsRemaining() < cardsToDeal)
		return;

	for (int i = (this->numberDealt), j = 0; (i < cardsToDeal+(this->numberDealt) && j < cardsToDeal);	i++, j++) {
		// j = [0,cardsToDeal)
		// i = [numberDealt, numberDealt+cardsToDeal)
		hand[j] = this->cards[i];
		//in hindsight, this solution is needlessly complicated.
		//whatever, the compiler will take care of it.
	}
	this->numberDealt += cardsToDeal;
}

int CardDeck::cardsRemaining() {
	return (DECKSIZE - this->numberDealt);
}

// Part 5-d
CardDeck::CardDeck() {
	//why does VS2010 tell me there's no default constructor for the class "Card"?
	buildDeck();
}

// Part 5-e
// Shuffles the deck if the argument is true
CardDeck::CardDeck(bool shouldShuffle) {
	//I created a default constructor for Card which does nothing and that made VS 2010 stop bothering me.
	//sheesh.
	buildDeck();
	if (shouldShuffle)
		shuffle();
}

// Part 5-c
void CardDeck::shuffle() {
	//the modern version of the Fisher-Yates shuffle
	// http://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
	srand(time(0));
	for (int i = DECKSIZE-1; i > -1; i--) {
		int j = rand() % (DECKSIZE - i);
		Card temp = this->cards[i];
		this->cards[i] = this->cards[j];
		this->cards[j] = temp;
	}
	this->numberDealt = 0;
}

}