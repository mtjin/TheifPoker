#include "pch.h"
#include "Card.h"


Card::Card()
{
}

Card::Card(int x) {
	rank = x;
}

//ī�� ���� ��ȯ
int Card::getRank() {
	return this->rank;
}