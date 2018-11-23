#pragma once
#include <iostream>
class Card
{
	int rank; //카드숫자 1~5
	int REAPER = 0;  //사신숫자는 0으로한다.
public:
	Card();
	Card(int n);
	~Card();
	int getRank();  //카드숫자얻는 메소드
};

