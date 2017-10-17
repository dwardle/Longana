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
	hand getHand();
	bool hasEngine(tile a_engine);
	vector<tile> getHand2();
	tile getLastTile();
	int getScore();
	int getTotalScore();
	void setRoundScore(int newScore);
	void setTotalScore();
	void setTotalScore(int tScore);
	void setHand(vector<tile> newHand);
	void clearHand();
	string handString();
	void drawHand(stock b_yard);
	void drawTile(stock& b_yard);
	void play1(tile playedTile, layout &gameLayout, char placement);
	virtual void play(tile playedTile, layout &gameLayout, char placement, bool lastPlayerPass);
	void playEngine(char placement, layout& gameLayout, tile engineTile);
	void removeTile(tile rTile);
	bool canPlayTile(tile leftOpen, tile rightOpen, bool lastPlayerPass, char playerSide);
private:
	hand playerHand;
	int roundScore;
	int totalScore;
};

