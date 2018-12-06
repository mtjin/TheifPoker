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
	for (int i = 0; i < 4; i++) {
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
void Player::addMoney(int money) {
	this->money += money;
}
void Player::subMoney(int money) {
	this->money -= money;
}

//����
bool Player::bet(int betMoney) {	
	if (betMoney <= money)
	{
		money -= betMoney;
		cout << name << "���� $" << betMoney << " ��ŭ �����ϼ̽��ϴ�." << endl;
		return true;
	}
	else {
		cout << "������ �ݾ��� �����մϴ�" << endl;
		return false;
	}
}

//��
bool Player::call(int betMoney) {
	if (betMoney <= money)
	{
		money -= betMoney;
		cout << name << "���� $" << betMoney << " �� �ϼ̽��ϴ�." << endl;
		return true;
	}
	else {
		cout << "������ �ݾ��� �����մϴ�" << endl;
		return false;
	}
}

//������
bool Player::stay() {
	cout << name << "���� �����̸� �����ϼ̽��ϴ�. ���� �����մϴ�." << endl;
	return true;
	
}

//����
bool Player::fold( Player winner, int tablemoney) {
	winner.addMoney(tablemoney);
	cout << name << "���� �й踦 �����ϼ̽��ϴ�." << endl;
	cout << winner.getName() << "���� �¸�!" << endl << winner.getName() << "���� $" << tablemoney << " �� ������ϴ�!" << endl;
	return false;
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
		return true;
	}
}

bool Player::swapCard(Hand *hand1, Hand *hand2, int n1, int n2) {	//��� �÷��̾�� ī�� ��ȯ
	Card tmp1 = hand1->getCard(n1); //hand1�� ����� hand2�� ī�� ����
	if (tmp1.getRank() == 0) {  //�ڽ��� �� �а� ���ī���� ��� 1�� ��ȯ(�ٷ� ��Ģ�� �����)
		cout << "���ī��� ��뿡�� �� �� �����ϴ� (��Ģ��)" << endl;
		return false;
	}
	Card tmp2 = hand2->getCard(n2);	 //hand2�� ����� hand1�� ī�� ����
	if (tmp2.getRank() == 0) {	//����� ����ڵ带 ����� ��� (�ٷ� ��)
		return false;
	}
	hand1->changeCard(n1, tmp2);
	hand2->changeCard(n2, tmp1);

	return true;
}


void Player::displayMoney() {
	cout << "-----------------------------" << endl;
	cout << "  "<<this->name << " ���� �ں� : " << "$" << money << endl;
	cout << "-----------------------------" << endl;
}

void Player::clearHand() {
	hand.clear();
}