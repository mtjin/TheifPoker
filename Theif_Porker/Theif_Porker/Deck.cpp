#include "pch.h"
#include <stdlib.h>
#include "Deck.h"
#include "Card.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
Deck::Deck()
{
}


Deck::~Deck()
{
}
void Deck::shuffle() { //ī�弯��
	for (int i = 0; i < 20; i++) {
		randNum = (int)(rand() % (i + 1));  //��������
		tmp = deck[i].getRank;
		deck[i] = deck[randNum];
		deck[randNum] = tmp;
		//tmp = deck.at(i).getRank;
		//deck.p


	}
}
	//���ʱ�ȭ�� �׳� ���ο��� �� �������ִ°ɷδ�ü
void Deck::createDeck() {  //������
	for (int i = 0; i < 19; i++) {
		for (int j = 1; j <= 5; j++) { //1~5 ī�� 4��Ʈ����
			deck[i] = Card(j);
			//deck.push_back(Card(j));
		}
	}
	deck[20] = 0; //���
	//deck.push_back(Card(0));
}