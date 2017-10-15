#pragma once
#include "player.h"
class computer : public player
{
public:
	computer();
	~computer();
	void setComputerTurn(bool turn);
	bool isComputerTurn();
private:
	bool computerTurn;
};

