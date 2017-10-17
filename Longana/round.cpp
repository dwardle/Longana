#include "round.h"

using namespace std;


round::round()
{
	//boneyard.createBoneyard();
}

round::round(int rNum)
{
	roundNum = rNum;
	numPasses = 0;
	boneyardIsEmpty = false;
}


round::~round()
{
}

//void round::roundStart(human h_Player, computer c_Player)
//{
//	boneyard.shuffleBoneyard();
//	engine.setPips(6, 6);
//	for (int i = 0; i < 8; i++)
//	{
//		h_Player.drawTile(boneyard);
//		//computer player will draw a tile next to alternate draws
//	}
//	
//	while (h_Player.hasEngine(engine) != true)
//	{
//		h_Player.drawTile(boneyard);
//	}
//}

void round::roundStart(human& h_Player, computer& c_Player, stock& b_yard)
{
	cout << "Round " << roundNum << " start" << endl << endl;
	cout << "Players draw their hands from the boneyard" << endl << endl;
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

	if (h_Player.hasEngine(engine))
	{
		h_Player.setHumanTurn(true);
		c_Player.setComputerTurn(false);
		cout << "Human player has the engine" << endl;
		//cout << "Human player places the engine tile" << endl << endl;
	}
	else
	{
		c_Player.setComputerTurn(true);
		h_Player.setHumanTurn(false);
		cout << "Computer player has the engine tile" << endl;
		//cout << "Computer player places the engine tile" << endl << endl;
	}
}

/*
The round ends when one of the following conditions is met:
	One of the players empties her/his hand.
	After the boneyard has emptied out (and not counting the pass that constitutes the last tile drawn from the boneyard), both the players pass.
*/

bool round::roundEnd(human h_Player, computer c_Player, bool computerPass, bool humanPass)
{
	if (h_Player.getHand2().empty() == true || c_Player.getHand2().empty() == true)
	{
		cout << "Round end because a player emptied their hand" << endl;
		return true;
	}
	else if (boneyard.isEmpty() == true && (humanPass == true || computerPass == true))
	{
		if (boneyardIsEmpty == false)
		{
			boneyardIsEmpty = true;
		}
		else if (boneyardIsEmpty == true && numPasses == 2)
		{
			return true;
		}
		/*else if (boneyardIsEmpty && (humanPass && computerPass))
		{
			numPasses++;
			if (numPasses == 2)
			{
				cout << "Round end because boneyard is empty and both players passed" << endl;
				return true;
			}
		}*/
		return false;
	}
	else
	{
		return false;
	}
}

void round::setEngine(int roundNum)
{
	if (roundNum > 7)
	{
		roundNum = roundNum - 7;
	}
	engine.setPips(7 - roundNum, 7 - roundNum);
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

void round::setNumPasses(int passes)
{
	numPasses = passes;
}

int round::getNumPasses()
{
	return numPasses;
}

bool round::isBoneyardEmpty()
{
	return boneyardIsEmpty;
}

void round::setRoundNum(int rNum)
{
	roundNum = rNum;
}

int round::getRoundNum()
{
	return roundNum;
}