#include "pch.h"
#include "Player.h"
#include <iostream>
#include <string>
#include "Hand.h"
using namespace std;

Player::Player()
{
}

Player::Player(string name, int money) {
	this->name = name;
	this->money = money;
}

Player::~Player()
{

}

void Player::drawCard(Deck de) {
	hand.addCard(de.getCard());
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