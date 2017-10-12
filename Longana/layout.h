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
	void placeTile(int a_player, tile tilePlaced);
	void getLayout(char a_layout[3][58]);

private:
	stock boneyard;
	vector<tile> h_playedTiles;
	vector<tile> c_playedTiles;
	char playedTiles[3][58];
	const int LAYOUT_MAX = 58;
};

