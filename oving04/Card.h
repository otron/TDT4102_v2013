#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#ifndef STRINGS_INCLUDED
#define STRINGS_INCLUDED

#include <string> 
using namespace std; 

#endif

namespace Cards {

class Card {
	private:
		int value; // [1,13]
		string suit; // S, H, C or D
	public:
		int getValue();
		string getSuit();
		string getFace(); // should return suit + value (e.g. "S8")
		void setValue(int val);
		void setSuit(string s);
		Card(string s, int val);
		Card();
};

}
#endif
