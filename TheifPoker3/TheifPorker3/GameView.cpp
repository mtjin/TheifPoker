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
	int dice1;	// �÷��̾� 1�� �ֻ��� ��
	int dice2;	// �÷��̾� 2�� �ֻ��� ��
	int starterplayer;  //1�̸� �÷��̾� 1��, 2�� �÷��̾� 2��
	bool dicewinner = false;	// �ֻ��� ���� ���� ī����
	int input; // ����� ��ǲ ��
	int score1 = 0;
	int score2 = 0;

	// ���� ����
	cout << "���� ��Ŀ�� ���Ű��� ȯ���մϴ�." << endl;
	cout << "<<<<<���� �����������ϴ�.>>>>>" << endl;
	cout << "1. �⺻�ڱ��� 100�� �̸��� �Ǹ� �÷��̾ �й��Ѵ�" << endl;
	cout << "2. ù��° �� �÷��̾�� stay, bet, fold�� �� ���ְ� �� ������ ���ʹ� call, bet , fold�� �� �� �ִ�" << endl;
	cout << "3. stay�� ���� �Ȱɰ� �⺻ ���·� �����ϴ°Ŵ�" << endl;
	cout << "4. bet�� ���ϴ� ���� �ɰ� ī�带 �ٲٴ� �Ŵ�. " << endl;
	cout << "5. call�� ������ ������ ���� �Ȱ��� ���� ī��� �ȹٲٴ� �Ŵ�" << endl;
	cout << "6. fold�� ���带 �����ϴ� �Ŵ�. (�⺻��� $100�� �����ϴ°� �����̴�)" << endl;
	cout << "7. ī�带 �ٲ� �� ���ī�带 �����ϰų� ������ ���� ���ī�带 ������ �ִٸ� tableMoney 2���� ���� �����Ѵ�. (���ī�� = 0�̴� )" << endl;
	cout << endl;
	cout << endl;

	cout << "<���ӹ���� �����Ͻʽÿ�>" << endl;
	cout << "1��: ��� �� ���� / 2��: ��� �� ����� (1 or 2 �Է��Ͻÿ�)" << endl;
	int gameRule;
	cin >> gameRule; cout << endl;
	while (1) {
		if (gameRule == 1) {

			// �̸� �� �ݾ� ����
			cout << "�÷��̾� 1������ �̸��� �Է��� �ֽʽÿ�." << endl << "�̸�: ";
			cin >> temp_name1;
			cout << "�÷��̾� 1������ �ʱ� �ݾ��� �Է��� �ֽʽÿ�." << endl << "�ݾ�: ";
			cin >> temp_money1;
			cout << endl;

			cout << "�÷��̾� 2������ �̸��� �Է��� �ֽʽÿ�." << endl << "�̸�: ";
			cin >> temp_name2;
			cout << "�÷��̾� 2������ �ʱ� �ݾ��� �Է��� �ֽʽÿ�." << endl << "�ݾ�: ";
			cin >> temp_money2;
			cout << endl;

			//�÷��̾� ����
			Player player1(temp_name1, temp_money1);
			Player player2(temp_name2, temp_money2);;

			//�ֻ��� ������ ���ۼ��� ���ϱ�
			while (1) {
				(srand((unsigned int)time(0)));
				dice1 = (int)(rand() % (6)) + 1;
				dice2 = (int)(rand() % (6)) + 1;
				cout << player1.getName() << "�� �ֻ��� ��: " << dice1 << endl;
				cout << player2.getName() << "�� �ֻ��� ��: " << dice2 << endl;
				if (dice1 < dice2)
				{
					cout << player2.getName() << "���� ���� �����ϴ�." << endl << endl;
					starterplayer = 2;
					break;
				}
				else if (dice1 > dice2)
				{
					cout << player1.getName() << "���� ���� �����ϴ�." << endl << endl;
					starterplayer = 1;
					break;
				}
				else if (dice1 == dice2)
					cout << "����! �ֻ����� �ٽ� �����ϴ�." << endl << endl;
			}


			//�̹�������� ����
			Evaluator eval;

			//������
			cout << "���� �����մϴ�." << endl << endl;
			Deck deck;

			//������
			cout << "���� �����մϴ�." << endl << endl;
			deck.shuffle();

			//���̺� �Ӵ� ����
			int tableMoney = 0;
			int betMoney;
			int totalPlayer1_Money = 0;
			int totalPlayer2_Money = 0;
			int myCard, yourCard; //ī�� ���� ���� ī��, ���� ī��
			bool isCanBetting = true; //������ �ݾ����ִ���
			int roundNum = 0; //����� (4���� �̻��̸� ����)
			bool roundOn = true;	//���� ī����


			//�ڱ�Ȯ��
			cout << player1.getName() << " ���� �ڱ�: $" << player1.getMoney() << endl;
			cout << player2.getName() << " ���� �ڱ�: $" << player2.getMoney() << endl;


			// ī�� ��ο�
			cout << "ī�带 ��ο� �մϴ�!" << endl;
			player1.drawCard(&deck);
			player2.drawCard(&deck);
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
				player1.drawCard(&deck);
				player2.drawCard(&deck);
				hand1 = player1.getHand();
				hand2 = player2.getHand();

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
					cout << "---------------" << roundNum << "�� �Դϴ�." << "----------------" << endl;
					cout << player1.getName() << " ���� ��" << endl;
					hand1.displayHand();
					cout << player2.getName() << " ���� ��" << endl;
					hand2.displayHand();

					isCanBetting = true; //�ʱ�ȭ

					// 1���÷��̾� ���� ù��
					if (starterplayer == 1 && roundNum == 1) {
						cout << endl;
						cout << player1.getName() << "���� �����Դϴ�." << endl;
						while (1) {
							//betMoney = 0; // ���øӴ� �ʱ�ȭ
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ������, 2.����, 3. Ȧ��): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									roundOn = player1.stay();
									starterplayer = 2;
									break;
								case 2:
									while (isCanBetting) {
										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player1.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(0~3): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player1.swapCard(&hand1, &hand2, myCard, yourCard); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player1.getName() << "���� " << myCard + 1 << "��° ī��� " << player2.getName() << "���� " << yourCard + 1 << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player1.subMoney(tableMoney / 2);
										player2.addMoney(tableMoney + tableMoney / 2);
										cout << player1.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player2.getName() << "���� �¸�!!" << player2.getName() << "���� $" << betMoney * 2 << " �� ������ϴ�!" << endl;
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
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ������, 2.����, 3. Ȧ��): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									roundOn = player2.stay();
									starterplayer = 1;
									break;
								case 2:
									while (isCanBetting) {
										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player2.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(0~3): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player2.swapCard(&hand2, &hand1, myCard, yourCard); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player2.getName() << "���� " << myCard + 1 << "��° ī��� " << player1.getName() << "���� " << yourCard + 1 << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player2.subMoney(tableMoney / 2);
										player1.addMoney(tableMoney + tableMoney / 2);
										cout << player2.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player1.getName() << "���� �¸�!!" << player2.getName() << "���� $" << tableMoney * 2 << " �� ������ϴ�!" << endl;
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

						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.����, 3. Ȧ��): ";
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
										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player1.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(0~3): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player1.swapCard(&hand1, &hand2, myCard, yourCard); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player1.getName() << "���� " << myCard + 1 << "��° ī��� " << player2.getName() << "���� " << yourCard + 1 << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player1.subMoney(tableMoney / 2);
										player2.addMoney(tableMoney + tableMoney / 2);
										cout << player1.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player2.getName() << "���� �¸�!!" << player2.getName() << "���� $" << betMoney * 2 << " �� ������ϴ�!" << endl;
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

						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.����, 3. Ȧ��): ";
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
										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player2.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(0~3): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player2.swapCard(&hand2, &hand1, myCard, yourCard); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player2.getName() << "���� " << myCard + 1 << "��° ī��� " << player1.getName() << "���� " << yourCard + 1 << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player2.subMoney(tableMoney / 2);
										player1.addMoney(tableMoney + tableMoney / 2);
										cout << player2.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player1.getName() << "���� �¸�!!" << player2.getName() << "���� $" << tableMoney * 2 << " �� ������ϴ�!" << endl;
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

						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.Ȧ��): ";
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

						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.Ȧ��): ";
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

					// final����  ���� ��
					if (roundNum == 4 && roundOn == true) {

						cout << "��� ���尡 ����Ǿ����ϴ�. ������ �����մϴ�." << endl;
						score1 = eval.checkScore(hand1);
						score2 = eval.checkScore(hand2);
						cout << player1.getName() << " ���� ��" << endl;
						hand1.displayHand();
						cout << player2.getName() << " ���� ��" << endl;
						hand2.displayHand();

						if (score1 == score2) {
							cout << player1.getName() << " ����: " << score1 << "   " << player2.getName() << " ����: " << score2 << endl;
							player1.addMoney(totalPlayer1_Money);
							player2.addMoney(totalPlayer2_Money);
							cout << "���º��Դϴ�" << endl;
						}
						if (score1 > score2) {
							cout << player1.getName() << " ����: " << score1 << "   " << player2.getName() << " ����: " << score2 << endl;
							cout << player1.getName() << " �¸� " << endl;
							if (score2 == -1) { //���ī��
								cout << "���ī�带 ����־����Ƿ� 2�� �г�Ƽ�� ����˴ϴ�" << endl;
								player1.addMoney(tableMoney + tableMoney / 2);
								player2.subMoney(tableMoney / 2);
							}
							else {
								player1.addMoney(tableMoney);
							}
							starterplayer = 1;
						}
						if (score1 < score2) {
							cout << player1.getName() << " ����: " << score1 << "   " << player2.getName() << " ����: " << score2 << endl;
							cout << player2.getName() << "�¸�" << endl;
							if (score1 == -1) { //���ī��
								cout << "���ī�带 ����־����Ƿ� 2�� �г�Ƽ�� ����˴ϴ�" << endl;
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
			cout << "���� �� ����� ��带 �����Ͽ����ϴ�" << endl;

			// �̸� �� �ݾ� ����
			cout << "�÷��̾� 1������ �̸��� �Է��� �ֽʽÿ�." << endl << "�̸�: ";
			cin >> temp_name1;
			cout << "�÷��̾� 1������ �ʱ� �ݾ��� �Է��� �ֽʽÿ�." << endl << "�ݾ�: ";
			cin >> temp_money1;
			cout << endl;

			cout << "�÷��̾� 2������ �̸��� �Է��� �ֽʽÿ�." << endl << "�̸�: ";
			cin >> temp_name2;
			cout << "�÷��̾� 2������ �ʱ� �ݾ��� �Է��� �ֽʽÿ�." << endl << "�ݾ�: ";
			cin >> temp_money2;
			cout << endl;

			//�÷��̾� ����
			Player player1(temp_name1, temp_money1);
			Player player2(temp_name2, temp_money2);;

			//�ֻ��� ������ ���ۼ��� ���ϱ�
			while (1) {
				(srand((unsigned int)time(0)));
				dice1 = (int)(rand() % (6)) + 1;
				dice2 = (int)(rand() % (6)) + 1;
				cout << player1.getName() << "�� �ֻ��� ��: " << dice1 << endl;
				cout << player2.getName() << "�� �ֻ��� ��: " << dice2 << endl;
				if (dice1 < dice2)
				{
					cout << player2.getName() << "���� ���� �����ϴ�." << endl << endl;
					starterplayer = 2;
					break;
				}
				else if (dice1 > dice2)
				{
					cout << player1.getName() << "���� ���� �����ϴ�." << endl << endl;
					starterplayer = 1;
					break;
				}
				else if (dice1 == dice2)
					cout << "����! �ֻ����� �ٽ� �����ϴ�." << endl << endl;
			}


			//�̹�������� ����
			Evaluator eval;

			//������
			cout << "���� �����մϴ�." << endl << endl;
			Deck deck;

			//������
			cout << "���� �����մϴ�." << endl << endl;
			deck.shuffle();

			//���̺� �Ӵ� ����
			int tableMoney = 0;
			int betMoney;
			int totalPlayer1_Money = 0;
			int totalPlayer2_Money = 0;
			int myCard, yourCard; //ī�� ���� ���� ī��, ���� ī��
			bool isCanBetting = true; //������ �ݾ����ִ���
			int roundNum = 0; //����� (4���� �̻��̸� ����)
			bool roundOn = true;	//���� ī����


			//�ڱ�Ȯ��
			cout << player1.getName() << " ���� �ڱ�: $" << player1.getMoney() << endl;
			cout << player2.getName() << " ���� �ڱ�: $" << player2.getMoney() << endl;


			// ī�� ��ο�
			cout << "ī�带 ��ο� �մϴ�!" << endl;
			player1.drawCard(&deck);
			player2.drawCard(&deck);
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
				player1.drawCard(&deck);
				player2.drawCard(&deck);
				hand1 = player1.getHand();
				hand2 = player2.getHand();

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
					cout << "---------------" << roundNum << "�� �Դϴ�." << "----------------" << endl;


					isCanBetting = true; //�ʱ�ȭ

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
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ������, 2.����, 3. Ȧ��): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									roundOn = player1.stay();
									starterplayer = 2;
									break;
								case 2:
									while (isCanBetting) {
										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player1.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(0~3): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player1.swapCard(&hand1, &hand2, myCard, yourCard); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player1.getName() << "���� " << myCard + 1 << "��° ī��� " << player2.getName() << "���� " << yourCard + 1 << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player1.subMoney(tableMoney / 2);
										player2.addMoney(tableMoney + tableMoney / 2);
										cout << player1.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player2.getName() << "���� �¸�!!" << player2.getName() << "���� $" << betMoney * 2 << " �� ������ϴ�!" << endl;
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
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ������, 2.����, 3. Ȧ��): ";
							cin >> input; cout << endl;

							if (0 < input && input < 4) {
								switch (input) {
								case 1:
									roundOn = player2.stay();
									starterplayer = 1;
									break;
								case 2:
									while (isCanBetting) {
										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player2.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(0~3): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player2.swapCard(&hand2, &hand1, myCard, yourCard); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player2.getName() << "���� " << myCard + 1 << "��° ī��� " << player1.getName() << "���� " << yourCard + 1 << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player2.subMoney(tableMoney / 2);
										player1.addMoney(tableMoney + tableMoney / 2);
										cout << player2.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player1.getName() << "���� �¸�!!" << player2.getName() << "���� $" << tableMoney * 2 << " �� ������ϴ�!" << endl;
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

						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.����, 3. Ȧ��): ";
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
										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player1.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer1_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(0~3): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player1.swapCard(&hand1, &hand2, myCard, yourCard); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player1.getName() << "���� " << myCard + 1 << "��° ī��� " << player2.getName() << "���� " << yourCard + 1 << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player1.subMoney(tableMoney / 2);
										player2.addMoney(tableMoney + tableMoney / 2);
										cout << player1.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player2.getName() << "���� �¸�!!" << player2.getName() << "���� $" << betMoney * 2 << " �� ������ϴ�!" << endl;
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

						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.����, 3. Ȧ��): ";
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
										cout << "�����Ͻ� �ݾ��� �Է��Ͽ� �ֽʽÿ�. (�ݾ״���$): $";
										cin >> betMoney; cout << endl;
										isCanBetting = !(player2.bet(betMoney));
									}
									tableMoney += betMoney;
									totalPlayer2_Money += betMoney;

									cout << "��ȯ�Ͻ� �ڽ��� ī�带 ������ �ֽʽÿ�(0~3): " << endl;
									cin >> myCard;
									cout << "��ȯ�Ͻ� ������ ī�带 ������ �ֽʽÿ�(0~3):" << endl;
									cin >> yourCard; cout << endl;
									roundOn = player2.swapCard(&hand2, &hand1, myCard, yourCard); // ī�� ��ȯ

									hand1.handShuffle();
									hand2.handShuffle();

									if (roundOn == true) {	//���ī�� �Ȼ��� ���	
										cout << player2.getName() << "���� " << myCard + 1 << "��° ī��� " << player1.getName() << "���� " << yourCard + 1 << "��° ī�带 ��ȯ�մϴ�." << endl;
										cout << player1.getName() << " ���� ��" << endl;
										hand1.displayHand();
										cout << player2.getName() << " ���� ��" << endl;
										hand2.displayHand();

										starterplayer = 2; //���� 2�����װ�
									}
									else { //���ī�� �������
										player2.subMoney(tableMoney / 2);
										player1.addMoney(tableMoney + tableMoney / 2);
										cout << player2.getName() << "���� ���ī�带 �����̽��ϴ�!" << endl;
										cout << player1.getName() << "���� �¸�!!" << player2.getName() << "���� $" << tableMoney * 2 << " �� ������ϴ�!" << endl;
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

						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.Ȧ��): ";
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

						while (1) {
							cout << "���Ͻô� �ൿ�� �´� ��ȣ�� �����Ͽ� �ֽʽÿ�. (1. ��, 2.Ȧ��): ";
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

					// final����  ���� ��
					if (roundNum == 4 && roundOn == true) {

						cout << "��� ���尡 ����Ǿ����ϴ�. ������ �����մϴ�." << endl;
						score1 = eval.checkScore(hand1);
						score2 = eval.checkScore(hand2);
						cout << player1.getName() << " ���� ��" << endl;
						hand1.displayHand();
						cout << player2.getName() << " ���� ��" << endl;
						hand2.displayHand();

						if (score1 == score2) {
							cout << player1.getName() << " ����: " << score1 << "   " << player2.getName() << " ����: " << score2 << endl;
							player1.addMoney(totalPlayer1_Money);
							player2.addMoney(totalPlayer2_Money);
							cout << "���º��Դϴ�" << endl;
						}
						if (score1 > score2) {
							cout << player1.getName() << " ����: " << score1 << "   " << player2.getName() << " ����: " << score2 << endl;
							cout << player1.getName() << " �¸� " << endl;
							if (score2 == -1) { //���ī��
								cout << "���ī�带 ����־����Ƿ� 2�� �г�Ƽ�� ����˴ϴ�" << endl;
								player1.addMoney(tableMoney + tableMoney / 2);
								player2.subMoney(tableMoney / 2);
							}
							else {
								player1.addMoney(tableMoney);
							}
							starterplayer = 1;
						}
						if (score1 < score2) {
							cout << player1.getName() << " ����: " << score1 << "   " << player2.getName() << " ����: " << score2 << endl;
							cout << player2.getName() << "�¸�" << endl;
							if (score1 == -1) { //���ī��
								cout << "���ī�带 ����־����Ƿ� 2�� �г�Ƽ�� ����˴ϴ�" << endl;
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
			cout << "��ȣ�� �߸��Է��Ͽ����ϴ�. 1�� Ȥ�� 2���� �ٽ� �Է����ֽʽÿ�" << endl;
			cin >> gameRule; cout << endl;
		}
	}
}