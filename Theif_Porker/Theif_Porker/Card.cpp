#include "pch.h"
#include "Card.h"


Card::Card()
{

}
Card::Card(int n) {
	rank = n;
}


Card::~Card()
{

}

int Card::getRank() {
	return rank;
}
