#pragma once
#include<iostream>
#include"human.h"
#include"computer.h"
#include"stock.h"


using namespace std;

class round
{
public:
	round();
	round(int rNum);
	~round();
	tile getEngine();
	int getNumPasses();
	int getRoundNum();
	bool isBoneyardEmpty();
	void setNumPasses(int passes);
	void setRoundNum(int rNum);
	void setEngine(int roundNum);
	void roundStart(human& h_Player, computer& c_Player, stock& b_yard);
	bool roundEnd(human h_Player, computer c_Player, bool computerPass, bool humanPass);
	bool playerHasEngine(human h_Player, computer c_Player);
private:
	stock boneyard;
	tile engine;
	int roundNum;
	int numPasses;
	bool boneyardIsEmpty;
};

