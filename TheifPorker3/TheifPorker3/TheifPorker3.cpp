// TheifPorker3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include "Player.h"
#include "Evaluator.h"
#include "Game.h"
#include "Evaluator.h"

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
	cout << hand1.getCard(3).getRank()<< endl;
	cout << "Player2" << endl;
	cout << hand2.getCard(0).getRank();
	cout << hand2.getCard(1).getRank();
	cout << hand2.getCard(2).getRank();
	cout << hand2.getCard(3).getRank() << endl;

	cout << "SWAP: 플레이어1의 1번째 카드와 플레이어2의 3번째 카드 교환" << endl;
	player1.swapCard(&hand1, &hand2, 0, 2);

	cout << "Player1" << endl;
	cout << hand1.getCard(0).getRank();
	cout << hand1.getCard(1).getRank();
	cout << hand1.getCard(2).getRank();
	cout << hand1.getCard(3).getRank() << endl;

	cout << "Player2" << endl;
	cout << hand2.getCard(0).getRank();
	cout << hand2.getCard(1).getRank();
	cout << hand2.getCard(2).getRank();
	cout << hand2.getCard(3).getRank() << endl;

	Evaluator eval;
	int player1_score = eval.checkScore(hand1);
	int player2_score = eval.checkScore(hand2);

	//cout << "점수1: " << player1_score << "   점수2:" << player2_score << endl;
	if (player1_score == player2_score) {
		cout << "점수1: " << player1_score << "   점수2:" << player2_score << endl;
		cout << "무승부" << endl;
	}
	if (player1_score > player2_score) {
		cout << "점수1: " << player1_score << "   점수2:" << player2_score << endl;
		cout << "player1 승리" << endl;
	}
	if (player1_score < player2_score) {
		cout << "점수1: " << player1_score << "   점수2:" << player2_score << endl;
		cout << "player2 승리" << endl;
	}

	player1.displayHand();
	cout << "Hello World!\n"; 
	
	
	/*
	
	string temp_name1 , temp_name2;
	int temp_money1, temp_money2;

	int roundnumber = 1;
	int dice1;	// 플레이어 1의 주사위 값
	int dice2;	// 플레이어 2의 주사위 값
	int starterplayer;  //1이면 플레이어 1선, 2면 플레이어 2선
	bool dicewinner = false;	// 주사위 게임 승패 카운터
	int input;	// 키보드 인풋값
	int round = 1; // 게임 라운드 값

	Evaluator eval(); // 점수체크

	// 시작 문구
	cout << "도둑 포커에 오신것을 환영합니다." << endl;
	
	// 이름 및 금액 설정
	cout << "플레이어 1번님의 이름을 입력해 주십시오." << endl << "이름: ";
	cin >> temp_name1;
	cout << "플레이어 1번님의 초기 금액을 입력해 주십시오." << endl << "금액: ";
	cin >> temp_money1;
	cout << endl;

	cout << "플레이어 2번님의 이름을 입력해 주십시오." << endl << "이름: ";
	cin >> temp_name2;
	cout <<"플레이어 2번님의 초기 금액을 입력해 주십시오." << endl << "금액: ";
	cin >> temp_money2;
	cout << endl;

	//플레이어 생성
	Player player1(temp_name1, temp_money1);
	Player player2(temp_name2, temp_money2);

	//주사위 굴리기 시작순서 정하기
	while (1) {
		(srand((unsigned int)time(NULL)));
		dice1 = (int)(rand() % (6)) + 1;
		dice2 = (int)(rand() % (6)) + 1;
		cout << player1.getName() << "의 주사위 값: " << dice1 << endl;
		cout << player2.getName() << "의 주사위 값: " << dice2 << endl;
		if (dice1 < dice2)
		{
			cout << player2.getName() << "님이 선을 갖습니다." << endl << endl;
			starterplayer = 2;
			break;
		}
		else if (dice1 > dice2)
		{
			cout << player1.getName() << "님이 선을 갖습니다." << endl << endl;
			starterplayer = 1;
			break;
		}
		else if (dice1 == dice2)
			cout << "동점! 주사위를 다시 굴립니다." << endl << endl;
	}

	//스타터 플레이어 지정

	//덱생성
	cout << "덱을 생성합니다." << endl << endl;
	Deck deck;

	//덱셔플
	cout << "덱을 셔플합니다." << endl << endl;
	deck.shuffle();

	//게임진행(흐름)
	while (1) {
		//카드를 4장씩 드로우합니다.
		player1.drawCard(&deck);
		player2.drawCard(&deck);
<<<<<<< HEAD
		Evaluator eval;
		int player1_score = eval.checkScore(player1);
		int player2_score = eval.checkScore(player2);


		if (player1_score == player2_score) {
			cout << "무승부" << endl;
		}
		if (player1_score > player2_score) {
			cout << "player1 승리" << endl;
		}
		if (player1_score < player1_score) {
			cout << "player2 승리" << endl;
		}
		int s;
		cin >> s;
=======

		//선을 가진 플레이어 부터 차례 시작 (스테이, 베팅, 폴드)
		cout << "<라운드 #1>" << endl;
		cout << "플레이어 " << /*지정된 스타터 플레이어 << */ "님의 차례입니다." << endl;
		cout <<  /* 스타터 플레이어 << */"님의 패: "; player1.displayHand();	cout << endl;

		while (1) {
			cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 스테이, 2.베팅, 3. 홀드): ";
			cin >> input;

			if (input == 1 | input == 2 | input == 3) {
				switch (input) {
				case 1:
					/* 플레이어가 스테이를 골랐을때의 알고리즘 */
					break;
				case 2:
					/* 플레이어가 베팅을 골랐을때의 알고리즘 */
					break;
				case 3:
					/* 플레이어가 홀드를 골랐을때의 알고리즘 */
					break;
				}
				break;
			}
			else {
				cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;
			}
		}

		//게임 총 5라운드 진행
		for (int i = 1; i < 10; i++) {

			if (i%2 == 0) {
				round++;
				cout << "<라운드 #" << round << ">" << endl;
			}
			cout << "플레이어 " << /* 다음 플레이어 << */ "님의 차례입니다." << endl;
			cout <<  /* 다음 플레이어 << */ "님의 패: "; player1.displayHand();	cout << endl;

			while (1) {
				cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 스테이, 2.베팅, 3. 홀드): ";
				cin >> input;

				if (0 < input < 4) {
					switch (input) {
					case 1:
						/* 플레이어가 스테이를 골랐을때의 알고리즘 */
						break;
					case 2:
						/* 플레이어가 베팅을 골랐을때의 알고리즘 */
						break;
					case 3:
						/* 플레이어가 홀드를 골랐을때의 알고리즘 */
						break;
					}
					break;
				}
				else {
					cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;
				}
			}
		}

		// Final라운드 (5라운드) 종료 후
		cout << "모든 라운드가 종료되었습니다. 점수를 집계합니다." << endl;
		eval().checkScore(player1);
		
>>>>>>> 93851cb46b94d7e6db91320b0c34275a82725cf0
	}
	*/


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
