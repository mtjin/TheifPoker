#pragma once
#include <iostream>
class Card
{
	int rank; //ī����� 1~5
	int REAPER = 0;  //��ż��ڴ� 0�����Ѵ�.
public:
	Card();
	Card(int n);
	~Card();
	int getRank();  //ī����ھ�� �޼ҵ�
};

