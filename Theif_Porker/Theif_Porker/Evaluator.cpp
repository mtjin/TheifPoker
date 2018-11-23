#include "pch.h"
#include "Evaluator.h"
#include <iostream>
#include <string>
#include "Player.h"


Evaluator::Evaluator()
{
}


Evaluator::~Evaluator()
{
}

int Evaluator::checkScore(Hand hand) {  //플레이어의 player.getHand()로 매개변수를 받음
	int arr[5];
	int score = 0;
	for (int i = 0; i < hand.getCardCount ; i++) {  //손에들고있던 카드값들을 배열에 담아줌
		arr[i] = hand.readCard().getRank();
	}

	for (int i = 0; ) {

	}
	
}
