#pragma once
#include <iostream>
#include "Card.h"
class Deck{
private:
	Card deck[21]; 
	Card temp;
	int cardsUsed;  //�����ī��
	int cardCt;
	int randomnum;
public:
	Deck();
	void shuffle(); //���� ���� ���
	int cardsLeft();	//���� �����ִ� ī�� �� ��ȯ
	Card dealCard();	//������ ī�� ��������
};

