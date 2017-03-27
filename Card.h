#ifndef CARD_H
#define CARD_H

class Card{
	private:
		int suit;
		int value;
	public:
		Card(int suit1, int value1);
		int getValue(){return value;};
		int getSuit(){return suit;};
		bool operator==(const Card &other);

};

#endif

