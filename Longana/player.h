#pragma once
#include"hand.h"
#include"layout.h"


using namespace std;

class player
{
public:
	player();
	player(stock b_yard);
	~player();
	void drawHand(stock b_yard);
	void drawTile(stock& b_yard);
	hand getHand();
	bool hasEngine(tile a_engine);
	vector<tile> getHand2();
	void play1(tile playedTile, layout &gameLayout, char placement);
	virtual void play(tile playedTile, layout &gameLayout, char placement, bool lastPlayerPass);
	void playEngine(char placement, layout& gameLayout, tile engineTile);
	void removeTile(tile rTile);
	bool canPlayTile(tile leftOpen, tile rightOpen, bool lastPlayerPass, char playerSide);
	tile getLastTile();
private:
	hand playerHand;
};

