﻿// TheifPorker3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Game.h"

using namespace std;
int main()
{	
	Deck deck;
	Player player1("JIN", 10000);
	Player player2("YOUNG", 10000);
	deck.shuffle();

	player1.drawCard(&deck);
	player2.drawCard(&deck);
	Hand hand1 = player1.getHand();
	Hand hand2 = player2.getHand();

	cout << "Player1" << endl;
	cout << hand1.getCard(0).getRank();
	cout << hand1.getCard(1).getRank();
	cout << hand1.getCard(2).getRank();
	cout << hand1.getCard(3).getRank();
	cout << hand1.getCard(4).getRank() << endl;
    
	cout << "Player2" << endl;
	cout << hand2.getCard(0).getRank();
	cout << hand2.getCard(1).getRank();
	cout << hand2.getCard(2).getRank();
	cout << hand2.getCard(3).getRank();
	cout << hand2.getCard(4).getRank() << endl;

	cout << "SWAP: 플레이어1의 1번째 카드와 플레이어2의 3번째 카드 교환" << endl;
	player1.swapCard(&hand1, &hand2, 0, 2);

	cout << "Player1" << endl;
	cout << hand1.getCard(0).getRank();
	cout << hand1.getCard(1).getRank();
	cout << hand1.getCard(2).getRank();
	cout << hand1.getCard(3).getRank();
	cout << hand1.getCard(4).getRank() << endl;

	cout << "Player2" << endl;
	cout << hand2.getCard(0).getRank();
	cout << hand2.getCard(1).getRank();
	cout << hand2.getCard(2).getRank();
	cout << hand2.getCard(3).getRank();
	cout << hand2.getCard(4).getRank() << endl;

	cout << "Hello World!\n"; 

	
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
