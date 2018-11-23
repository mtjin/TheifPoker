#pragma once
#include <iostream>
#include <string>
#include "Player.h"
#include "Hand.h"

using namespace std;
class Evaluator
{
public:
	Evaluator();
	~Evaluator();
	int checkScore(Player player);
};

