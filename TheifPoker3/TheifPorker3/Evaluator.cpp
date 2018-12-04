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


int Evaluator::checkScore(Hand tmphand) {
	int arr[4];
	int score = 0;	// ����. ��ī�� = 1, Ʈ���� = 2, ��Ʈ����Ʈ = 3, ��ī�� = 4, ��� = 0
	for (int i = 0; i < tmphand.getCardcount() ; i++) {  //�տ�����ִ� ī�尪���� �迭�� �����
		arr[i] = tmphand.getCard(i).getRank();
	}
	
	sort(arr, arr + 4);	// ������ �и� ���ʺ��� ���� ���ڴ�� ����

	if (arr[0] == 0) {	// ���ī�� ����
		return -1;
	}
	else if (arr[0] == 1 && arr[1] == 2 && arr[2] == 3 && arr[3] == 4) {
		return 3;
	}
	else if (arr[0] == 2 && arr[1] == 3 && arr[2] == 4 && arr[3] == 5) {
		return 3;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = i + 1; j < 4; j++) {
				if (arr[i] == arr[j]) {		// �����
					if (i == 2) {
						return 1;
					}
					else if (arr[i] == arr[j+1]) {		// Ʈ����
						if (i == 1) {
							return 2;
						}
						else if (arr[i] == arr[j+2]) {		// ��ī��
							return 4;
						}
						
						return 2;
					}
					
					return 1;
				}
			}
		}
	}
	return 0;  //�������� ī���ΰ��
}

string Evaluator::scoreCard(int score) {
	string temp;
	switch (score) {
	case 1:
		temp = "�����";
		break;
	case 2:
		temp = "Ʈ����";
		break;
	case 3:
		temp = "��Ʈ����Ʈ";
		break;
	case 4:
		temp = "��ī��";
		break;
	case -1:
		temp = "��� ī��";
		break;
	case 0:
		temp = "���� ����";
		break;
	}
	return temp;						
}


