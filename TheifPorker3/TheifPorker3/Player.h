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
	void drawCard(Deck de);
	int getMoney();
	string getName();
	Hand getHand();
	void bet(int betMoney);  //베팅금액
	void receiveReward(int reward); //이겼을시 보상
	bool ableToParticipateIn(); //게임참가 할 수 있는지 조사( 최소금액비용 100보다 낮은금액을 가졌을 경우)
	void swapCard(Hand hand2, int n); //상대방 손에있는(hand2) n번쨰 카드와 자신의 카드 교환
};

