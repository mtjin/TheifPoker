#include "pch.h"
#include "Player.h"
#include <iostream>
#include <string>
#include "Hand.h"
#include "Deck.h"
using namespace std;

Player::Player()
{
}

//�÷��̾� �̸��� �� �ʱ�ȭ
Player::Player(string name, int money) {
	this->name = name;
	this->money = money;
}

//ī�� 5�� ��ο�
void Player::drawCard(Deck de) {	
	for (int i = 0; i < 5; i++) {
		hand.addCard(de.dealCard());
	}
}
int Player::getMoney() {
	return this->money;
}
string Player::getName() {
	return this->name;
}
Hand Player::getHand() {
	return this->hand;
}

//����
void Player::bet(int betMoney) {	
	if (betMoney < money)
	{
		money -= betMoney;
	}
	else {
		cout << "������ �ݾ��� �����մϴ�" << endl;
	}
}

//���� ȹ��
void Player::receiveReward(int reward) {
	money += reward;
}

//���������� ���� �ִ��� �˻�
bool Player::ableToParticipateIn() {	
	if (money < 100) {
		return false;
	}
	else {
		return false;
	}
}

void Player::swapCard(Hand *hand1, Hand *hand2, int n1, int n2) {	//��� �÷��̾�� ī�� ��ȯ
	Card tmp1 = hand1->getCard(n2);
	Card tmp2 = hand2->getCard(n1);
	hand1->changeCard(n1, tmp1);
	hand2->changeCard(n2, tmp2);
}
