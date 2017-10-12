#pragma once
#include"round.h"

using namespace std;

class tournament
{
public:
	tournament();
	~tournament();
	void startTourn();
	void setTournScore();

private:
	class::round gameRound; //need to declair round like this because round is a function built into c++
	int tournScore;

};

