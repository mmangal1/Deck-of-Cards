#include "Card.h"

Card::Card(int suit1, int value1){
	if(suit1 < 5 && suit1 > 0)
		suit = suit1;
	if(value1 < 15 && value1 > 1)
		value = value1;
}

bool Card::operator ==(const Card &other){
	if(suit == other.suit && value == other.value)
		return true;
	else
		return false;

}



