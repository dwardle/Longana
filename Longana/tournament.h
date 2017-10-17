#pragma once
#include"round.h"

using namespace std;

class tournament
{
public:
	tournament();
	~tournament();
	int getTournScore();
	void setTournScore();
	void setTournScore(int tScore);
	void startTourn();
	bool tournEnd(human h_player, computer c_player);
private:
	class::round gameRound;
	int tournScore;

};

