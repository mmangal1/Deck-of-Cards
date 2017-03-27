#include "Deck.h"

Deck::Deck(){
	for(int x = 1; x <= 4; x++){
		for(int y = 2; y <= 14; y++){
			Card* card = new Card(x, y);
			deck.enqueue(card);
		}
	}
}

Card Deck::draw(){
	Card* temp =  deck.dequeue();
	Card retVal = *temp;
	delete temp;
	return retVal;

}

bool Deck::empty(){
	return deck.empty();
}

void Deck::shuffle(){
	Queue<Card*> temp1;
	Queue<Card*> temp2;

	for(int x = 0; x < 50; x++){
		for(int i = 0; i < rand()%26+5 && !deck.empty(); i++){
			temp1.enqueue(deck.dequeue());
		}
		while(!deck.empty()){
			temp2.enqueue(deck.dequeue());
		}
		while(!temp2.empty())
			deck.enqueue(temp2.dequeue());
		while(!temp1.empty())
			deck.enqueue(temp1.dequeue());
	}


}
