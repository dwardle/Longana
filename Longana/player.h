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
	void play(tile playedTile, layout &gameLayout, char placement);
private:
	hand playerHand;
};

