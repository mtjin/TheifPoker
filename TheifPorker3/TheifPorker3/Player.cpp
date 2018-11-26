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
void Player::drawCard(Deck *de) {	
	for (int i = 0; i < 5; i++) {
		hand.addCard(de->dealCard());
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

int Player::swapCard(Hand *hand1, Hand *hand2, int n1, int n2) {	//��� �÷��̾�� ī�� ��ȯ
	Card tmp1 = hand1->getCard(n1); //hand1�� ����� hand2�� ī�� ����
	if (tmp1.getRank() == 0) {  //�ڽ��� �� �а� ���ī���� ��� 1�� ��ȯ(�ٷ� ��Ģ�� �����)
		cout << "���ī��� ��뿡�� �� �� �����ϴ� (��Ģ��)" << endl;
		return 1;
	}
	Card tmp2 = hand2->getCard(n2);	 //hand2�� ����� hand1�� ī�� ����
	if (tmp2.getRank() == 0) {	//����� ����ڵ带 ����� ��� (�ٷ� ��)
		return 1;
	}
	hand1->changeCard(n1, tmp2);
	hand2->changeCard(n2, tmp1);

	return 0;
}
