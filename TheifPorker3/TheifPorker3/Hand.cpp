#include "pch.h"
#include "Hand.h"
#include <iostream>

using namespace std;
Hand::Hand()
{
}

void Hand::clear()
{
	hand.clear();
} //처음에는 게임 참가자의 손이 비어있습니다.

void Hand::addCard(Card ca)
{
	if (hand.size() <= 5) hand.push_back(ca);
	else cout << "손에들린 카드가 5장을 넘었습니다." << endl;
}

void Hand::removeCard(unsigned int posi)
{
	if (posi >= 0 && posi < hand.size())
		hand.erase(hand.begin() + posi);
} //모든 카드를 버립니다.

int Hand::getCardcount()
{
	return hand.size(); //손이 들린 카드의 개수를 반환
}

Card Hand::getCard(unsigned int posi)
{
	if (posi >= 0 && posi < hand.size())
		return (Card)hand.at(posi);
	
} //카드 추가에 대한 기능
