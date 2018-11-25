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
	void drawCard(Deck de);
	int getMoney();
	string getName();
	Hand getHand();
	void bet(int betMoney);  //���ñݾ�
	void receiveReward(int reward); //�̰����� ����
	bool ableToParticipateIn(); //�������� �� �� �ִ��� ����( �ּұݾ׺�� 100���� �����ݾ��� ������ ���)
	void swapCard(Hand hand2, int n); //���� �տ��ִ�(hand2) n���� ī��� �ڽ��� ī�� ��ȯ
};

