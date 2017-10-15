#pragma once
#include "player.h"
#include<string>
#include<sstream>

using namespace std;

class human : public player
{
public:
	human();
	~human();
	//tile play(tile leftOpen);
	void play(layout& gameLayout, bool lastPlayerPass);//play(tile playedTile, layout &gameLayout, char placement, bool lastPlayerPass);
	tile selectTile();//tile leftOpen, tile rightOpen);//, bool lastPlayerPass);
	tile parseTileInput(string selectedTile);
	bool hasTile(tile selectedTile);
	bool validatePlay(tile openTile, tile& playedTile);
	void setHumanTurn(bool turn);
	bool isHumanTurn();
	char tilePlacement();
private:
	bool humanTurn;
};

