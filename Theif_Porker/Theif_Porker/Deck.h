#pragma once
#include <iostream>
#include "Card.h"
#include <string>
#include <vector>
using namespace std;;
class Deck
{
private:
	Card deck[20];
	//vector<Card> deck;
	int randNum, tmp; //셔플할때 쓸 변수
	int drawNum; //카드읽어올 포인터역할
public:
	Deck();
	~Deck();
	void shuffle();  //카드섞기
	//덱초기화는 그냥 메인에서 덱 생성해주는걸로대체
	void createDeck();  //덱생성
};

