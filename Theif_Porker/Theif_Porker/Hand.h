#pragma once
#include <iostream>
#include <vector>
#include "Deck.h"
using namespace std;
class Hand : public Deck
{
private:
	//Card handCard[5];
	vector<Card>  hand;
	int noCard = -1;
	int pointer;
public:
	Hand();
	~Hand();
	void clear(); //º’≈–±‚
	void addCard(Card c); 
	void removeCard(Card c);
	int getCardCount();
	Card readCard();

};

