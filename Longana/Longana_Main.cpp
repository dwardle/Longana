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
	testGame.startGame();
	testGame.beginTourn();
	testGame.playGame();
	//testGame.setLayout();
	//testGame.drawLayout();


	system("Pause");
	return 0;
}