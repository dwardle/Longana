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
	void startGame();
	void beginTourn();
	void playGame();

	//testing layout
	void setLayout();
	void drawLayout();
	/*void drawLayout(vector<tile> bones); this function was for testing, can remove later*/
	stock getBoneyard();
	void playEngine();
	void setHumanPass(bool pass);
	void setComputerPass(bool pass);
	bool getHumanPass();
	bool getComputerPass();
	bool roundEnd();
	bool tournEnd();
	void nextRound();
	void roundWinner();
	int totalPips(vector<tile> loserHand);
	void serialize();
	void saveGame();
	void loadGame();
	vector<tile> parseTileString(string tString);

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
	bool humanTurn;
	bool computerTurn;
	bool humanPass;
	bool computerPass;
};

