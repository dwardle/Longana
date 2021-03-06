#include "stock.h"
#include<iostream>

using namespace std;


stock::stock()
{
	//createBoneyard();
	//shuffleBoneyard();
}


stock::~stock()
{
}

//generate all tiles in the stock
void stock::createBoneyard()
{
	tile nextTile;
	for (int i = 0; i < 7; i++)
	{
		for (int j = i; j < 7; j++)
		{
			nextTile.setPips(i, j);
			boneyard.push_back(nextTile);
		}
	}
}

//shuffle all tiles in the stock
void stock::shuffleBoneyard()
{
	srand(time(NULL));
	random_shuffle(boneyard.begin(), boneyard.end());
}

//draw a tile from the remaining tiles
tile stock::drawTile()
{
	tile temp = boneyard[0];
	boneyard.erase(boneyard.begin());
	return temp;
}

bool stock::isEmpty()
{
	return boneyard.empty();
}

vector<tile> stock::getStock()
{
	return boneyard;
}

void stock::clearBoneyard()
{
	boneyard.clear();
}

string stock::getBoneyardString()
{
	string boneyardTiles;
	for each(tile t in boneyard)
	{
		boneyardTiles += (t.getLeftPips() + 48);
		boneyardTiles += "-";
		boneyardTiles += (t.getRightPips() + 48);
		boneyardTiles += " ";
	}
	return boneyardTiles;
}

void stock::setBoneYard(vector<tile> newBoneyard)
{
	boneyard = newBoneyard;
}