#include "computer.h"



computer::computer()
{
}


computer::~computer()
{
}

void computer::setComputerTurn(bool turn)
{
	computerTurn = turn;
}

bool computer::isComputerTurn()
{
	return computerTurn;
}