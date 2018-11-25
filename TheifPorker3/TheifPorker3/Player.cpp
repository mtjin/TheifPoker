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

Player::Player(string name, int money) {
	this->name = name;
	this->money = money;
}

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

void Player::bet(int betMoney) {
	if (betMoney < money)
	{
		money -= betMoney;
	}
	else {
		cout << "소지한 금액이 부족합니다" << endl;
	}
}

void Player::receiveReward(int reward) {
	money += reward;
}

bool Player::ableToParticipateIn() {
	if (money < 100) {
		return false;
	}
	else {
		return false;
	}
}

void Player::swapCard(Hand hand2, int n) {

}
