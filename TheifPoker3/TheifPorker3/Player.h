#pragma once
#include <iostream>
#include <string>
#include "Hand.h"
#include "Deck.h"

using namespace std;
class Player
{
private:
	int money;
	string name;
	Hand hand;
public:
	Player();
	Player(string name, int money);
	void drawCard(Deck *de);	//ī�� 5�� ��ο�
	int getMoney();
	string getName();
	Hand getHand();
	void addMoney(int);
	void subMoney(int);
	bool bet(int);  //����
	bool call(int betMoney); //��
	bool stay(); //������
	bool fold(Player, int); //����
	void receiveReward(int reward); //�̰����� ����
	bool ableToParticipateIn(); //�������� �� �� �ִ��� ����( �ּұݾ׺�� 100���� �����ݾ��� ������ ���)
	bool swapCard(Hand *hand1, Hand *hand2, int n1, int n2); //����� ī�� ��ȯ
	void displayMoney();
	void clearHand();
};

