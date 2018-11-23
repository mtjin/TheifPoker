#pragma once
#include <iostream>
#include <vector>
#include "Deck.h"
using namespace std;
class Hand : public Deck
{
private:
	Card handCard[5];
	int noCard = -1;
public:
	Hand();
	~Hand();
	void clear(); //º’≈–±‚
	void addCard(Card c); 
	void removeCard(Card c);
	int getCardCount();

};

