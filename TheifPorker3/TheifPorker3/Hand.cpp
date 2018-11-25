#include "pch.h"
#include "Hand.h"
#include <iostream>

using namespace std;
Hand::Hand()
{
}

//�տ� �� ī�� �� ������
void Hand::clear()	
{
	hand.clear();
}

//�տ� ī�� �߰�
void Hand::addCard(Card ca)	
{
	if (hand.size() <= 5) hand.push_back(ca);
	else cout << "�տ��鸰 ī�尡 5���� �Ѿ����ϴ�." << endl;
}

//Ư�� ��ġ�� ī�� ����
void Hand::removeCard(unsigned int posi)	
{
	if (posi >= 0 && posi < hand.size())
		hand.erase(hand.begin() + posi);
} 

//�տ� �� ī�� ���� ��ȯ
int Hand::getCardcount()	
{
	return hand.size(); 
}

//Ư����ġ�� ī�� ��ȯ
Card Hand::getCard(unsigned int posi)	
{
	if (posi >= 0 && posi < hand.size())
		return (Card)hand.at(posi);
	
}

//Ư����ġ�� ī�带 �����ϰ� �ٸ�ī�� �߰� 
//(��뿡�� �� ī����ġ�� �����ϰ� ������ �� ī�带 ����)
void Hand::changeCard(unsigned int posi, Card ca) {	
	if(posi >= 0 && posi < hand.size()) {
		removeCard(posi);//�ش� �ڸ��� ī�带 ����
		//hand.erase(hand.begin() + posi);
		//hand.push_back(ca);//�� ī�� �߰�
		hand.insert(hand.begin() + posi, ca);
	}
}	