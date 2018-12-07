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
#include <windows.h>
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

	int roundnumber = 1; // ���� ��
	int dice1;	// �÷��̾� 1�� �ֻ��� ��
	int dice2;	// �÷��̾� 2�� �ֻ��� ��
	int starterplayer = 0;  //1�̸� �÷��̾� 1��, 2�� �÷��̾� 2��
	bool dicewinner = false;	// �ֻ��� ���� ���� ī����
	int input; // ����� ��ǲ ��
	int score1 = 0;
	int score2 = 0;
	int gameRule; // ���Ӹ�� ������
	string scorecard1, scorecard2;

	string startingMessage[] = { "��","��","��","��","��","��","��","��","��","��"," ","��","Ŀ","��"," ","��","��","��","��"," ","ȯ","��","��","��","��","!","��","��","��","��","��","��","��","��" };


	// ���� ����
	for (int i = 0; i < 34; i++) {
		cout << startingMessage[i];
		Sleep(100);
	}
	cout << endl << endl;

	cout << "���������������������������������� ��Ŀ ��Ģ��������������������������������" << endl;
	cout << "| 1. �⺻�ڱ��� 100�� �̸��� �Ǹ� �й��մϴ�.                              |" << endl;
	cout << "| 2. ù��° ���� ù �÷��̾�� stay�� �� ���ֽ��ϴ�.                       |" << endl;
	cout << "| 3. Stay: ���� ���� �ʰ� �⺻ ���·� ���� �����Ѵ�.                       |" << endl;
	cout << "| 4. Bet: ���ϴ� �׼��� ���� �ɰ� ����� ī�带 ��ȯ �Ѵ�.               |" << endl;
	cout << "| 5. Call: ������ ������ ���� ���� �ݾ��� �����ϰ� ���� �����Ѵ�         |" << endl;
	cout << "| 6. Fold: �ش� ���忡�� �й踦 �����Ѵ�.                                |" << endl;
	cout << "|     (�⺻��� $100�� ���ݱ��� ������ ���� ������ �������� �ȴ�.)       |" << endl;
	cout << "| 7. ī�带 �ٲ� �� ���ī�带 �����ϰų� ������ ���� ���ī�带 ������    |" << endl;
	cout << "|    �ְ� �Ǹ�, Table Money�� 2�迡 �ش��ϴ� �ݾ��� �����Ѵ�.              |" << endl;
	cout << "| 8. ī�带 �ٲ� �� ���濡�� �� ī��� ���ī�带 ������ �� ����.        |" << endl;
	cout << "����������������������������������������������������������������������������" << endl << endl;

	cout << "�������������������� ��Ŀ ����������������������" << endl;
	cout << "| �����: ī�� 2���� ���ڰ� ���� ��            |" << endl;
	cout << "| Ʈ����: ī�� 3���� ���ڰ� ���� ��            |" << endl;
	cout << "| ��Ʈ����Ʈ: ī�� 4���� ���ڰ� ���޾� �ִ� �� |" << endl;
	cout << "| ��ī��: ī�� 4���� ���ڰ� ���� ��            |" << endl;
	cout << "������������������������������������������������" << endl << endl;



	cout << endl << "����Ͻ÷��� ���͸� �����ּ���..." << endl;
	cin.get();

	cout << endl;

	while (1) {
		cout << "<���ӹ���� �����Ͻʽÿ�>" << endl;
		cout << "1. �� ������� 2. �� �������� " << endl << "����: ";
		cin >> gameRule; cout << endl;
		if (gameRule == 1 || gameRule == 2)
			break;
		else
			cout << "�߸��� �Է��Դϴ�." << endl << endl;
	}

	while (1) {
		if (gameRule == 1) {

			// �̸� �� �ݾ� ����
			cout << "�÷��̾� 1������ �̸��� �Է��� �ֽʽÿ�." << endl << "�̸�: ";
			cin >> temp_name1;
			while (1) {
				cout << "�÷��̾� 1������ ���� �ݾ��� �Է��� �ֽʽÿ�." << endl << "�ݾ�: ";
				cin >> temp_money1;
				if (cin.fail()) {
					cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���" << endl << endl; // �����޼���
					cin.clear(); cin.ignore(256, '\n');
				}
				else if (temp_money1 < 100) {
					cout << "!!���� �ݾ��� $100 �̻��̿��� �մϴ�!!" << endl << endl;
				}
				else
					break;
			}

			cout << endl;

			cout << "�÷��̾� 2������ �̸��� �Է��� �ֽʽÿ�." << endl << "�̸�: ";
			cin >> temp_name2;
			while (1) {
				cout << "�÷��̾� 2������ ���� �ݾ��� �Է��� �ֽʽÿ�." << endl << "�ݾ�: ";
				cin >> temp_money2;
				if (cin.fail()) {
					cout << "!!--�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���--!!" << endl << endl; // �����޼���
					cin.clear(); cin.ignore(256, '\n');
				}
				else if (temp_money2 < 100) {
					cout << "!!---���� �ݾ��� $100 �̻��̿��� �մϴ�---!!" << endl << endl;
				}
				else
					break;
			}
			cout << endl;

			//�÷��̾� ����
			Player player1(temp_name1, temp_money1);
			Player player2(temp_name2, temp_money2);

			//�ֻ��� ������ ���ۼ��� ���ϱ�
			cout << "�ֻ����� ���� ������ ���մϴ�." << endl;
			Sleep(1000);
			while (1) {
				(srand((unsigned int)time(0)));
				dice1 = (int)(rand() % (6)) + 1;
				dice2 = (int)(rand() % (6)) + 1;
				cout << player1.getName() << "���� �ֻ��� ��: " << dice1 << endl;
				Sleep(1000);

				cout << player2.getName() << "���� �ֻ��� ��: " << dice2 << endl << endl;
				Sleep(1000);

				if (dice1 < dice2)
				{
					cout << player2.getName() << "���� ���� �����ϴ�!" << endl << endl;
					starterplayer = 2;
					cout << "-----------���͸� ������ ������ �����մϴ�----------" << endl << endl;
					cin.ignore();
					cin.get();
					break;
				}
				else if (dice1 > dice2)
				{
					cout << player1.getName() << "���� ���� �����ϴ�!" << endl << endl;
					starterplayer = 1;
					cout << "-----------���͸� ������ ������ �����մϴ�----------" << endl << endl;
					cin.ignore();
					cin.get();
					break;
				}
				else if (dice1 == dice2) {
					cout << "---����! �ֻ����� �ٽ� �������� ���͸� �����ּ���---" << endl << endl;
					cin.ignore();
					cin.get();
				}
			}


			//�̹�������� ����
			Evaluator eval;

			//������
			cout << "-----------���ӿ� ���� ���� ������ �Դϴ�-----------" << endl << endl;
			Deck deck;
			Sleep(1000);


			//������
			cout << "--------------������ ���� ������ �Դϴ�-------------" << endl << endl;
			deck.shuffle();
			Sleep(1000);


			//���̺� �Ӵ� ����
			int tableMoney = 0;
			int betMoney;
			int totalPlayer1_Money = 0;
			int totalPlayer2_Money = 0;
			int preBetMoney = 0;
			int myCard, yourCard; //ī�� ���� ���� ī��, ���� ī��
			bool isCanBetting = true; //������ �ݾ����ִ���
			int roundNum = 0; //����� (4���� �̻��̸� ����)
			bool roundOn = true;	//���� ī����
			bool isCanCall = true;
			int tmpMoney = 0;

			Hand hand1 = player1.getHand();
			Hand hand2 = player2.getHand();

			while (player1.ableToParticipateIn() || player2.ableToParticipateIn()) {

				//�����ܾ� ����
				player1.displayMoney();
				player2.displayMoney();
				cout << endl;

				//��ī�� ������ �� ��ī��ޱ� (����)
				player1.clearHand();
				player2.clearHand();

				Sleep(1000);

				if (!(player1.ableToParticipateIn())) {
					cout << player1.getName() << "�� �ּ��ں�($100)�� �����Ƿ� �й��Ͽ����ϴ�." << endl;
					cout << player2.getName() << "�� �����¸����Դϴ�. ���ϵ帳�ϴ�!!" << endl << endl;
					cout << "������ �����մϴ�.";

					cin.ignore();
					cin.get();
					exit(1);
				}
				if (!(player2.ableToParticipateIn())) {
					cout << player2.getName() << "�� �ּ��ں�($100)�� �����Ƿ� �й��Ͽ����ϴ�." << endl;
					cout << player1.getName() << "�� �����¸����Դϴ�. ���ϵ帳�ϴ�!!" << endl << endl;
					cout << "������ �����մϴ�.";

					cin.ignore();
					cin.get();
					exit(1);
				}

				//ī�� ��ο�
				cout << "ī�带 ��ο� �մϴ�!" << endl;
				player1.drawCard(&deck);
				player2.drawCard(&deck);
				hand1 = player1.getHand();
				hand2 = player2.getHand();
				Sleep(1000);


				roundOn = true;	//���� ī���� �ʱ�ȭ
				roundNum = 0; //����� �� �ʱ�ȭ
				totalPlayer1_Money = 0;
				totalPlayer2_Money = 0;
				betMoney = 0;
				tableMoney = 0;

				// ù��° ���� ù���� ����

				while (roundOn && roundNum++ < 4) {

					//�������� �˸�
					cout << endl;
					cout << "---------------" << "�� #" << roundNum << " ----------------" << endl;
					cout << player1.getName() << " ���� ��" << endl;
					hand1.displayHand();
					cout << player2.getName() << " ���� ��" << endl;
					hand2.displayHand();

					isCanBetting = true; //�ʱ�ȭ
					isCanCall = true;

					// 1���÷��̾� ���� ù��
					if (starterplayer == 1 && roundNum == 1) {
						cout << endl;
						cout << player1.getName() << "���� �����Դϴ�." << endl;
						while (1) {
							//betMoney = 0; // ���øӴ� �ʱ�ȭ
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ������, 2.����, 3. ����): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									roundOn = player1.stay();
									starterplayer = 2;
									break;
								case 2:
									while (isCanBetting) {
										//�����ܾ� ����
										player1.displayMoney();
										player2.displayMoney();
										cout << endl << endl;

										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										if (betMoney > player2.getMoney()) {
											cout << " ������ �ڱݺ��� �� ���� ������ �� �����ϴ�! " << endl;
										}
										else {
											isCanBetting = !(player1.bet(betMoney));
										}
									}
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(1~4): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(1~4):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player1.swapCard(&hand1, &hand2, myCard - 1, yourCard - 1); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player1.getName() << "���� " << myCard << "��° ī��� " << player2.getName() << "���� " << yourCard << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player1.subMoney(totalPlayer1_Money);
										player2.addMoney(totalPlayer2_Money + totalPlayer1_Money*2);
										cout << player1.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player2.getName() << "���� �¸�!!" << player2.getName() << "���� $" << totalPlayer1_Money*2 << " �� ������ϴ�!" << endl;
										roundOn = false;
										tableMoney = 0; //���̺� �Ӵ� ����
									}
									starterplayer = 2;
									break;
								case 3:
									player1.subMoney(100);
									tableMoney += 100;
									roundOn = player1.fold(player2, tableMoney);
									player2.addMoney(tableMoney);
									tableMoney = 0; //���̺� �Ӵ� ����
									starterplayer = 2;
									break;
								}
								break;
							}

							else {
								cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���" << endl;

							}
						}
					}

					//2���÷��̾� ���� ù��
					else if (starterplayer == 2 && roundNum == 1) {
						cout << endl;
						cout << player2.getName() << "���� �����Դϴ�." << endl;

						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ������, 2.����, 3. ����): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									roundOn = player2.stay();
									starterplayer = 1;
									break;
								case 2:
									while (isCanBetting) {
										//�����ܾ� ����
										player1.displayMoney();
										player2.displayMoney();
										cout << endl << endl;

										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										if (betMoney > player1.getMoney()) {
											cout << " ������ �ڱݺ��� �� ���� ������ �� �����ϴ�! " << endl;
										}
										else {
											isCanBetting = !(player2.bet(betMoney));
										}
									}
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(1~4): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(1~4):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player2.swapCard(&hand2, &hand1, myCard - 1, yourCard - 1); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player2.getName() << "���� " << myCard << "��° ī��� " << player1.getName() << "���� " << yourCard << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

									}
									else { //���ī�� �������
										player2.subMoney(totalPlayer2_Money);
										player1.addMoney(totalPlayer1_Money + totalPlayer2_Money * 2);
										cout << player2.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player1.getName() << "���� �¸�!!" << player1.getName() << "���� $" << totalPlayer2_Money * 2 << " �� ������ϴ�!" << endl;
										roundOn = false;
										tableMoney = 0; //���̺� �Ӵ� ����
									}
									starterplayer = 1;
									break;
								case 3:
									player2.subMoney(100);
									tableMoney += 100;
									roundOn = player2.fold(player1, tableMoney);
									player1.addMoney(tableMoney);
									tableMoney = 0; //���̺� �Ӵ� ����
									starterplayer = 1;
									break;
								}
								break;
							}
							else {
								cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���" << endl;
							}
						}
					}

					//�ι�° ��, 1���÷��̾� ���϶�
					else if (starterplayer == 1 && (roundNum == 2 || roundNum == 3)) {

						cout << endl;
						cout << player1.getName() << "���� �����Դϴ�." << endl;
					jump:
						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.����, 3. ����): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:

									if (betMoney > player1.getMoney()) {
										isCanCall = !(player1.call(betMoney));
										goto jump;
									}
									player1.call(betMoney);
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;
									starterplayer = 2;
									break;
								case 2:
									preBetMoney = betMoney;
									while (isCanBetting) {
										//�����ܾ� ����
										player1.displayMoney();
										player2.displayMoney();
										cout << endl << endl;

										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> tmpMoney; cout << endl;
										//cin >> betMoney; cout << endl;
										if (tmpMoney <= preBetMoney) {
											cout << "���溸�� ���� ������ �� �����ϴ�" << endl;
											goto jump;
										}
										if (tmpMoney > player2.getMoney()) {
											cout << " ������ �ڱݺ��� �� ���� ������ �� �����ϴ�! " << endl;
										}
										else {
											betMoney = tmpMoney;  // �߰����� 
											isCanBetting = !(player1.bet(betMoney));
										}
									}
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(1~4): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(1~4):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player1.swapCard(&hand1, &hand2, myCard - 1, yourCard - 1); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player1.getName() << "���� " << myCard << "��° ī��� " << player2.getName() << "���� " << yourCard << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

									}
									else { //���ī�� �������
										player1.subMoney(totalPlayer1_Money);
										player2.addMoney(totalPlayer2_Money + totalPlayer1_Money * 2);
										cout << player1.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player2.getName() << "���� �¸�!!" << player2.getName() << "���� $" << totalPlayer1_Money * 2 << " �� ������ϴ�!" << endl;
										roundOn = false;
										tableMoney = 0; //���̺� �Ӵ� ����
									}
									starterplayer = 2;
									break;
								case 3:
									player1.subMoney(100);
									tableMoney += 100;
									roundOn = player1.fold(player2, tableMoney);
									player2.addMoney(tableMoney);
									tableMoney = 0; //���̺� �Ӵ� ����
									starterplayer = 2;
									break;
								}
								break;
							}
							else {
								cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���" << endl;
							}
						}
					}

					//2��°�� 2���÷��̾����
					else if (starterplayer == 2 && (roundNum == 2 || roundNum == 3)) {
						cout << endl;
						cout << player2.getName() << "���� �����Դϴ�." << endl;
					jump1:
						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.����, 3. ����): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									if (betMoney > player2.getMoney()) {
										isCanCall = !(player2.call(betMoney));
										goto jump1;
									}
									player2.call(betMoney);
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;
									starterplayer = 1;
									break;
								case 2:
									preBetMoney = betMoney;
									while (isCanBetting) {
										//�����ܾ� ����
										player1.displayMoney();
										player2.displayMoney();
										cout << endl << endl;

										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> tmpMoney; cout << endl;
										//cin >> betMoney; cout << endl;

										if (tmpMoney <= preBetMoney) {
											cout << "���溸�� ���� ������ �� �����ϴ�" << endl;
											goto jump1;
										}
										if (tmpMoney > player1.getMoney()) {
											cout << " ������ �ڱݺ��� �� ���� ������ �� �����ϴ�! " << endl;
										}
										else {
											betMoney = tmpMoney; //�߰�����
											isCanBetting = !(player2.bet(betMoney));
										}
									}
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(1~4): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(1~4):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player2.swapCard(&hand2, &hand1, myCard - 1, yourCard - 1); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player2.getName() << "���� " << myCard << "��° ī��� " << player1.getName() << "���� " << yourCard << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player2.subMoney(totalPlayer2_Money);
										player1.addMoney(totalPlayer1_Money + totalPlayer2_Money * 2);
										cout << player2.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player1.getName() << "���� �¸�!!" << player1.getName() << "���� $" << totalPlayer2_Money * 2 << " �� ������ϴ�!" << endl;
										roundOn = false;
										tableMoney = 0; //���̺� �Ӵ� ����
									}
									starterplayer = 1;
									break;
								case 3:
									player2.subMoney(100);
									tableMoney += 100;
									roundOn = player2.fold(player1, tableMoney);
									player1.addMoney(tableMoney);
									tableMoney = 0; //���̺� �Ӵ� ����
									starterplayer = 1;
									break;
								}
								break;
							}
							else {
								cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���" << endl;
							}
						}
					}

					//�������� 1���÷��̾�����
					else if (starterplayer == 1 && roundNum == 4) {
						cout << endl;
						cout << player1.getName() << "���� �����Դϴ�." << endl;
					jump2:
						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.����): ";
							cin >> input; cout << endl;

							if (0 < input && input < 3) {
								switch (input) {
								case 1:

									if (betMoney > player1.getMoney()) {
										if ((totalPlayer1_Money + betMoney) > totalPlayer2_Money) {
											betMoney = totalPlayer2_Money - totalPlayer1_Money;
											cout << "�� �� ���� �����ϹǷ� ���ε˴ϴ�.  " << player1.getName() << "���� Call Money �� $" << betMoney << "�� ���� �˴ϴ�." << endl;
											player1.call(betMoney);
											tableMoney += betMoney;
											totalPlayer1_Money += betMoney;
											break;
										}
										isCanCall = !(player1.call(betMoney));
										goto jump2;
									}
									player1.call(betMoney);
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;
									break;
								case 2:
									player1.subMoney(100);
									tableMoney += 100;
									roundOn = player1.fold(player2, tableMoney);
									player2.addMoney(tableMoney);
									tableMoney = 0; //���̺� �Ӵ� ����
									starterplayer = 2;
									break;

								}
								break;
							}
							else {
								cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���" << endl;
							}
						}
					}

					//�������� 2���÷��̾� ����
					else if (starterplayer == 2 && roundNum == 4) {
						cout << endl;
						cout << player2.getName() << "���� �����Դϴ�." << endl;
					jump3:
						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.����): ";
							cin >> input; cout << endl;

							if (0 < input && input < 3) {
								switch (input) {
								case 1:
									if (betMoney > player2.getMoney()) {
										if ((totalPlayer2_Money + betMoney) > totalPlayer1_Money) {
											betMoney = totalPlayer1_Money - totalPlayer2_Money;
											cout << "�� �� ���� �����ϹǷ� ���ε˴ϴ�.  " << player2.getName() << "���� Call Money �� $" << betMoney << "�� ���� �˴ϴ�." << endl;
											player2.call(betMoney);
											tableMoney += betMoney;
											totalPlayer2_Money += betMoney;
											break;
										}
										isCanCall = !(player2.call(betMoney));
										goto jump3;
									}
									player2.call(betMoney);
									totalPlayer2_Money += betMoney;
									tableMoney += betMoney;
									break;
								case 2:
									player2.subMoney(100);
									tableMoney += 100;
									roundOn = player2.fold(player1, tableMoney);
									player1.addMoney(tableMoney);
									tableMoney = 0; //���̺� �Ӵ� ����
									starterplayer = 1;
									break;
								}
								break;
							}
							else {
								cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���" << endl;
							}
						}
					}

					else if (player1.getMoney() == 0 || player2.getMoney() == 0) {
						roundNum = 4; roundOn = true;
						cout << "���� �÷��̾��� ���� ���δ� ���õǾ��⶧���� �ٷ� ���и� �����ϴ�. Good Luck!" << endl << endl;
						goto Zero1;
					}

					// final����  ���� ��
					if (roundNum == 4 && roundOn == true) {
					Zero1:
						cout << "��� ���尡 ����Ǿ����ϴ�. ������ �����մϴ�." << endl;
						score1 = eval.checkScore(hand1);
						score2 = eval.checkScore(hand2);
						cout << player1.getName() << " ���� ��" << endl;
						hand1.displayHand();
						cout << player2.getName() << " ���� ��" << endl;
						hand2.displayHand();

						scorecard1 = eval.scoreCard(score1);
						scorecard2 = eval.scoreCard(score2);

						if (score1 == score2) {
							cout << player1.getName() << "���� ����: " << scorecard1 << "   " << player2.getName() << "���� ����: " << scorecard2 << endl;
							player1.addMoney(totalPlayer1_Money);
							player2.addMoney(totalPlayer2_Money);
							cout << "���º��Դϴ�" << endl;
						}
						if (score1 > score2) {
							cout << player1.getName() << "���� ����: " << scorecard1 << "   " << player2.getName() << "���� ����: " << scorecard2 << endl;
							cout << player1.getName() << " �¸� " << endl;
							if (score2 == -1) { //���ī��
								cout << "���ī�带 ����־����Ƿ� 2�� �г�Ƽ�� ����˴ϴ�" << endl;
								player1.addMoney(totalPlayer1_Money + totalPlayer2_Money * 2);
								player2.subMoney(totalPlayer2_Money);
							}
							else {
								player1.addMoney(tableMoney);
							}
							starterplayer = 1;
						}
						if (score1 < score2) {
							cout << player1.getName() << "���� ����: " << scorecard1 << "   " << player2.getName() << "���� ����: " << scorecard2 << endl;
							cout << player2.getName() << "�¸�" << endl;
							if (score1 == -1) { //���ī��
								cout << "���ī�带 ����־����Ƿ� 2�� �г�Ƽ�� ����˴ϴ�" << endl;
								player2.addMoney(totalPlayer2_Money + totalPlayer1_Money * 2);
								player1.subMoney(totalPlayer1_Money);
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

				cout << endl << "����Ͻ÷��� ���͸� �����ּ���..." << endl;
				while (1) {
					cin.ignore();
					if (cin.peek() == '\n') break;
				}
			}
		}
		else if (gameRule == 2) {
			cout << "���� �� ����� ��带 �����Ͽ����ϴ�" << endl;

			// �̸� �� �ݾ� ����
			cout << "�÷��̾� 1������ �̸��� �Է��� �ֽʽÿ�." << endl << "�̸�: ";
			cin >> temp_name1;
			while (1) {
				cout << "�÷��̾� 1������ ���� �ݾ��� �Է��� �ֽʽÿ�." << endl << "�ݾ�: ";
				cin >> temp_money1;
				if (cin.fail()) {
					cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���" << endl << endl; // �����޼���
					cin.clear(); cin.ignore(256, '\n');
				}
				else if (temp_money1 < 100) {
					cout << "!!���� �ݾ��� $100 �̻��̿��� �մϴ�!!" << endl << endl;
				}
				else
					break;
			}

			cout << endl;

			cout << "�÷��̾� 2������ �̸��� �Է��� �ֽʽÿ�." << endl << "�̸�: ";
			cin >> temp_name2;
			while (1) {
				cout << "�÷��̾� 2������ ���� �ݾ��� �Է��� �ֽʽÿ�." << endl << "�ݾ�: ";
				cin >> temp_money2;
				if (cin.fail()) {
					cout << "!!--�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���--!!" << endl << endl; // �����޼���
					cin.clear(); cin.ignore(256, '\n');
				}
				else if (temp_money2 < 100) {
					cout << "!!---���� �ݾ��� $100 �̻��̿��� �մϴ�---!!" << endl << endl;
				}
				else
					break;
			}
			cout << endl;


			//�÷��̾� ����
			Player player1(temp_name1, temp_money1);
			Player player2(temp_name2, temp_money2);;

			//�ֻ��� ������ ���ۼ��� ���ϱ�
			cout << "�ֻ����� ���� ������ ���մϴ�." << endl;
			Sleep(1000);
			while (1) {
				(srand((unsigned int)time(0)));
				dice1 = (int)(rand() % (6)) + 1;
				dice2 = (int)(rand() % (6)) + 1;
				cout << player1.getName() << "���� �ֻ��� ��: " << dice1 << endl;
				Sleep(1000);

				cout << player2.getName() << "���� �ֻ��� ��: " << dice2 << endl << endl;
				Sleep(1000);

				if (dice1 < dice2)
				{
					cout << player2.getName() << "���� ���� �����ϴ�!" << endl << endl;
					starterplayer = 2;
					cout << "-----------���͸� ������ ������ �����մϴ�----------" << endl << endl;
					cin.ignore();
					cin.get();
					break;
				}
				else if (dice1 > dice2)
				{
					cout << player1.getName() << "���� ���� �����ϴ�!" << endl << endl;
					starterplayer = 1;
					cout << "-----------���͸� ������ ������ �����մϴ�----------" << endl << endl;
					cin.ignore();
					cin.get();
					break;
				}
				else if (dice1 == dice2) {
					cout << "---����! �ֻ����� �ٽ� �������� ���͸� �����ּ���---" << endl << endl;
					cin.ignore();
					cin.get();
				}
			}


			//�̹�������� ����
			Evaluator eval;

			//������
			cout << "-----------���ӿ� ���� ���� ������ �Դϴ�-----------" << endl << endl;
			Deck deck;
			Sleep(1000);


			//������
			cout << "--------------������ ���� ������ �Դϴ�-------------" << endl << endl;
			deck.shuffle();
			Sleep(1000);


			//���̺� �Ӵ� ����
			int tableMoney = 0;
			int betMoney;
			int totalPlayer1_Money = 0;
			int totalPlayer2_Money = 0;
			int myCard, yourCard; //ī�� ���� ���� ī��, ���� ī��
			int preBetMoney = 0;
			bool isCanBetting = true; //������ �ݾ����ִ���
			bool isCanCall = true;
			int roundNum = 0; //����� (4���� �̻��̸� ����)
			bool roundOn = true;	//���� ī����

			Hand hand1 = player1.getHand();
			Hand hand2 = player2.getHand();

			while (player1.ableToParticipateIn() || player2.ableToParticipateIn()) {

				//�����ܾ� ����
				player1.displayMoney();
				player2.displayMoney();
				cout << endl;

				if (!(player1.ableToParticipateIn())) {
					cout << player1.getName() << "�� �ּ��ں�($100)�� �����Ƿ� �й��Ͽ����ϴ�." << endl;
					cout << player2.getName() << "�� �����¸����Դϴ�. ���ϵ帳�ϴ�!!" << endl;
					break;
				}
				if (!(player2.ableToParticipateIn())) {
					cout << player2.getName() << "�� �ּ��ں�($100)�� �����Ƿ� �й��Ͽ����ϴ�." << endl;
					cout << player1.getName() << "�� �����¸����Դϴ�. ���ϵ帳�ϴ�!!" << endl;
					break;
				}

				//��ī�� ������ �� ��ī��ޱ� (����)
				player1.clearHand();
				player2.clearHand();

				//ī�� ��ο�
				cout << "ī�带 ��ο� �մϴ�!" << endl;
				player1.drawCard(&deck);
				player2.drawCard(&deck);
				hand1 = player1.getHand();
				hand2 = player2.getHand();
				Sleep(1000);


				roundOn = true;	//���� ī���� �ʱ�ȭ
				roundNum = 0; //����� �� �ʱ�ȭ
				totalPlayer1_Money = 0;
				totalPlayer2_Money = 0;
				betMoney = 0;
				tableMoney = 0;

				// ù��° ���� ù���� ����

				while (roundOn && roundNum++ < 4) {

					//�������� �˸�
					cout << endl;
					cout << "---------------" << "�� #" << roundNum << " ----------------" << endl;


					isCanBetting = true; //�ʱ�ȭ
					isCanCall = true;

					// 1���÷��̾� ���� ù��
					if (starterplayer == 1 && roundNum == 1) {
						cout << player1.getName() << " ���� ��" << endl;
						hand1.displayHand();
						cout << player2.getName() << " ���� ��" << endl;
						hand2.displayHiddenHand();
						cout << endl;
						cout << player1.getName() << "���� �����Դϴ�." << endl;
						while (1) {
							//betMoney = 0; // ���øӴ� �ʱ�ȭ
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ������, 2.����, 3. ����): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									roundOn = player1.stay();
									starterplayer = 2;
									break;
								case 2:
									while (isCanBetting) {
										//�����ܾ� ����
										player1.displayMoney();
										player2.displayMoney();
										cout << endl << endl;

										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										if (betMoney > player2.getMoney()) {
											cout << " ������ �ڱݺ��� �� ���� ������ �� �����ϴ�! " << endl;
										}
										else {
											isCanBetting = !(player1.bet(betMoney));
										}
									}
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(1~4): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(1~4):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player1.swapCard(&hand1, &hand2, myCard - 1, yourCard - 1); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player1.getName() << "���� " << myCard << "��° ī��� " << player2.getName() << "���� " << yourCard << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player1.subMoney(totalPlayer1_Money);
										player2.addMoney(totalPlayer2_Money + totalPlayer1_Money * 2);
										cout << player1.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player2.getName() << "���� �¸�!!" << player2.getName() << "���� $" << totalPlayer1_Money * 2 << " �� ������ϴ�!" << endl;
										roundOn = false;
										tableMoney = 0; //���̺� �Ӵ� ����
									}
									starterplayer = 2;
									break;
								case 3:
									player1.subMoney(100);
									tableMoney += 100;
									roundOn = player1.fold(player2, tableMoney);
									player2.addMoney(tableMoney);
									tableMoney = 0; //���̺� �Ӵ� ����
									starterplayer = 2;
									break;
								}
								break;
							}

							else {
								cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���" << endl;

							}
						}
					}

					//2���÷��̾� ���� ù��
					else if (starterplayer == 2 && roundNum == 1) {
						cout << player1.getName() << " ���� ��" << endl;
						hand1.displayHiddenHand();
						cout << player2.getName() << " ���� ��" << endl;
						hand2.displayHand();
						cout << endl;
						cout << player2.getName() << "���� �����Դϴ�." << endl;

						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ������, 2.����, 3. ����): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									roundOn = player2.stay();
									starterplayer = 1;
									break;
								case 2:
									while (isCanBetting) {
										//�����ܾ� ����
										player1.displayMoney();
										player2.displayMoney();
										cout << endl << endl;

										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										if (betMoney > player1.getMoney()) {
											cout << " ������ �ڱݺ��� �� ���� ������ �� �����ϴ�! " << endl;
										}
										else {
											isCanBetting = !(player2.bet(betMoney));
										}
									}
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(1~4): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(1~4):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player2.swapCard(&hand2, &hand1, myCard - 1, yourCard - 1); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player2.getName() << "���� " << myCard << "��° ī��� " << player1.getName() << "���� " << yourCard << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player2.subMoney(totalPlayer2_Money);
										player1.addMoney(totalPlayer1_Money + totalPlayer2_Money * 2);
										cout << player2.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player1.getName() << "���� �¸�!!" << player2.getName() << "���� $" << totalPlayer2_Money*2 << " �� ������ϴ�!" << endl;
										roundOn = false;
										tableMoney = 0; //���̺� �Ӵ� ����
									}
									starterplayer = 1;
									break;
								case 3:
									player2.subMoney(100);
									tableMoney += 100;
									roundOn = player2.fold(player1, tableMoney);
									player1.addMoney(tableMoney);
									tableMoney = 0; //���̺� �Ӵ� ����
									starterplayer = 1;
									break;
								}
								break;
							}
							else {
								cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���" << endl;
							}
						}
					}

					//�ι�° ��, 1���÷��̾� ���϶�
					else if (starterplayer == 1 && (roundNum == 2 || roundNum == 3)) {
						cout << player1.getName() << " ���� ��" << endl;
						hand1.displayHand();
						cout << player2.getName() << " ���� ��" << endl;
						hand2.displayHiddenHand();
						cout << endl;
						cout << player1.getName() << "���� �����Դϴ�." << endl;
					jump4:
						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.����, 3. ����): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									if (betMoney > player1.getMoney()) {
										isCanCall = !(player1.call(betMoney));
										goto jump4;
									}
									player1.call(betMoney);
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;
									starterplayer = 2;
									break;
								case 2:
									preBetMoney = betMoney;
									while (isCanBetting) {
										//�����ܾ� ����
										player1.displayMoney();
										player2.displayMoney();
										cout << endl << endl;

										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										if (betMoney <= preBetMoney) {
											cout << "���溸�� ���� ������ �� �����ϴ�" << endl;
											goto jump4;
										}
										if (betMoney > player2.getMoney()) {
											cout << " ������ �ڱݺ��� �� ���� ������ �� �����ϴ�! " << endl;
										}
										else {
											isCanBetting = !(player1.bet(betMoney));
										}
									}
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(1~4): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(1~4):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player1.swapCard(&hand1, &hand2, myCard - 1, yourCard - 1); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player1.getName() << "���� " << myCard << "��° ī��� " << player2.getName() << "���� " << yourCard << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player1.subMoney(totalPlayer1_Money);
										player2.addMoney(totalPlayer2_Money + totalPlayer1_Money * 2);
										cout << player1.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player2.getName() << "���� �¸�!!" << player2.getName() << "���� $" << totalPlayer1_Money * 2 << " �� ������ϴ�!" << endl;
										roundOn = false;
										tableMoney = 0; //���̺� �Ӵ� ����
									}
									starterplayer = 2;
									break;
								case 3:
									player1.subMoney(100);
									tableMoney += 100;
									roundOn = player1.fold(player2, tableMoney);
									player2.addMoney(tableMoney);
									tableMoney = 0; //���̺� �Ӵ� ����
									starterplayer = 2;
									break;
								}
								break;
							}
							else {
								cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���" << endl;
							}
						}
					}

					//2��°�� 2���÷��̾����
					else if (starterplayer == 2 && (roundNum == 2 || roundNum == 3)) {
						cout << player1.getName() << " ���� ��" << endl;
						hand1.displayHiddenHand();
						cout << player2.getName() << " ���� ��" << endl;
						hand2.displayHand();
						cout << endl;
						cout << player2.getName() << "���� �����Դϴ�." << endl;
					jump5:
						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.����, 3. ����): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									if (betMoney > player2.getMoney()) {
										isCanCall = !(player2.call(betMoney));
										goto jump5;
									}
									player2.call(betMoney);
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;
									starterplayer = 1;
									break;
								case 2:
									preBetMoney = betMoney;
									while (isCanBetting) {
										//�����ܾ� ����
										player1.displayMoney();
										player2.displayMoney();
										cout << endl << endl;

										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;

										if (betMoney <= preBetMoney) {
											cout << "���溸�� ���� ������ �� �����ϴ�" << endl;
											goto jump5;
										}
										if (betMoney > player1.getMoney()) {
											cout << " ������ �ڱݺ��� �� ���� ������ �� �����ϴ�! " << endl;
										}
										else {
											isCanBetting = !(player2.bet(betMoney));
										}
									}
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(1~4): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(1~4):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player2.swapCard(&hand2, &hand1, myCard - 1, yourCard - 1); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player2.getName() << "���� " << myCard << "��° ī��� " << player1.getName() << "���� " << yourCard << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player2.subMoney(totalPlayer2_Money);
										player1.addMoney(totalPlayer1_Money + totalPlayer2_Money * 2);
										cout << player2.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player1.getName() << "���� �¸�!!" << player2.getName() << "���� $" << totalPlayer2_Money * 2 << " �� ������ϴ�!" << endl;
										roundOn = false;
										tableMoney = 0; //���̺� �Ӵ� ����
									}
									starterplayer = 1;
									break;
								case 3:
									player2.subMoney(100);
									tableMoney += 100;
									roundOn = player2.fold(player1, tableMoney);
									player1.addMoney(tableMoney);
									tableMoney = 0; //���̺� �Ӵ� ����
									starterplayer = 1;
									break;
								}
								break;
							}
							else {
								cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���" << endl;
							}
						}
					}

					//�������� 1���÷��̾�����
					else if (starterplayer == 1 && roundNum == 4) {
						cout << player1.getName() << " ���� ��" << endl;
						hand1.displayHand();
						cout << player2.getName() << " ���� ��" << endl;
						hand2.displayHiddenHand();
						cout << endl;
						cout << player1.getName() << "���� �����Դϴ�." << endl;
					jump6:
						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.����): ";
							cin >> input; cout << endl;

							if (0 < input && input < 3) {
								switch (input) {
								case 1:
									if (betMoney > player1.getMoney()) {
										if ((totalPlayer1_Money + betMoney) > totalPlayer2_Money) {
											betMoney = totalPlayer2_Money - totalPlayer1_Money;
											cout << "�� �� ���� �����ϹǷ� ���ε˴ϴ�.  " << player1.getName() << "���� Call Money �� $" << betMoney << "�� ���� �˴ϴ�." << endl;
											player1.call(betMoney);
											tableMoney += betMoney;
											totalPlayer1_Money += betMoney;
											break;
										}
										isCanCall = !(player1.call(betMoney));
										goto jump6;
									}
									player1.call(betMoney);
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;
									break;
								case 2:
									player1.subMoney(100);
									tableMoney += 100;
									roundOn = player1.fold(player2, tableMoney);
									player2.addMoney(tableMoney);
									tableMoney = 0; //���̺� �Ӵ� ����
									starterplayer = 2;
									break;

								}
								break;
							}
							else {
								cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���" << endl;
							}
						}
					}

					//�������� 2���÷��̾� ����
					else if (starterplayer == 2 && roundNum == 4) {
						cout << player1.getName() << " ���� ��" << endl;
						hand1.displayHiddenHand();
						cout << player2.getName() << " ���� ��" << endl;
						hand2.displayHand();
						cout << endl;
						cout << player2.getName() << "���� �����Դϴ�." << endl;
					jump7:
						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.����): ";
							cin >> input; cout << endl;

							if (0 < input && input < 3) {
								switch (input) {
								case 1:
									if (betMoney > player1.getMoney()) {
										if ((totalPlayer2_Money + betMoney) > totalPlayer1_Money) {
											betMoney = totalPlayer1_Money - totalPlayer2_Money;
											cout << "�� �� ���� �����ϹǷ� ���ε˴ϴ�.  " << player2.getName() << "���� Call Money �� $" << betMoney << "�� ���� �˴ϴ�." << endl;
											player2.call(betMoney);
											tableMoney += betMoney;
											totalPlayer2_Money += betMoney;
											break;
										}
										isCanCall = !(player2.call(betMoney));
										goto jump7;
									}
									player2.call(betMoney);
									totalPlayer2_Money += betMoney;
									tableMoney += betMoney;
									break;
								case 2:
									player2.subMoney(100);
									tableMoney += 100;
									roundOn = player2.fold(player1, tableMoney);
									player1.addMoney(tableMoney);
									tableMoney = 0; //���̺� �Ӵ� ����
									starterplayer = 1;
									break;
								}
								break;
							}
							else {
								cout << "�߸��� �Է��Դϴ�. �ٽ� ������ �ּ���" << endl;
							}
						}
					}

					else if (player1.getMoney() == 0 || player2.getMoney() == 0) {
						roundNum = 4; roundOn = true;
						cout << "���� �÷��̾��� ���� ���δ� ���õǾ��⶧���� �ٷ� ���и� �����ϴ�. Good Luck!" << endl << endl;
						goto Zero2;
					}

					// final����  ���� ��
					if (roundNum == 4 && roundOn == true) {
					Zero2:
						cout << "��� ���尡 ����Ǿ����ϴ�. ������ �����մϴ�." << endl;
						score1 = eval.checkScore(hand1);
						score2 = eval.checkScore(hand2);
						cout << player1.getName() << " ���� ��" << endl;
						hand1.displayHand();
						cout << player2.getName() << " ���� ��" << endl;
						hand2.displayHand();

						scorecard1 = eval.scoreCard(score1);
						scorecard2 = eval.scoreCard(score2);

						if (score1 == score2) {
							cout << player1.getName() << "���� ����: " << scorecard1 << "   " << player2.getName() << "���� ����: " << scorecard2 << endl;
							player1.addMoney(totalPlayer1_Money);
							player2.addMoney(totalPlayer2_Money);
							cout << "���º��Դϴ�" << endl;
						}
						if (score1 > score2) {
							cout << player1.getName() << "���� ����: " << scorecard1 << "   " << player2.getName() << "���� ����: " << scorecard2 << endl;
							cout << player1.getName() << " �¸� " << endl;
							if (score2 == -1) { //���ī��
								cout << "���ī�带 ����־����Ƿ� 2�� �г�Ƽ�� ����˴ϴ�" << endl;
								player1.addMoney(totalPlayer1_Money + totalPlayer2_Money * 2);
								player2.subMoney(totalPlayer2_Money);
							}
							else {
								player1.addMoney(tableMoney);
							}
							starterplayer = 1;
						}
						if (score1 < score2) {
							cout << player1.getName() << "���� ����: " << scorecard1 << "   " << player2.getName() << "���� ����: " << scorecard2 << endl;
							cout << player2.getName() << "�¸�" << endl;
							if (score1 == -1) { //���ī��
								cout << "���ī�带 ����־����Ƿ� 2�� �г�Ƽ�� ����˴ϴ�" << endl;
								player2.addMoney(totalPlayer2_Money + totalPlayer1_Money * 2);
								player1.subMoney(totalPlayer1_Money);
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

				cout << endl << "����Ͻ÷��� ���͸� �����ּ���..." << endl;
				while (1) {
					cin.ignore();
					if (cin.peek() == '\n') break;
				}
			}
		}
		else {
			cout << "��ȣ�� �߸��Է��Ͽ����ϴ�. �ٽ� �Է����ֽʽÿ�" << endl;
			cin >> gameRule; cout << endl;
		}
	}
	exit(1);
}