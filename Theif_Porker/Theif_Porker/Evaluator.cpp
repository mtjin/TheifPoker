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

int Evaluator::checkScore(Hand hand) {  //�÷��̾��� player.getHand()�� �Ű������� ����
	int arr[5];
	int score = 0;
	for (int i = 0; i < hand.getCardCount ; i++) {  //�տ�����ִ� ī�尪���� �迭�� �����
		arr[i] = hand.readCard().getRank();
	}

	for (int i = 0; ) {

	}
	
}
