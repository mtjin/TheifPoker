// Theif_Porker.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "Player.h"
#include "Human.h"
#include "Computer.h"
#include "Evaluator.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	Human player1 = new Human();
	Computer computer1 = new Computer();
	Evaluator eval1 = new Evaluator();
	string temp_name;
	int temp_money;

	int roundNumber = 1;
	int dice1;	// 플레이어 1의 주사위 값
	int dice2;	// 플레이어 2의 주사위 값
	bool diceWinner = false;	// 주사위 게임 승패 카운터

	int starter;	// 선을 갖는 사람. 1 = 컴퓨터, 2 = 플레이어



	// 시작 문구
	cout << "도둑 포커에 오신것을 환영합니다." << endl;

	// 이름 및 금액 설정
	cout << "플레이어의 이름을 입력해 주십시오." << endl << "이름: ";
	cin >> temp_name;
	player1.setName( temp_name);
	cout << endl << player1.getName() + "님의 초기 금액을 입력해 주십시오." << endl << "금액: ";
	cin >> temp_money;
	player1.setMoney( temp_money);
	cout << endl;

	// 선 정하기
	cout << "주사위 게임으로 순서를 결정합니다." << endl;
	srand(time(0));
	while (diceWinner == false)
	{
		dice1 = (rand() % 100) + 1;
		dice2 = (rand() % 100) + 1;
		cout << player1.getName() << "의 주사위 값: " << dice1 << endl;
		cout << computer1.getName() << "의 주사위 값: " << dice2 << endl;
		if (dice1 < dice2)
		{
			cout << computer1.getName() << "님이 선을 갖습니다." << endl << endl;
			starter = 1;
			diceWinner = true;
		}
		else if (dice1 > dice2)
		{
			cout << player1.getName() << "님이 선을 갖습니다." << endl << endl;
			starter = 2;
			diceWinner = true;
		}
		else if (dice1 == dice2)
			cout << "동점! 주사위를 다시 굴립니다." << endl << endl;
	}

	for (int i = roundNumber; i <= 5; i++)
	{
		// 라운드 시작
		cout << i + " 라운드를 시작합니다." << endl;
		cout << player1.getName() << " vs  Computer 1" << endl << endl;

		// 현재 정보
		cout << player1.getName() << "님의 현재 잔액: " << player1.getMoney() << endl;
		cout << computer1.getName() << "님의 현재 잔액: " << computer1.getMoney() << endl << endl;

		// 덱 생성
		cout << i + " 라운드에 쓰일 덱을 생성합니다." << endl;

		// 카드 드로우
		cout << player1.getName() << "님의 카드를 드로우 합니다." << endl;

		cout << computer1.getName() << "님의 카드를 드로우 합니다." << endl << endl;

		// 라운드 진행

		// 승패 결정
		cout << i << "라운드 끝. 승패를 결정합니다." << endl;
		cout << player1.getName() << "님의 패: " << eval1.checkScore(player1) << endl;
		cout << computer1.getName() << "님의 패: " << eval1.checkScore(computer1) << endl;

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
