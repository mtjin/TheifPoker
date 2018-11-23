#pragma once
#include <iostream>
#include "Card.h"
#include <string>
#include <vector>
using namespace std;;
class Deck
{
private:
	//Card deck[20];
	vector<Card> deck;
	int randNum, tmp; //셔플할때 쓸 변수
	int drawPointer; //카드읽어올 포인터역할
	int leftSize; //남은 카드 개수
public:
	Deck();
	~Deck();
	void shuffle();  //카드섞기
	//덱초기화는 그냥 메인에서 덱 생성해주는걸로대체
	void createDeck();  //덱생성
	Card getCard(); //맨 윗장 카드반환
	int getLeftSize();  //남아있는 카드 덱 카드 개수 반환
};

