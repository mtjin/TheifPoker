#include "pch.h"
#include "Hand.h"
#include "Hand.h"

Hand::Hand()
{
}


Hand::~Hand()
{
}

void Hand::clear() { //손털기
	for (int i = 0; i < 5; i++) {
		handCard[i] = noCard;
	}
}
void Hand::addCard(Card card) { //카드추가
	for (int i = 0; i < 5; i++) {
		handCard[i] = card;
	}
}
void Hand::removeCard(Card c);
int Hand::getCardCount();