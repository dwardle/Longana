#pragma once
#include"hand.h"

using namespace std;

class player
{
public:
	player();
	player(stock b_yard);
	~player();
	void drawHand(stock b_yard);
	void drawTile(stock b_yard);
	hand getHand();
private:
	hand playerHand;
};

