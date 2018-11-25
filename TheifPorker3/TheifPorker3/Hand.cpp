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
} //ó������ ���� �������� ���� ����ֽ��ϴ�.

void Hand::addCard(Card ca)
{
	if (hand.size() <= 5) hand.push_back(ca);
	else cout << "�տ��鸰 ī�尡 5���� �Ѿ����ϴ�." << endl;
}

void Hand::removeCard(unsigned int posi)
{
	if (posi >= 0 && posi < hand.size())
		hand.erase(hand.begin() + posi);
} //��� ī�带 �����ϴ�.

int Hand::getCardcount()
{
	return hand.size(); //���� �鸰 ī���� ������ ��ȯ
}

Card Hand::getCard(unsigned int posi)
{
	if (posi >= 0 && posi < hand.size())
		return (Card)hand.at(posi);
	
} //ī�� �߰��� ���� ���
