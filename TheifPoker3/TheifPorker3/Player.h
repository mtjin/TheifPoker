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
	void drawCard(Deck *de);	//카드 5장 드로우
	int getMoney();
	string getName();
	Hand getHand();
	void bet(int betMoney);  //베팅
	void race(int betMoney); //레이스
	void hold(); //홀드
	void receiveReward(int reward); //이겼을시 보상
	bool ableToParticipateIn(); //게임참가 할 수 있는지 조사( 최소금액비용 100보다 낮은금액을 가졌을 경우)
<<<<<<< HEAD
	bool swapCard(Hand *hand1, Hand *hand2, int n1, int n2); //상대방과 카드 교환
	void displayHand();
	
=======
	int swapCard(Hand *hand1, Hand *hand2, int n1, int n2); //상대방과 카드 교환
	void displayHand();
>>>>>>> 93851cb46b94d7e6db91320b0c34275a82725cf0
};

