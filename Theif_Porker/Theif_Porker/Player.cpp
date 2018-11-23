#include "pch.h"
#include "Player.h"


Player::Player()
{
	int money = 0;
	string name = "";
	Hand hand;
}


Player::~Player()
{
}

void Player::drawCard() {
	hand.addCard();
}

string Player::getName() {
	return name; 
}

int Player::getMoney() { 
	return money; 
}

void Player::setName(string name) { 
	this->name = name; 
}

void Player::setMoney(int money) {
	this->money = money;
}