#include "player.h"

using namespace std;

player::player()
{
}

player::player(stock b_yard)
{
	drawHand(b_yard);
}

player::~player()
{
}

//draw initial hand
void player::drawHand(stock b_yard)
{
	for (int i = 0; i < 8; i++)
	{
		this->playerHand.addTile(b_yard.drawTile());
	}
}

//draw single tile
void player::drawTile(stock& b_yard)
{
	//tile temp = b_yard.drawTile();
	this->playerHand.addTile(b_yard.drawTile());
}

hand player::getHand()
{
	return this->playerHand;
}

vector<tile> player::getHand2()
{
	return this->playerHand.getHand();
}

bool player::hasEngine(tile a_engine)
{
	for each(tile t in playerHand.getHand())
	{
		if (t == a_engine)
		{
			return true;
		}
	}
	return false;
}

void player::play1(tile playedTile, layout &gameLayout, char placement)
{
	if (placement == 'L')
	{
		gameLayout.placeTile(0, playedTile);
		for each(tile t in getHand2())
		{
			if (t == playedTile)
			{
				playerHand.removeTile(t);
				break;
			}
		}
	}
	else if (placement == 'R')
	{
		gameLayout.placeTile(1, playedTile);
		for each(tile t in getHand2())
		{
			if (t == playedTile)
			{
				playerHand.removeTile(t);
				break;
			}
		}
	}
}

//testing virtual function
void player::play(tile playedTile, layout &gameLayout, char placement, bool lastPlayerPass)
{
	if (placement == 'L')
	{
		gameLayout.placeTile('L', playedTile);
		this->playerHand.removeTile(playedTile);
	}
	else if (placement == 'R')
	{
		gameLayout.placeTile('R', playedTile);
		this->playerHand.removeTile(playedTile);
	}
}



void player::playEngine(char placement, layout& gameLayout, tile engineTile)
{
	gameLayout.placeTile(placement, engineTile);
	//removeTile(engineTile);
}

void player::removeTile(tile rTile)
{
	this->playerHand.removeTile(rTile);
}

bool player::canPlayTile(tile leftOpen, tile rightOpen, bool lastPlayerPass, char playerSide)
{
	int left = leftOpen.getLeftPips();
	int right = rightOpen.getRightPips();
	for each(tile t in this->playerHand.getHand())
	{
		if (playerSide == 'L')
		{
			if (t.getRightPips() == left || t.getLeftPips() == left)
			{
				return true;
			}
			else if (t.isDouble() && (t.getRightPips() == left || t.getRightPips() == right))
			{
				return true;
			}
			else if (lastPlayerPass == true && (t.getRightPips() == right || t.getLeftPips() == right))
			{
				return true;
			}
			/*else
			{
				return false;
			}*/
		}
		else if (playerSide == 'R')
		{
			if (t.getLeftPips() == right || t.getRightPips() == left)
			{
				return true;
			}
			else if (t.isDouble() && (t.getRightPips() == left || t.getRightPips() == right))
			{
				return true;
			}
			else if (lastPlayerPass == true && (t.getRightPips() == left || t.getLeftPips() == left))
			{
				return true;
			}
			/*else
			{
				return false;
			}*/
		}
	}
	return false;
}

tile player::getLastTile()
{
	return this->playerHand.getHand().back();
}