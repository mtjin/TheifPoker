#pragma once
#include <vector>
#include "Deck.h"
#include "Card.h"

// ī�� ������ ��Ÿ���� HandŸ��
class Hand {
private:
	vector<Card> hand;
public:
	Hand();
	void clear();		//�տ��ִ� ī�� ������
	void addCard(Card c);	//�տ� ī�� �߰�
	void removeCard(unsigned int position);	//Ư����Ű ī�� ����
	int getCardcount();	//�տ��� ī�� ������ȯ
	Card getCard(unsigned int posi);	//Ư����ġ�� ī�� ��ȯ
	void changeCard(unsigned int posi, Card ca);	//Ư����ġ�� ī�带 �����ϰ� �ٸ�ī�� �߰� (��뿡�� �� ī����ġ�� �����ϰ� ������ �� ī�带 ����)
};
