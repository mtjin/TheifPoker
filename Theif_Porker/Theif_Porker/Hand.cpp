#include "pch.h"
#include "Hand.h"
#include "Hand.h"

Hand::Hand()
{
	pointer = 0;
	noCard = -1;
}


Hand::~Hand()
{
}

void Hand::clear() { //손털기
	
	hand.clear();
	/*
	for (int i = 0; i < 5; i++) {
		handCard[i] = noCard;
	}
	*/
}
void Hand::addCard(Card card) { //카드추가
		hand.push_back(card);
}
void Hand::removeCard(Card card) { //카드제거
		//hand.erase(card);
}
int Hand::getCardCount() {  
	return hand.size();
}
Card Hand::readCard() {
	return hand.at(pointer++);
}