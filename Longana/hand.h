#pragma once
#include"tile.h"
#include"stock.h"
#include<vector>

using namespace std;


class hand
{
public:
	hand();
	~hand();
	vector<tile> getHand();
	void setHand(vector<tile> newHand);
	void addTile(tile newTile);
	void removeTile(tile handTile);
	void clearHand();
private:
	vector<tile> handTiles;
};

