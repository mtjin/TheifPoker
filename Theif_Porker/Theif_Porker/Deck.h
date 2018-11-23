#pragma once
#include <iostream>
#include "Card.h"
#include <string>
#include <vector>
using namespace std;;
class Deck
{
private:
	//Card deck[20];
	vector<Card> deck;
	int randNum, tmp; //�����Ҷ� �� ����
	int drawPointer; //ī���о�� �����Ϳ���
	int leftSize; //���� ī�� ����
public:
	Deck();
	~Deck();
	void shuffle();  //ī�弯��
	//���ʱ�ȭ�� �׳� ���ο��� �� �������ִ°ɷδ�ü
	void createDeck();  //������
	Card getCard(); //�� ���� ī���ȯ
	int getLeftSize();  //�����ִ� ī�� �� ī�� ���� ��ȯ
};

