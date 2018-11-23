#include "pch.h"
#include <stdlib.h>
#include "Deck.h"
#include "Card.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;
Deck::Deck()
{
	drawPointer = 0;
	leftSize = 21;
}


Deck::~Deck()
{
}
void Deck::shuffle() { //카드섞기
	for (int i = 0; i < 100; i++) {
		randNum = (int)(rand() % (i + 1));  //난수생성
		//tmp = deck[i].getRank;
		//deck[i] = deck[randNum];
		//deck[randNum] = tmp;
		tmp = deck.at((i % 21)).getRank;
		deck.erase(deck.begin() + (i%21));
		deck.insert(deck.begin() + (i % 21), deck.at(randNum) );  //deck[i] = deck[randNum];
		deck.insert(deck.begin() + randNum, tmp);	//deck[randNum] = tmp;
		


	}
}
	//덱초기화는 그냥 메인에서 덱 생성해주는걸로대체
void Deck::createDeck() {  //덱생성
	for (int i = 0; i < 19; i++) {
		for (int j = 1; j <= 5; j++) { //1~5 카드 4세트만듬
			//deck[i] = Card(j);
			deck.push_back(Card(j));
		}
	}
	//deck[20] = 0; //사신
	deck.push_back(Card(0));
	drawPointer = 0; 
}

Card Deck::getCard() {
	return deck.at(drawPointer++);
}

int Deck::getLeftSize() {
	return this->leftSize;
}