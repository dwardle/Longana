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
	void addTile(tile newTile);
	void removeTile(tile handTile);
	vector<tile> getHand();
	void clearHand();
	void setHand(vector<tile> newHand);
	/*void drawTile(stock b_yard);*/
private:
	vector<tile> handTiles;
};

