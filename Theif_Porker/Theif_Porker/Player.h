#pragma once
#include <iostream>
#include <string>
#include "Hand.h"
using namespace std;
class Player
{
private:
	int money;
	string name;
	Hand hand;
public:
	Player();
	~Player();
	void drawCard();

	string getName() { return name;};
	int getMoney() { return money; };
	void setName(string name) { this->name = name; };
	void setMoney(int money) { this->money = money; };
};

