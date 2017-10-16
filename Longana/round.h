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
	//functions below may be temporary/moved to different class
	void roundStart(human h_Player, computer c_Player);
	//round start to allow the game to pass a stock to the round
	void roundStart(human& h_Player, computer& c_Player, stock& b_yard);


	bool roundEnd(human h_Player, computer c_Player, bool computerPass, bool humanPass);
	void setEngine(int roundNum);
	tile getEngine();
	bool playerHasEngine(human h_Player, computer c_Player);
	void setNumPasses(int passes);
	int getNumPasses();
	bool isBoneyardEmpty();
	void setRoundNum(int rNum);
	int getRoundNum();
private:
	stock boneyard;
	tile engine;
	int roundNum;
	int numPasses;
	bool boneyardIsEmpty;
};

