#include "pch.h"
#include "Player.h"
#include <iostream>
#include <string>
#include "Hand.h"
#include "Deck.h"
using namespace std;

Player::Player()
{
}

//플레이어 이름과 돈 초기화
Player::Player(string name, int money) {
	this->name = name;
	this->money = money;
}

//카드 5장 드로우
void Player::drawCard(Deck *de) {	
	for (int i = 0; i < 5; i++) {
		hand.addCard(de->dealCard());
	}
}
int Player::getMoney() {
	return this->money;
}
string Player::getName() {
	return this->name;
}
Hand Player::getHand() {
	return this->hand;
}

//베팅
void Player::bet(int betMoney) {	
	if (betMoney < money)
	{
		money -= betMoney;
	}
	else {
		cout << "소지한 금액이 부족합니다" << endl;
	}
}

//보상 획득
void Player::receiveReward(int reward) {
	money += reward;
}

//참가가능한 돈이 있는지 검사
bool Player::ableToParticipateIn() {	
	if (money < 100) {
		return false;
	}
	else {
		return false;
	}
}

int Player::swapCard(Hand *hand1, Hand *hand2, int n1, int n2) {	//상대 플레이어와 카드 교환
	Card tmp1 = hand1->getCard(n1); //hand1이 갖고올 hand2의 카드 저장
	if (tmp1.getRank() == 0) {  //자신이 줄 패가 사신카드인 경우 1을 반환(바로 반칙패 만들것)
		cout << "사신카드는 상대에게 줄 수 없습니다 (반칙패)" << endl;
		return 1;
	}
	Card tmp2 = hand2->getCard(n2);	 //hand2가 갖고올 hand1의 카드 저장
	if (tmp2.getRank() == 0) {	//상대의 사신코드를 골랐을 경우 (바로 패)
		return 1;
	}
	hand1->changeCard(n1, tmp2);
	hand2->changeCard(n2, tmp1);

	return 0;
}
