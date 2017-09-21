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
void player::drawTile(stock b_yard)
{
	//tile temp = b_yard.drawTile();
	playerHand.addTile(b_yard.drawTile());
}

hand player::getHand()
{
	return playerHand;
}