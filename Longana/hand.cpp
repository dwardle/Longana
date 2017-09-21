#include "hand.h"

using namespace std;

hand::hand()
{
}


hand::~hand()
{
}


void hand::addTile(tile newTile)
{
	handTiles.push_back(newTile);
}

void hand::removeTile(tile handTile)
{
	tile temp;
	for (vector<tile>::iterator it = handTiles.begin(); it != handTiles.end(); it++)
	{
		 temp = *it;
		 /*int x;
		 x = temp.getLeftPips();*/
		 if ((temp.getLeftPips() == handTile.getLeftPips()) && (temp.getRightPips() == handTile.getRightPips()))
		 {
			 handTiles.erase(it);
		 }
		 else if ((temp.getLeftPips() == handTile.getRightPips()) && (temp.getRightPips() == handTile.getLeftPips()))
		 {
			 handTiles.erase(it);
		 }
	}
	system("pause");
}


vector<tile> hand::getHand()
{
	return handTiles;
}
