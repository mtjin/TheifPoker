#include "pch.h"
#include "Evaluator.h"
#include "Player.h"
#include "Hand.h"
#include <iostream>
#include <string>
#include <algorithm>  //소팅알고리즘

using namespace std;
Evaluator::Evaluator()
{
}


Evaluator::~Evaluator()
{
}


int Evaluator::checkScore(Player player) {
	int arr[4];
	int score = 0;	// 족보. 원카드 = 1, 트리플 = 2, 스트레이트 = 3, 포카드 = 4, 사신 = 0
	Hand tmpHand = player.getHand();
	for (int i = 0; i < tmpHand.getCardcount() ; i++) {  //손에들고있던 카드값들을 배열에 담아줌
		arr[i] = tmpHand.getCard(i).getRank();
	}
	
	sort(arr, arr + 4);	// 가져온 패를 왼쪽부터 작은 숫자대로 정렬

	if (arr[0] == 0) {	// 사신카드 있음
		return score;
	}
	else if (arr[0] == 1) {
		for (int k = 0; k < 4; k++) {
			for (int l = k + 1; l < 5; l++) {
				if (arr[k] == l) {	// 스트레이트
					score = 3;
					return score;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 4; j++) {
				if (arr[i] == arr[j]) {		// 원페어
					if (arr[i] == arr[j]) {		// 트리플
						if (arr[i] == arr[j]) {		// 포카드
							score = 4;
							return score;
						}
						score = 2;
						return score;
					}
					score = 1;
					return score;
				}
			}
		}
	}
	
}

