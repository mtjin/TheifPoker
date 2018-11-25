#include "pch.h"
#include "Hand.h"
#include <iostream>

using namespace std;
Hand::Hand()
{
}

//손에 든 카드 다 버리기
void Hand::clear()	
{
	hand.clear();
}

//손에 카드 추가
void Hand::addCard(Card ca)	
{
	if (hand.size() <= 5) hand.push_back(ca);
	else cout << "손에들린 카드가 5장을 넘었습니다." << endl;
}

//특정 위치의 카드 삭제
void Hand::removeCard(unsigned int posi)	
{
	if (posi >= 0 && posi < hand.size())
		hand.erase(hand.begin() + posi);
} 

//손에 든 카드 개수 반환
int Hand::getCardcount()	
{
	return hand.size(); 
}

//특정위치의 카드 반환
Card Hand::getCard(unsigned int posi)	
{
	if (posi >= 0 && posi < hand.size())
		return (Card)hand.at(posi);
	
}

//특정위치의 카드를 삭제하고 다른카드 추가 
//(상대에게 줄 카드위치를 삭제하고 상대방이 준 카드를 저장)
void Hand::changeCard(unsigned int posi, Card ca) {	
	if(posi >= 0 && posi < hand.size()) {
		removeCard(posi);//해당 자리의 카드를 삭제
		//hand.erase(hand.begin() + posi);
		//hand.push_back(ca);//새 카드 추가
		hand.insert(hand.begin() + posi, ca);
	}
}	