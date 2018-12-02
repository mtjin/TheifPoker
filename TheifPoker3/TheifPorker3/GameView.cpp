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
#include "GameView.h"
#include "Evaluator.h"
using namespace std;

GameView::GameView()
{
}


GameView::~GameView()
{
}

void GameView::gameRun() {
	string temp_name1, temp_name2;
	int temp_money1, temp_money2;

	int roundnumber = 1;
	int dice1;	// 플레이어 1의 주사위 값
	int dice2;	// 플레이어 2의 주사위 값
	int starterplayer;  //1이면 플레이어 1선, 2면 플레이어 2선
	bool dicewinner = false;	// 주사위 게임 승패 카운터
	int input; // 사용자 인풋 값
	int score1 = 0;
	int score2 = 0;

	// 시작 문구
	cout << "도둑 포커에 오신것을 환영합니다." << endl;
	cout << "<<<<<룰은 다음과같습니다.>>>>>" << endl;
	cout << "1. 기본자금이 100원 미만이 되면 플레이어가 패배한다" << endl;
	cout << "2. 첫번째 턴 플레이어는 stay, bet, fold를 할 수있고 그 다음턴 부터는 call, bet , fold를 할 수 있다" << endl;
	cout << "3. stay는 돈을 안걸고 기본 상태로 진행하는거다" << endl;
	cout << "4. bet은 원하는 돈을 걸고 카드를 바꾸는 거다. " << endl;
	cout << "5. call은 상대방이 베팅한 돈과 똑같이 가되 카드는 안바꾸는 거다" << endl;
	cout << "6. fold는 라운드를 포기하는 거다. (기본요금 $100을 지불하는게 조건이다)" << endl;
	cout << "7. 카드를 바꿀 때 사신카드를 선택하거나 마지막 까지 사신카드를 가지고 있다면 tableMoney 2배의 돈을 내야한다. (사신카드 = 0이다 )" << endl;
	cout << endl;
	cout << endl;

	cout << "<게임방식을 선택하십시오>" << endl;
	cout << "1번: 상대 패 공개 / 2번: 상대 패 비공개 (1 or 2 입력하시오)" << endl;
	int gameRule;
	cin >> gameRule; cout << endl;
	while (1) {
		if (gameRule == 1) {

			// 이름 및 금액 설정
			cout << "플레이어 1번님의 이름을 입력해 주십시오." << endl << "이름: ";
			cin >> temp_name1;
			cout << "플레이어 1번님의 초기 금액을 입력해 주십시오." << endl << "금액: ";
			cin >> temp_money1;
			cout << endl;

			cout << "플레이어 2번님의 이름을 입력해 주십시오." << endl << "이름: ";
			cin >> temp_name2;
			cout << "플레이어 2번님의 초기 금액을 입력해 주십시오." << endl << "금액: ";
			cin >> temp_money2;
			cout << endl;

			//플레이어 생성
			Player player1(temp_name1, temp_money1);
			Player player2(temp_name2, temp_money2);;

			//주사위 굴리기 시작순서 정하기
			while (1) {
				(srand((unsigned int)time(0)));
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


			//이밸류에이터 생성
			Evaluator eval;

			//덱생성
			cout << "덱을 생성합니다." << endl << endl;
			Deck deck;

			//덱셔플
			cout << "덱을 셔플합니다." << endl << endl;
			deck.shuffle();

			//테이블 머니 생성
			int tableMoney = 0;
			int betMoney;
			int totalPlayer1_Money = 0;
			int totalPlayer2_Money = 0;
			int myCard, yourCard; //카드 고를시 나의 카드, 상대방 카드
			bool isCanBetting = true; //베팅할 금액이있는지
			int roundNum = 0; //라운드수 (4라운드 이상이면 끝냄)
			bool roundOn = true;	//라운드 카운터


			//자금확인
			cout << player1.getName() << " 님의 자금: $" << player1.getMoney() << endl;
			cout << player2.getName() << " 님의 자금: $" << player2.getMoney() << endl;


			// 카드 드로우
			cout << "카드를 드로우 합니다!" << endl;
			player1.drawCard(&deck);
			player2.drawCard(&deck);
			Hand hand1 = player1.getHand();
			Hand hand2 = player2.getHand();




			while (player1.ableToParticipateIn() || player2.ableToParticipateIn()) {

				//현재잔액 공개
				player1.displayMoney();
				player2.displayMoney();
				cout << endl;

				//손카드 버리기 및 새카드받기 (리셋)
				player1.clearHand();
				player2.clearHand();
				player1.drawCard(&deck);
				player2.drawCard(&deck);
				hand1 = player1.getHand();
				hand2 = player2.getHand();

				if (!(player1.ableToParticipateIn())) {
					cout << player1.getName() << "은 최소자본($100)이 없으므로 패배하였습니다." << endl;
					cout << player2.getName() << "가 최종승리자입니다. 축하드립니다!!" << endl;
					break;
				}
				if (!(player2.ableToParticipateIn())) {
					cout << player2.getName() << "은 최소자본($100)이 없으므로 패배하였습니다." << endl;
					cout << player1.getName() << "가 최종승리자입니다. 축하드립니다!!" << endl;
					break;
				}

				roundOn = true;	//라운드 카운터 초기화
				roundNum = 0; //라운터 턴 초기화
				totalPlayer1_Money = 0;
				totalPlayer2_Money = 0;
				betMoney = 0;
				tableMoney = 0;

				// 첫번째 라운드 첫순서 진행

				while (roundOn && roundNum++ < 4) {

					//몇턴인지 알림
					cout << endl;
					cout << "---------------" << roundNum << "턴 입니다." << "----------------" << endl;
					cout << player1.getName() << " 님의 패" << endl;
					hand1.displayHand();
					cout << player2.getName() << " 님의 패" << endl;
					hand2.displayHand();

					isCanBetting = true; //초기화

					// 1번플레이어 차례 첫턴
					if (starterplayer == 1 && roundNum == 1) {
						cout << endl;
						cout << player1.getName() << "님의 차례입니다." << endl;
						while (1) {
							//betMoney = 0; // 베팅머니 초기화
							cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 스테이, 2.베팅, 3. 홀드): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									roundOn = player1.stay();
									starterplayer = 2;
									break;
								case 2:
									while (isCanBetting) {
										cout << "베팅하실 금액을 입력하여 주십시오. (금액단위$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player1.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;

									cout << "교환하실 자신의 카드를 선택해 주십시오(0~3): " << endl;
									cin >> myCard;
									cout << "교환하실 상대방의 카드를 선택해 주십시오(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player1.swapCard(&hand1, &hand2, myCard, yourCard); // 카드 교환

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//사신카드 안뽑을 경우	
										cout << player1.getName() << "님의 " << myCard + 1 << "번째 카드와 " << player2.getName() << "님의 " << yourCard + 1 << "번째 카드를 교환합니다." << endl;
										cout << player1.getName() << " 님의 패" << endl;
										hand1.displayHand();
										cout << player2.getName() << " 님의 패" << endl;
										hand2.displayHand();

										starterplayer = 2; //선은 2번한테감
									}
									else { //사신카드 뽑을경우
										player1.subMoney(tableMoney / 2);
										player2.addMoney(tableMoney + tableMoney / 2);
										cout << player1.getName() << "님이 사신카드를 뽑으셨습니다!" << endl;
										cout << player2.getName() << "님의 승리!!" << player2.getName() << "님이 $" << betMoney * 2 << " 를 얻었습니다!" << endl;
										roundOn = false;
										tableMoney = 0; //테이블 머니 리셋
									}
									starterplayer = 2;
									break;
								case 3:
									player1.subMoney(100);
									tableMoney += 100;
									roundOn = player1.fold(player2, tableMoney);
									player2.addMoney(tableMoney);
									tableMoney = 0; //테이블 머니 리셋
									starterplayer = 2;
									break;
								}
								break;
							}

							else {
								cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;

							}
						}
					}

					//2번플레이어 차례 첫턴
					else if (starterplayer == 2 && roundNum == 1) {
						cout << endl;
						cout << player2.getName() << "님의 차례입니다." << endl;

						while (1) {
							cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 스테이, 2.베팅, 3. 홀드): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									roundOn = player2.stay();
									starterplayer = 1;
									break;
								case 2:
									while (isCanBetting) {
										cout << "베팅하실 금액을 입력하여 주십시오. (금액단위$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player2.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;

									cout << "교환하실 자신의 카드를 선택해 주십시오(0~3): " << endl;
									cin >> myCard;
									cout << "교환하실 상대방의 카드를 선택해 주십시오(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player2.swapCard(&hand2, &hand1, myCard, yourCard); // 카드 교환

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//사신카드 안뽑을 경우	
										cout << player2.getName() << "님의 " << myCard + 1 << "번째 카드와 " << player1.getName() << "님의 " << yourCard + 1 << "번째 카드를 교환합니다." << endl;
										cout << player1.getName() << " 님의 패" << endl;
										hand1.displayHand();
										cout << player2.getName() << " 님의 패" << endl;
										hand2.displayHand();

										starterplayer = 2; //선은 2번한테감
									}
									else { //사신카드 뽑을경우
										player2.subMoney(tableMoney / 2);
										player1.addMoney(tableMoney + tableMoney / 2);
										cout << player2.getName() << "님이 사신카드를 뽑으셨습니다!" << endl;
										cout << player1.getName() << "님의 승리!!" << player2.getName() << "님이 $" << tableMoney * 2 << " 를 얻었습니다!" << endl;
										roundOn = false;
										tableMoney = 0; //테이블 머니 리셋
									}
									starterplayer = 1;
									break;
								case 3:
									player2.subMoney(100);
									tableMoney += 100;
									roundOn = player2.fold(player1, tableMoney);
									player1.addMoney(tableMoney);
									tableMoney = 0; //테이블 머니 리셋
									starterplayer = 1;
									break;
								}
								break;
							}
							else {
								cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;
							}
						}
					}


					//두번째 턴, 1번플레이어 턴일때
					else if (starterplayer == 1 && (roundNum == 2 || roundNum == 3)) {

						cout << endl;
						cout << player1.getName() << "님의 차례입니다." << endl;

						while (1) {
							cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 콜, 2.베팅, 3. 홀드): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									player1.call(betMoney);
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;
									starterplayer = 2;
									break;
								case 2:
									while (isCanBetting) {
										cout << "베팅하실 금액을 입력하여 주십시오. (금액단위$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player1.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;

									cout << "교환하실 자신의 카드를 선택해 주십시오(0~3): " << endl;
									cin >> myCard;
									cout << "교환하실 상대방의 카드를 선택해 주십시오(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player1.swapCard(&hand1, &hand2, myCard, yourCard); // 카드 교환

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//사신카드 안뽑을 경우	
										cout << player1.getName() << "님의 " << myCard + 1 << "번째 카드와 " << player2.getName() << "님의 " << yourCard + 1 << "번째 카드를 교환합니다." << endl;
										cout << player1.getName() << " 님의 패" << endl;
										hand1.displayHand();
										cout << player2.getName() << " 님의 패" << endl;
										hand2.displayHand();

										starterplayer = 2; //선은 2번한테감
									}
									else { //사신카드 뽑을경우
										player1.subMoney(tableMoney / 2);
										player2.addMoney(tableMoney + tableMoney / 2);
										cout << player1.getName() << "님이 사신카드를 뽑으셨습니다!" << endl;
										cout << player2.getName() << "님의 승리!!" << player2.getName() << "님이 $" << betMoney * 2 << " 를 얻었습니다!" << endl;
										roundOn = false;
										tableMoney = 0; //테이블 머니 리셋
									}
									starterplayer = 2;
									break;
								case 3:
									player1.subMoney(100);
									tableMoney += 100;
									roundOn = player1.fold(player2, tableMoney);
									player2.addMoney(tableMoney);
									tableMoney = 0; //테이블 머니 리셋
									starterplayer = 2;
									break;
								}
								break;
							}
							else {
								cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;
							}
						}
					}

					//2번째턴 2번플레이어순서
					else if (starterplayer == 2 && (roundNum == 2 || roundNum == 3)) {
						cout << endl;
						cout << player2.getName() << "님의 차례입니다." << endl;

						while (1) {
							cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 콜, 2.베팅, 3. 홀드): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									player2.call(betMoney);
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;
									starterplayer = 1;
									break;
								case 2:
									while (isCanBetting) {
										cout << "베팅하실 금액을 입력하여 주십시오. (금액단위$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player2.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;

									cout << "교환하실 자신의 카드를 선택해 주십시오(0~3): " << endl;
									cin >> myCard;
									cout << "교환하실 상대방의 카드를 선택해 주십시오(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player2.swapCard(&hand2, &hand1, myCard, yourCard); // 카드 교환

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//사신카드 안뽑을 경우	
										cout << player2.getName() << "님의 " << myCard + 1 << "번째 카드와 " << player1.getName() << "님의 " << yourCard + 1 << "번째 카드를 교환합니다." << endl;
										cout << player1.getName() << " 님의 패" << endl;
										hand1.displayHand();
										cout << player2.getName() << " 님의 패" << endl;
										hand2.displayHand();

										starterplayer = 2; //선은 2번한테감
									}
									else { //사신카드 뽑을경우
										player2.subMoney(tableMoney / 2);
										player1.addMoney(tableMoney + tableMoney / 2);
										cout << player2.getName() << "님이 사신카드를 뽑으셨습니다!" << endl;
										cout << player1.getName() << "님의 승리!!" << player2.getName() << "님이 $" << tableMoney * 2 << " 를 얻었습니다!" << endl;
										roundOn = false;
										tableMoney = 0; //테이블 머니 리셋
									}
									starterplayer = 1;
									break;
								case 3:
									player2.subMoney(100);
									tableMoney += 100;
									roundOn = player2.fold(player1, tableMoney);
									player1.addMoney(tableMoney);
									tableMoney = 0; //테이블 머니 리셋
									starterplayer = 1;
									break;
								}
								break;
							}
							else {
								cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;
							}
						}
					}

					//마지막턴 1번플레이어차례
					else if (starterplayer == 1 && roundNum == 4) {
						cout << endl;
						cout << player1.getName() << "님의 차례입니다." << endl;

						while (1) {
							cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 콜, 2.홀드): ";
							cin >> input; cout << endl;

							if (0 < input && input < 3) {
								switch (input) {
								case 1:
									player1.call(betMoney);
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;
									break;
								case 2:
									player1.subMoney(100);
									tableMoney += 100;
									roundOn = player1.fold(player2, tableMoney);
									player2.addMoney(tableMoney);
									tableMoney = 0; //테이블 머니 리셋
									starterplayer = 2;
									break;

								}
								break;
							}
							else {
								cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;
							}
						}
					}

					//마지막턴 2번플레이어 차례
					else if (starterplayer == 2 && roundNum == 4) {
						cout << endl;
						cout << player2.getName() << "님의 차례입니다." << endl;

						while (1) {
							cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 콜, 2.홀드): ";
							cin >> input; cout << endl;

							if (0 < input && input < 3) {
								switch (input) {
								case 1:
									player2.call(betMoney);
									totalPlayer2_Money += betMoney;
									tableMoney += betMoney;
									break;
								case 2:
									player2.subMoney(100);
									tableMoney += 100;
									roundOn = player2.fold(player1, tableMoney);
									player1.addMoney(tableMoney);
									tableMoney = 0; //테이블 머니 리셋
									starterplayer = 1;
									break;
								}
								break;
							}
							else {
								cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;
							}
						}
					}

					// final라운드  종료 후
					if (roundNum == 4 && roundOn == true) {

						cout << "모든 라운드가 종료되었습니다. 점수를 집계합니다." << endl;
						score1 = eval.checkScore(hand1);
						score2 = eval.checkScore(hand2);
						cout << player1.getName() << " 님의 패" << endl;
						hand1.displayHand();
						cout << player2.getName() << " 님의 패" << endl;
						hand2.displayHand();

						if (score1 == score2) {
							cout << player1.getName() << " 점수: " << score1 << "   " << player2.getName() << " 점수: " << score2 << endl;
							player1.addMoney(totalPlayer1_Money);
							player2.addMoney(totalPlayer2_Money);
							cout << "무승부입니다" << endl;
						}
						if (score1 > score2) {
							cout << player1.getName() << " 점수: " << score1 << "   " << player2.getName() << " 점수: " << score2 << endl;
							cout << player1.getName() << " 승리 " << endl;
							if (score2 == -1) { //사신카드
								cout << "사신카드를 들고있었으므로 2배 패널티가 적용됩니다" << endl;
								player1.addMoney(tableMoney + tableMoney / 2);
								player2.subMoney(tableMoney / 2);
							}
							else {
								player1.addMoney(tableMoney);
							}
							starterplayer = 1;
						}
						if (score1 < score2) {
							cout << player1.getName() << " 점수: " << score1 << "   " << player2.getName() << " 점수: " << score2 << endl;
							cout << player2.getName() << "승리" << endl;
							if (score1 == -1) { //사신카드
								cout << "사신카드를 들고있었으므로 2배 패널티가 적용됩니다" << endl;
								player2.addMoney(tableMoney + tableMoney / 2);
								player1.subMoney(tableMoney / 2);
							}
							else {
								player2.addMoney(tableMoney);
							}

							starterplayer = 2;
						}
						tableMoney = 0;
						roundOn = false;
					}
				}

			}
		}
		else if (gameRule == 2) {
			cout << "상대방 패 비공개 모드를 선택하였습니다" << endl;

			// 이름 및 금액 설정
			cout << "플레이어 1번님의 이름을 입력해 주십시오." << endl << "이름: ";
			cin >> temp_name1;
			cout << "플레이어 1번님의 초기 금액을 입력해 주십시오." << endl << "금액: ";
			cin >> temp_money1;
			cout << endl;

			cout << "플레이어 2번님의 이름을 입력해 주십시오." << endl << "이름: ";
			cin >> temp_name2;
			cout << "플레이어 2번님의 초기 금액을 입력해 주십시오." << endl << "금액: ";
			cin >> temp_money2;
			cout << endl;

			//플레이어 생성
			Player player1(temp_name1, temp_money1);
			Player player2(temp_name2, temp_money2);;

			//주사위 굴리기 시작순서 정하기
			while (1) {
				(srand((unsigned int)time(0)));
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


			//이밸류에이터 생성
			Evaluator eval;

			//덱생성
			cout << "덱을 생성합니다." << endl << endl;
			Deck deck;

			//덱셔플
			cout << "덱을 셔플합니다." << endl << endl;
			deck.shuffle();

			//테이블 머니 생성
			int tableMoney = 0;
			int betMoney;
			int totalPlayer1_Money = 0;
			int totalPlayer2_Money = 0;
			int myCard, yourCard; //카드 고를시 나의 카드, 상대방 카드
			bool isCanBetting = true; //베팅할 금액이있는지
			int roundNum = 0; //라운드수 (4라운드 이상이면 끝냄)
			bool roundOn = true;	//라운드 카운터


			//자금확인
			cout << player1.getName() << " 님의 자금: $" << player1.getMoney() << endl;
			cout << player2.getName() << " 님의 자금: $" << player2.getMoney() << endl;


			// 카드 드로우
			cout << "카드를 드로우 합니다!" << endl;
			player1.drawCard(&deck);
			player2.drawCard(&deck);
			Hand hand1 = player1.getHand();
			Hand hand2 = player2.getHand();




			while (player1.ableToParticipateIn() || player2.ableToParticipateIn()) {

				//현재잔액 공개
				player1.displayMoney();
				player2.displayMoney();
				cout << endl;

				//손카드 버리기 및 새카드받기 (리셋)
				player1.clearHand();
				player2.clearHand();
				player1.drawCard(&deck);
				player2.drawCard(&deck);
				hand1 = player1.getHand();
				hand2 = player2.getHand();

				if (!(player1.ableToParticipateIn())) {
					cout << player1.getName() << "은 최소자본($100)이 없으므로 패배하였습니다." << endl;
					cout << player2.getName() << "가 최종승리자입니다. 축하드립니다!!" << endl;
					break;
				}
				if (!(player2.ableToParticipateIn())) {
					cout << player2.getName() << "은 최소자본($100)이 없으므로 패배하였습니다." << endl;
					cout << player1.getName() << "가 최종승리자입니다. 축하드립니다!!" << endl;
					break;
				}

				roundOn = true;	//라운드 카운터 초기화
				roundNum = 0; //라운터 턴 초기화
				totalPlayer1_Money = 0;
				totalPlayer2_Money = 0;
				betMoney = 0;
				tableMoney = 0;

				// 첫번째 라운드 첫순서 진행

				while (roundOn && roundNum++ < 4) {

					//몇턴인지 알림
					cout << endl;
					cout << "---------------" << roundNum << "턴 입니다." << "----------------" << endl;


					isCanBetting = true; //초기화

					// 1번플레이어 차례 첫턴
					if (starterplayer == 1 && roundNum == 1) {
						cout << player1.getName() << " 님의 패" << endl;
						hand1.displayHand();
						cout << player2.getName() << " 님의 패" << endl;
						hand2.displayHiddenHand();
						cout << endl;
						cout << player1.getName() << "님의 차례입니다." << endl;
						while (1) {
							//betMoney = 0; // 베팅머니 초기화
							cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 스테이, 2.베팅, 3. 홀드): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									roundOn = player1.stay();
									starterplayer = 2;
									break;
								case 2:
									while (isCanBetting) {
										cout << "베팅하실 금액을 입력하여 주십시오. (금액단위$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player1.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;

									cout << "교환하실 자신의 카드를 선택해 주십시오(0~3): " << endl;
									cin >> myCard;
									cout << "교환하실 상대방의 카드를 선택해 주십시오(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player1.swapCard(&hand1, &hand2, myCard, yourCard); // 카드 교환

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//사신카드 안뽑을 경우	
										cout << player1.getName() << "님의 " << myCard + 1 << "번째 카드와 " << player2.getName() << "님의 " << yourCard + 1 << "번째 카드를 교환합니다." << endl;
										cout << player1.getName() << " 님의 패" << endl;
										hand1.displayHand();
										cout << player2.getName() << " 님의 패" << endl;
										hand2.displayHand();

										starterplayer = 2; //선은 2번한테감
									}
									else { //사신카드 뽑을경우
										player1.subMoney(tableMoney / 2);
										player2.addMoney(tableMoney + tableMoney / 2);
										cout << player1.getName() << "님이 사신카드를 뽑으셨습니다!" << endl;
										cout << player2.getName() << "님의 승리!!" << player2.getName() << "님이 $" << betMoney * 2 << " 를 얻었습니다!" << endl;
										roundOn = false;
										tableMoney = 0; //테이블 머니 리셋
									}
									starterplayer = 2;
									break;
								case 3:
									player1.subMoney(100);
									tableMoney += 100;
									roundOn = player1.fold(player2, tableMoney);
									player2.addMoney(tableMoney);
									tableMoney = 0; //테이블 머니 리셋
									starterplayer = 2;
									break;
								}
								break;
							}

							else {
								cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;

							}
						}
					}

					//2번플레이어 차례 첫턴
					else if (starterplayer == 2 && roundNum == 1) {
						cout << player1.getName() << " 님의 패" << endl;
						hand1.displayHiddenHand();
						cout << player2.getName() << " 님의 패" << endl;
						hand2.displayHand();
						cout << endl;
						cout << player2.getName() << "님의 차례입니다." << endl;

						while (1) {
							cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 스테이, 2.베팅, 3. 홀드): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									roundOn = player2.stay();
									starterplayer = 1;
									break;
								case 2:
									while (isCanBetting) {
										cout << "베팅하실 금액을 입력하여 주십시오. (금액단위$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player2.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;

									cout << "교환하실 자신의 카드를 선택해 주십시오(0~3): " << endl;
									cin >> myCard;
									cout << "교환하실 상대방의 카드를 선택해 주십시오(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player2.swapCard(&hand2, &hand1, myCard, yourCard); // 카드 교환

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//사신카드 안뽑을 경우	
										cout << player2.getName() << "님의 " << myCard + 1 << "번째 카드와 " << player1.getName() << "님의 " << yourCard + 1 << "번째 카드를 교환합니다." << endl;
										cout << player1.getName() << " 님의 패" << endl;
										hand1.displayHand();
										cout << player2.getName() << " 님의 패" << endl;
										hand2.displayHand();

										starterplayer = 2; //선은 2번한테감
									}
									else { //사신카드 뽑을경우
										player2.subMoney(tableMoney / 2);
										player1.addMoney(tableMoney + tableMoney / 2);
										cout << player2.getName() << "님이 사신카드를 뽑으셨습니다!" << endl;
										cout << player1.getName() << "님의 승리!!" << player2.getName() << "님이 $" << tableMoney * 2 << " 를 얻었습니다!" << endl;
										roundOn = false;
										tableMoney = 0; //테이블 머니 리셋
									}
									starterplayer = 1;
									break;
								case 3:
									player2.subMoney(100);
									tableMoney += 100;
									roundOn = player2.fold(player1, tableMoney);
									player1.addMoney(tableMoney);
									tableMoney = 0; //테이블 머니 리셋
									starterplayer = 1;
									break;
								}
								break;
							}
							else {
								cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;
							}
						}
					}


					//두번째 턴, 1번플레이어 턴일때
					else if (starterplayer == 1 && (roundNum == 2 || roundNum == 3)) {
						cout << player1.getName() << " 님의 패" << endl;
						hand1.displayHand();
						cout << player2.getName() << " 님의 패" << endl;
						hand2.displayHiddenHand();
						cout << endl;
						cout << player1.getName() << "님의 차례입니다." << endl;

						while (1) {
							cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 콜, 2.베팅, 3. 홀드): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									player1.call(betMoney);
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;
									starterplayer = 2;
									break;
								case 2:
									while (isCanBetting) {
										cout << "베팅하실 금액을 입력하여 주십시오. (금액단위$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player1.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;

									cout << "교환하실 자신의 카드를 선택해 주십시오(0~3): " << endl;
									cin >> myCard;
									cout << "교환하실 상대방의 카드를 선택해 주십시오(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player1.swapCard(&hand1, &hand2, myCard, yourCard); // 카드 교환

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//사신카드 안뽑을 경우	
										cout << player1.getName() << "님의 " << myCard + 1 << "번째 카드와 " << player2.getName() << "님의 " << yourCard + 1 << "번째 카드를 교환합니다." << endl;
										cout << player1.getName() << " 님의 패" << endl;
										hand1.displayHand();
										cout << player2.getName() << " 님의 패" << endl;
										hand2.displayHand();

										starterplayer = 2; //선은 2번한테감
									}
									else { //사신카드 뽑을경우
										player1.subMoney(tableMoney / 2);
										player2.addMoney(tableMoney + tableMoney / 2);
										cout << player1.getName() << "님이 사신카드를 뽑으셨습니다!" << endl;
										cout << player2.getName() << "님의 승리!!" << player2.getName() << "님이 $" << betMoney * 2 << " 를 얻었습니다!" << endl;
										roundOn = false;
										tableMoney = 0; //테이블 머니 리셋
									}
									starterplayer = 2;
									break;
								case 3:
									player1.subMoney(100);
									tableMoney += 100;
									roundOn = player1.fold(player2, tableMoney);
									player2.addMoney(tableMoney);
									tableMoney = 0; //테이블 머니 리셋
									starterplayer = 2;
									break;
								}
								break;
							}
							else {
								cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;
							}
						}
					}

					//2번째턴 2번플레이어순서
					else if (starterplayer == 2 && (roundNum == 2 || roundNum == 3)) {
						cout << player1.getName() << " 님의 패" << endl;
						hand1.displayHiddenHand();
						cout << player2.getName() << " 님의 패" << endl;
						hand2.displayHand();
						cout << endl;
						cout << player2.getName() << "님의 차례입니다." << endl;

						while (1) {
							cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 콜, 2.베팅, 3. 홀드): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									player2.call(betMoney);
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;
									starterplayer = 1;
									break;
								case 2:
									while (isCanBetting) {
										cout << "베팅하실 금액을 입력하여 주십시오. (금액단위$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player2.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;

									cout << "교환하실 자신의 카드를 선택해 주십시오(0~3): " << endl;
									cin >> myCard;
									cout << "교환하실 상대방의 카드를 선택해 주십시오(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player2.swapCard(&hand2, &hand1, myCard, yourCard); // 카드 교환

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//사신카드 안뽑을 경우	
										cout << player2.getName() << "님의 " << myCard + 1 << "번째 카드와 " << player1.getName() << "님의 " << yourCard + 1 << "번째 카드를 교환합니다." << endl;
										cout << player1.getName() << " 님의 패" << endl;
										hand1.displayHand();
										cout << player2.getName() << " 님의 패" << endl;
										hand2.displayHand();

										starterplayer = 2; //선은 2번한테감
									}
									else { //사신카드 뽑을경우
										player2.subMoney(tableMoney / 2);
										player1.addMoney(tableMoney + tableMoney / 2);
										cout << player2.getName() << "님이 사신카드를 뽑으셨습니다!" << endl;
										cout << player1.getName() << "님의 승리!!" << player2.getName() << "님이 $" << tableMoney * 2 << " 를 얻었습니다!" << endl;
										roundOn = false;
										tableMoney = 0; //테이블 머니 리셋
									}
									starterplayer = 1;
									break;
								case 3:
									player2.subMoney(100);
									tableMoney += 100;
									roundOn = player2.fold(player1, tableMoney);
									player1.addMoney(tableMoney);
									tableMoney = 0; //테이블 머니 리셋
									starterplayer = 1;
									break;
								}
								break;
							}
							else {
								cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;
							}
						}
					}

					//마지막턴 1번플레이어차례
					else if (starterplayer == 1 && roundNum == 4) {
						cout << player1.getName() << " 님의 패" << endl;
						hand1.displayHand();
						cout << player2.getName() << " 님의 패" << endl;
						hand2.displayHiddenHand();
						cout << endl;
						cout << player1.getName() << "님의 차례입니다." << endl;

						while (1) {
							cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 콜, 2.홀드): ";
							cin >> input; cout << endl;

							if (0 < input && input < 3) {
								switch (input) {
								case 1:
									player1.call(betMoney);
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;
									break;
								case 2:
									player1.subMoney(100);
									tableMoney += 100;
									roundOn = player1.fold(player2, tableMoney);
									player2.addMoney(tableMoney);
									tableMoney = 0; //테이블 머니 리셋
									starterplayer = 2;
									break;

								}
								break;
							}
							else {
								cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;
							}
						}
					}

					//마지막턴 2번플레이어 차례
					else if (starterplayer == 2 && roundNum == 4) {
						cout << player1.getName() << " 님의 패" << endl;
						hand1.displayHiddenHand();
						cout << player2.getName() << " 님의 패" << endl;
						hand2.displayHand();
						cout << endl;
						cout << player2.getName() << "님의 차례입니다." << endl;

						while (1) {
							cout << "원하시는 행동에 맞는 번호를 선택하여 주십시오. (1. 콜, 2.홀드): ";
							cin >> input; cout << endl;

							if (0 < input && input < 3) {
								switch (input) {
								case 1:
									player2.call(betMoney);
									totalPlayer2_Money += betMoney;
									tableMoney += betMoney;
									break;
								case 2:
									player2.subMoney(100);
									tableMoney += 100;
									roundOn = player2.fold(player1, tableMoney);
									player1.addMoney(tableMoney);
									tableMoney = 0; //테이블 머니 리셋
									starterplayer = 1;
									break;
								}
								break;
							}
							else {
								cout << "잘못된 입력입니다. 다시 선택해 주세요" << endl;
							}
						}
					}

					// final라운드  종료 후
					if (roundNum == 4 && roundOn == true) {

						cout << "모든 라운드가 종료되었습니다. 점수를 집계합니다." << endl;
						score1 = eval.checkScore(hand1);
						score2 = eval.checkScore(hand2);
						cout << player1.getName() << " 님의 패" << endl;
						hand1.displayHand();
						cout << player2.getName() << " 님의 패" << endl;
						hand2.displayHand();

						if (score1 == score2) {
							cout << player1.getName() << " 점수: " << score1 << "   " << player2.getName() << " 점수: " << score2 << endl;
							player1.addMoney(totalPlayer1_Money);
							player2.addMoney(totalPlayer2_Money);
							cout << "무승부입니다" << endl;
						}
						if (score1 > score2) {
							cout << player1.getName() << " 점수: " << score1 << "   " << player2.getName() << " 점수: " << score2 << endl;
							cout << player1.getName() << " 승리 " << endl;
							if (score2 == -1) { //사신카드
								cout << "사신카드를 들고있었으므로 2배 패널티가 적용됩니다" << endl;
								player1.addMoney(tableMoney + tableMoney / 2);
								player2.subMoney(tableMoney / 2);
							}
							else {
								player1.addMoney(tableMoney);
							}
							starterplayer = 1;
						}
						if (score1 < score2) {
							cout << player1.getName() << " 점수: " << score1 << "   " << player2.getName() << " 점수: " << score2 << endl;
							cout << player2.getName() << "승리" << endl;
							if (score1 == -1) { //사신카드
								cout << "사신카드를 들고있었으므로 2배 패널티가 적용됩니다" << endl;
								player2.addMoney(tableMoney + tableMoney / 2);
								player1.subMoney(tableMoney / 2);
							}
							else {
								player2.addMoney(tableMoney);
							}

							starterplayer = 2;
						}
						tableMoney = 0;
						roundOn = false;
					}
				}

			}
		}
		else {
			cout << "번호를 잘못입력하였습니다. 1번 혹은 2번만 다시 입력해주십시오" << endl;
			cin >> gameRule; cout << endl;
		}
	}
}