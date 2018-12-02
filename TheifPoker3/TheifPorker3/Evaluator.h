#pragma once
#include <iostream>
#include "Player.h"

using namespace std;
class Evaluator
{
public:
	Evaluator();
	~Evaluator();
	int checkScore(Hand hand);
	bool reaperCardIn(Hand);
};

