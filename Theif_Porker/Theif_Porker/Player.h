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
	Player(string name, int money);
	~Player();
	void drawCard(Deck de);
	int getMoney();
	string getName();
	Hand getHand();
};

