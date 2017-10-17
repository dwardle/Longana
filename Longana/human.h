#pragma once
#include "player.h"
#include "computer.h"
#include<string>
#include<sstream>

using namespace std;

class human : public player
{
public:
	human();
	~human();
	void setHumanTurn(bool turn);
	bool hasTile(tile selectedTile);
	bool isHumanTurn();
	void play(layout& gameLayout, computer computerPlayer, bool lastPlayerPass);
	tile selectTile();
	tile parseTileInput(string selectedTile);
	bool validatePlay(tile openTile, tile& playedTile, char placement);
	char tilePlacement();
	void helpMode(computer computerPlayer, layout gameLayout, bool lastPlayerPass);
private:
	bool humanTurn;
	bool inHelpMode;
};

