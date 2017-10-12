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
		playerHand.addTile(b_yard.drawTile());
	}
}

//draw single tile
void player::drawTile(stock& b_yard)
{
	//tile temp = b_yard.drawTile();
	playerHand.addTile(b_yard.drawTile());
}

hand player::getHand()
{
	return playerHand;
}

vector<tile> player::getHand2()
{
	return playerHand.getHand();
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

void player::play(tile playedTile, layout &gameLayout, char placement)
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