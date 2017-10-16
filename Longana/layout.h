#pragma once
#include"stock.h"
#include"tile.h"
#include<string>
#include<iostream>

using namespace std;

class layout
{
public:
	layout();
	~layout();
	void setLayout();
	void placeTile(char placement, tile tilePlaced);
	//void getLayout(char a_layout[3][58]);
	vector<tile> getLayout();
	tile getOpenLeft();
	tile getOpenRight();
	void placeEngineTile(int a_player, tile engineTile);
	string getLayoutString();
	void setTotalLayout(vector<tile> layoutTiles);
	void splitLayout(tile engine);


private:
	stock boneyard;
	vector<tile> l_playedTiles;
	vector<tile> r_playedTiles;
	vector<tile> totalLayout;
	char playedTiles[3][58];
	const int LAYOUT_MAX = 58;
};

