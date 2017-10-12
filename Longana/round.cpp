#include "round.h"

using namespace std;


round::round()
{
	//boneyard.createBoneyard();
}


round::~round()
{
}

void round::roundStart(human h_Player, computer c_Player)
{
	boneyard.shuffleBoneyard();
	engine.setPips(6, 6);
	for (int i = 0; i < 8; i++)
	{
		h_Player.drawTile(boneyard);
		//computer player will draw a tile next to alternate draws
	}
	
	while (h_Player.hasEngine(engine) != true)
	{
		h_Player.drawTile(boneyard);
	}
}

void round::roundStart(human& h_Player, computer& c_Player, stock& b_yard)
{
	//b_yard.shuffleBoneyard();
	//engine.setPips(6, 6);
	for (int i = 0; i < 8; i++)
	{
		h_Player.drawTile(b_yard);
		c_Player.drawTile(b_yard);
		//computer player will draw a tile next to alternate draws
	}

	while (playerHasEngine(h_Player, c_Player) != true)
	{
		h_Player.drawTile(b_yard);
		c_Player.drawTile(b_yard);
	}
}

/*
The round ends when one of the following conditions is met:
	One of the players empties her/his hand.
	After the boneyard has emptied out (and not counting the pass that constitutes the last tile drawn from the boneyard), both the players pass.
*/

bool round::roundEnd(human h_Player, computer c_Player)
{
	if (h_Player.getHand2().empty() == true || c_Player.getHand2().empty() == true)
	{
		return true;
	}
	else if (boneyard.isEmpty() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void round::setEngine(int roundNum)
{
	if (roundNum > 6)
	{
		roundNum = roundNum - 7;
	}
	engine.setPips(6 - roundNum, 6 - roundNum);
}

tile round::getEngine()
{
	return engine;
}


bool round::playerHasEngine(human h_Player, computer c_Player)
{
	if (h_Player.hasEngine(engine) == true || c_Player.hasEngine(engine) == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}