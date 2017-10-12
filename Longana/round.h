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
	~round();
	//functions below may be temporary/moved to different class
	void roundStart(human h_Player, computer c_Player);
	//round start to allow the game to pass a stock to the round
	void roundStart(human& h_Player, computer& c_Player, stock& b_yard);


	bool roundEnd(human h_Player, computer c_Player);
	void setEngine(int roundNum);
	tile getEngine();
	bool playerHasEngine(human h_Player, computer c_Player);
private:
	stock boneyard;
	tile engine;
};

