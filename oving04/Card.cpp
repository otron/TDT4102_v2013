#include "Card.h"
#include <sstream>

namespace Cards {

int Card::getValue() { return value; }
string Card::getSuit() { return suit; }

Card::Card(string s, int val) {
	this->setSuit(s);
	this->setValue(val);
}

Card::Card() {
	this->setSuit("H");
	this->setValue(4);
	// turns out I can't just declare stuff in the header files without actually implementing them
	// or else the VS compiler spouts error LNK2019
}

string Card::getFace() {
	stringstream ss;
	ss << this->getValue();
	return (this->getSuit() + ss.str());
}

void Card::setValue(int val) {
	if (val > 0 && val < 14)
		this->value = val;
}

void Card::setSuit(string s) {
	if (s == "S" || s == "H" || s == "C" || s == "D")
		this->suit = s;
}

}
