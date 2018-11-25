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

//플레이어 이름과 돈 초기화
Player::Player(string name, int money) {
	this->name = name;
	this->money = money;
}

//카드 5장 드로우
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

//베팅
void Player::bet(int betMoney) {	
	if (betMoney < money)
	{
		money -= betMoney;
	}
	else {
		cout << "소지한 금액이 부족합니다" << endl;
	}
}

//보상 획득
void Player::receiveReward(int reward) {
	money += reward;
}

//참가가능한 돈이 있는지 검사
bool Player::ableToParticipateIn() {	
	if (money < 100) {
		return false;
	}
	else {
		return false;
	}
}

void Player::swapCard(Hand *hand1, Hand *hand2, int n1, int n2) {	//상대 플레이어와 카드 교환
	Card tmp1 = hand1->getCard(n2);
	Card tmp2 = hand2->getCard(n1);
	hand1->changeCard(n1, tmp1);
	hand2->changeCard(n2, tmp2);
}
