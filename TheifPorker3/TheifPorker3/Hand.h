#pragma once
#include <vector>
#include "Deck.h"

// 카드 한장을 나타내는 Hand타입
class Hand : public Deck {
private:
	vector<Card> hand;
public:
	Hand();
	void clear();
	void addCard(Card c);
	//void removeCard(Card c);
	void removeCard(unsigned int position);
	int getCardcount();
	Card getCard(unsigned int posi);
};

