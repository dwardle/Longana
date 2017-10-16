#pragma once
#include"round.h"

using namespace std;

class tournament
{
public:
	tournament();
	~tournament();
	void startTourn();
	int getTournScore();
	void setTournScore();
	bool tournEnd(human h_player, computer c_player);


private:
	class::round gameRound; //need to declair round like this because round is a function built into c++
	int tournScore;

};

