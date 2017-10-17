#pragma once
#include "player.h"
class computer : public player
{
public:
	computer();
	~computer();
	bool isComputerTurn();
	void setComputerTurn(bool turn);
	vector<tile> getPlayableTiles(tile leftOpen, tile rightOpen, bool lastPlayerPass);
	vector<tile> getHumanPlayableTiles(tile leftOpen, tile rightOpen, bool lastPlayerPass);
	int nextPlaysLeft(tile tilePlayed);
	int nextPlaysRight(tile tilePlayed);
	char getPlaySide(tile playedTile, tile openLeft, tile openRight, bool lastPlayerPass);
	char getHumanPlaySide(tile playedTile, tile openLeft, tile openRight, bool lastPlayerPass);
	void play(layout& gameLayout, bool lastPlayerPass);
	int numNextPlays(tile tilePlayed);
	bool canPlayTile(tile& playedTile, tile openTile, char placement);
	tile findBestPlay(vector<tile> possiblePlays, tile openLeft, tile openRight);
	bool needToFlipTile(tile tilePlayed, tile openTile, char placement);
	void helpHuman(vector<tile> humanHand, layout gameLayot, bool lastPlayerPass);
private:
	bool computerTurn;
};

