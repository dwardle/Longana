#include<iostream>
#include "game.h"
#include"hand.h"
#include"stock.h"
#include"tournament.h"

using namespace std;

int main()
{
	//testing tile functions
	
	game testGame;
	//stock temp;
	testGame.startGame();
	//temp = testGame.getBoneyard();
	//testGame.drawLayout(temp.getStock());
	testGame.beginTourn();
	testGame.playEngine();
	testGame.drawLayout();
	testGame.playGame();
	testGame.drawLayout();
	testGame.playGame();
	testGame.drawLayout();
	testGame.playGame();
	testGame.drawLayout();
	testGame.playGame();
	testGame.drawLayout();
	testGame.playGame();
	testGame.drawLayout();
	/*testGame.playGame();
	testGame.setLayout();
	testGame.drawLayout();*/


	system("Pause");
	return 0;
}