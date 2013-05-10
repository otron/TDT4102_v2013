#ifndef CARDDECK_H_INCLUDED
#define CARDDECK_H_INCLUDED
#include "Card.h"

#define DECKSIZE 52 //decided by the assignment text
namespace Cards {
class CardDeck {
	private:
		Card cards[DECKSIZE];
		void buildDeck();
		int numberDealt, deckSize;
	public:
		CardDeck();
		CardDeck(bool shouldShuffle);
		int getDecksize(); //should return the decksize
		void shuffle(); //erry day i'm shufflin'
		void dealHand(Card hand[], int cardsToDeal);
		int cardsRemaining();
		
};
}
#endif