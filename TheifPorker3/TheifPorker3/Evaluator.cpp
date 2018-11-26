#include "pch.h"
#include "Evaluator.h"
#include "Player.h"
#include "Hand.h"
#include <iostream>
#include <string>

using namespace std;
Evaluator::Evaluator()
{
}


Evaluator::~Evaluator()
{
}

int Evaluator::checkScore(Player player) {
	int arr[5];
	int score = 0;
	Hand tmpHand = player.getHand();
	for (int i = 0; i < tmpHand.getCardcount(); i++) {  //손에들고있던 카드값들을 배열에 담아줌
		arr[i] = tmpHand.getCard(i).getRank();
	}
	
	return 0;
}
