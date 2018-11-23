#pragma once
#include <iostream>
#include "Deck.h"
#include "Player.h"
class Dealer
{
private:
	Deck deck;
public:
	Dealer();
	~Dealer();
	void run(Player , Player) {};
	int result(Player) {};
};

