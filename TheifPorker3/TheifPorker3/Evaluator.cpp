#include "pch.h"
#include "Evaluator.h"
#include "Player.h"
#include "Hand.h"
#include <iostream>
#include <string>
#include <algorithm>  //���þ˰���

using namespace std;
Evaluator::Evaluator()
{
}


Evaluator::~Evaluator()
{
}


int Evaluator::checkScore(Player player) {
	int arr[4];
	int score = 0;	// ����. ��ī�� = 1, Ʈ���� = 2, ��Ʈ����Ʈ = 3, ��ī�� = 4, ��� = 0
	Hand tmpHand = player.getHand();
	for (int i = 0; i < tmpHand.getCardcount() ; i++) {  //�տ�����ִ� ī�尪���� �迭�� �����
		arr[i] = tmpHand.getCard(i).getRank();
	}
	
	sort(arr, arr + 4);	// ������ �и� ���ʺ��� ���� ���ڴ�� ����

	if (arr[0] == 0) {	// ���ī�� ����
		return score;
	}
	else if (arr[0] == 1) {
		for (int k = 0; k < 4; k++) {
			for (int l = k + 1; l < 5; l++) {
				if (arr[k] == l) {	// ��Ʈ����Ʈ
					score = 3;
					return score;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 4; j++) {
				if (arr[i] == arr[j]) {		// �����
					if (arr[i] == arr[j]) {		// Ʈ����
						if (arr[i] == arr[j]) {		// ��ī��
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

