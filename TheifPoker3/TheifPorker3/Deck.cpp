#include "pch.h"
#include "Deck.h"
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

//�� ����
Deck::Deck()
{
	cardCt = 0;
	for (int i = 1; i <= 5; i++) {
		for (int j = 0; j <4; j++) {
			Card card(i);
			deck[cardCt] = card;
			cardCt++;
		}
	}
	deck[cardCt] = 0; //��� ī��
	cardsUsed = 0;
}

//����(rand)�� ����Ͽ� ī�带 suffle
void Deck::shuffle()	
{
	for (int i = 21; i > 0; i--) {
		(srand((unsigned int)time(NULL)));
		randomnum = (int)(rand() % (i + 1));
	
		temp = deck[i];
		deck[i] = deck[randomnum];
		deck[randomnum] = temp;
	}
	cardsUsed = 0;
} 

//ī�尡 deck���� ���ɶ�, �����ִ� ī���� ���� ��ȯ
int Deck::cardsLeft()
{
	return 21 - cardsUsed;
}  

//ī�带 21�� ����Ͽ��ٸ� shuffle�ϰ� deck���� ī�带 ���� ������
Card Deck::dealCard()
{
	if (cardsUsed == 21) {
		cout << "���� �����Ǿ� ���� �����ϰ� �����մϴ�" << endl;
		shuffle();
	}
	cardsUsed++;
	return deck[cardsUsed - 1];
} 
