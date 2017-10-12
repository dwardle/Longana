#pragma once
#include"tile.h"
#include"player.h"
#include"human.h"
#include"stock.h"
#include"tournament.h"
#include"round.h"
#include"layout.h"
#include"layoutView.h"
#include<vector>
#include<algorithm>
#include<time.h>
#include<iostream>

using namespace std;

class game
{
public:
	game();
	~game();
	void startGame();
	void beginTourn();
	void playGame();

	//testing layout
	void setLayout();
	void drawLayout();

private:
	human humanPlayer;
	computer computerPlayer;
	stock boneYard;
	tournament tourn;
	class::round tournRound;
	layout gameLayout;
	layoutView gameView;
	tile openLeft;
	tile openRight;
	int roundNum;
};

