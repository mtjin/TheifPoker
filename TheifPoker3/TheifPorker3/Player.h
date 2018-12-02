#pragma once
#include <iostream>
#include <string>
#include "Hand.h"
#include "Deck.h"

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
	void drawCard(Deck *de);	//ī�� 5�� ��ο�
	int getMoney();
	string getName();
	Hand getHand();
	void bet(int betMoney);  //����
	void race(int betMoney); //���̽�
	void hold(); //Ȧ��
	void receiveReward(int reward); //�̰����� ����
	bool ableToParticipateIn(); //�������� �� �� �ִ��� ����( �ּұݾ׺�� 100���� �����ݾ��� ������ ���)
<<<<<<< HEAD
	bool swapCard(Hand *hand1, Hand *hand2, int n1, int n2); //����� ī�� ��ȯ
	void displayHand();
	
=======
	int swapCard(Hand *hand1, Hand *hand2, int n1, int n2); //����� ī�� ��ȯ
	void displayHand();
>>>>>>> 93851cb46b94d7e6db91320b0c34275a82725cf0
};
