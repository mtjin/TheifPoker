#pragma once
#include <iostream>
#include "Card.h"
class Deck : public Card {
private:
	Card deck[21]; 
	Card temp;
	int cardsUsed;
	int cardCt;
	int randomnum;
public:
	Deck();
	void shuffle(); //µ¦À» ¼¯´Â ±â´É
	int cardsLeft();
	Card dealCard();
};

