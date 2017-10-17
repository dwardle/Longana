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
#include<fstream>

using namespace std;

class game
{
public:
	game();
	~game();
	stock getBoneyard();
	bool getHumanPass();
	bool getComputerPass();
	bool roundEnd();
	bool tournEnd();
	void setLayout();
	void drawLayout();
	void setHumanPass(bool pass);
	void setComputerPass(bool pass);
	void startGame();
	void beginTourn();
	void playGame();
	void playEngine();
	void nextRound();
	void roundWinner();
	void endTourn();
	int totalPips(vector<tile> loserHand);
	void serialize();
	void saveGame();
	void loadGame();
	vector<tile> parseTileString(string tString);

private:
	int roundNum;
	bool humanTurn;
	bool computerTurn;
	bool humanPass;
	bool computerPass;
	human humanPlayer;
	computer computerPlayer;
	stock boneYard;
	tournament tourn;
	class::round tournRound;
	layout gameLayout;
	layoutView gameView;
	tile openLeft;
	tile openRight;
	
};

