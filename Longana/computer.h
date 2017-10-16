#pragma once
#include "player.h"
class computer : public player
{
public:
	computer();
	~computer();
	void setComputerTurn(bool turn);
	void play(layout& gameLayout, bool lastPlayerPass);
	vector<tile> getPlayableTiles(tile leftOpen, tile rightOpen, bool lastPlayerPass);
	int numNextPlays(tile tilePlayed);
	bool isComputerTurn();
	bool canPlayTile(tile& playedTile, tile openTile, char placement);
	tile findBestPlay(vector<tile> possiblePlays, tile openLeft, tile openRight);
	char getPlaySide(tile playedTile, tile openLeft, tile openRight, bool lastPlayerPass);
	int nextPlaysLeft(tile tilePlayed);
	int nextPlaysRight(tile tilePlayed);
	bool needToFlipTile(tile tilePlayed, tile openTile, char placement);

private:
	bool computerTurn;
};

