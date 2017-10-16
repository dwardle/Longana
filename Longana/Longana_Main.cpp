#include<iostream>
#include "game.h"
#include"hand.h"
#include"stock.h"
#include"tournament.h"

using namespace std;

int main()
{
	game game1;
	game1.startGame();
	game1.beginTourn();
	game1.playEngine();
	game1.drawLayout();

	game1.serialize();

	while (game1.tournEnd() == false)
	{
		while (game1.roundEnd() == false)
		{
			game1.playGame();
			game1.drawLayout();
		}
		game1.roundWinner();
		if (game1.tournEnd() == false)
		{
			game1.nextRound();
			game1.playEngine();
			game1.drawLayout();
		}	
	}
	system("Pause");
	return 0;
}