#include "pch.h"
#include "Hand.h"
#include "Card.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;
Hand::Hand()
{
}

//�տ� �� ī�� �� ������
void Hand::clear()	
{
	cards.clear();
}

//�տ� ī�� �߰�
void Hand::addCard(Card ca)	
{
	if (cards.size() < 4) cards.push_back(ca);
	else cout << "�տ��鸰 ī�尡 4���� �Ѿ����ϴ�." << endl;
}

//Ư�� ��ġ�� ī�� ����
void Hand::removeCard(unsigned int posi)	
{
	
	if (posi >= 0 && posi < cards.size())
		cards.erase(cards.begin() + posi);
} 

//�տ� �� ī�� ���� ��ȯ
int Hand::getCardcount()	
{
	return cards.size();
}

//Ư����ġ�� ī�� ��ȯ
Card Hand::getCard(unsigned int posi)
{
	
	if (posi >= 0 && posi < cards.size()) {
		
		return (Card)(cards.at(posi));
		
	}
}

//Ư����ġ�� ī�带 �����ϰ� �ٸ�ī�� �߰� 
//(��뿡�� �� ī����ġ�� �����ϰ� ������ �� ī�带 ����)
void Hand::changeCard(unsigned int posi, Card ca) {
	if(posi >= 0 && posi < cards.size()) {
		removeCard(posi);//�ش� �ڸ��� ī�带 ����
		cards.insert(cards.begin() + posi, ca); //�� ī�� �߰�
	}
}	

void Hand::displayHand() {
	cout << "-----------------------------" << endl;
	for (int i = 0; i < 4; i++) {
		cout << " | " << cards.at(i).getRank() << " | ";
	}
	cout << endl;
	cout << "-----------------------------"<<endl;
	cout << "  ��     ��     ��     ��" << endl << endl;
}

void Hand::displayHiddenHand() {
	cout << "-----------------------------" << endl;
	for (int i = 0; i < 4; i++) {
		cout << " | " << "#" << " | ";
	}
	cout << endl;
	cout << "-----------------------------" << endl << endl;
	cout << "  ��     ��     ��     ��" << endl;
}

void Hand::handShuffle() {
	for (int i = 0; i < 100; i++) {
		(srand((unsigned int)time(NULL)));
		int randomnum = (int)(rand() % (4));
		Card temp = cards.at(randomnum);
		int randomnum2 = i%4;
		//int randomnum2 = (int)(rand() % (4));
		Card temp2 = cards.at(randomnum2);
		removeCard(randomnum);//�ش� �ڸ��� ī�带 ����
		cards.insert(cards.begin() + randomnum, temp2); //�� ī�� �߰�
		removeCard(randomnum2);//�ش� �ڸ��� ī�带 ����
		cards.insert(cards.begin() + randomnum2, temp); //�� ī�� �߰�
	}
}