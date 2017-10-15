#include "game.h"

using namespace std;


game::game()
{
	roundNum = 0;
	setHumanPass(false);
	setComputerPass(false);
	tournRound = round::round(roundNum + 1);
}


game::~game()
{
}

void game::startGame()
{
	//char choice = ' ';
	boneYard.createBoneyard();
	boneYard.shuffleBoneyard();

	cout << "Welcome to Longana" << endl << endl;
}

void game::beginTourn()
{
	tourn.setTournScore();
	tournRound.setEngine(roundNum);
	tournRound.roundStart(humanPlayer, computerPlayer, boneYard);
	openLeft = tournRound.getEngine();
	openRight = tournRound.getEngine();
}

void game::playGame()
{
	if (humanPlayer.isHumanTurn())
	{
		if (humanPlayer.canPlayTile(openLeft, openRight, getComputerPass(), 'L') == false)
		{
			humanPlayer.drawTile(boneYard);
			tile tempTile = humanPlayer.getHand2().back();
			cout << "You have no playable tiles." << endl;
			cout << "You draw the tile " << tempTile.getLeftPips() << "-" << tempTile.getRightPips() << " from the boneyard" << endl;
			if (humanPlayer.canPlayTile(openLeft, openRight, computerPass, 'L') == false)
			{
				cout << "After drawing a tile you still have no playable tiles. You pass your turn" << endl;
				setHumanPass(true);
				humanPlayer.setHumanTurn(false);
				computerPlayer.setComputerTurn(true);
				return;
			}
		}

		
		bool exceptionThrow = false;
		tile playedTile;
		do
		{
			try
			{
				exceptionThrow = false;
				humanPlayer.play(gameLayout, computerPass);
				setHumanPass(false);
				humanPlayer.setHumanTurn(false);
				computerPlayer.setComputerTurn(true);
				gameLayout.setLayout();
				openLeft = gameLayout.getOpenLeft();
				openRight = gameLayout.getOpenRight();
			}
			catch (char* execptionMessage)
			{
				cerr << endl << execptionMessage << endl << "Please try again" << endl << endl;
				exceptionThrow = true;
			}
		} while (exceptionThrow == true);
	}
	else if (computerPlayer.isComputerTurn())
	{
		cout << "Was computer turn" << endl << endl;
		computerPlayer.setComputerTurn(false);
		humanPlayer.setHumanTurn(true);
	}
}

//using player hand right now for testing. must be changed.
//not currently using, should be deleted later
void game::setLayout()
{
	for each(tile t in humanPlayer.getHand2())
	{
		gameLayout.placeTile(0, t);
	}
}

void game::drawLayout()
{
	gameLayout.setLayout();
	gameView.setLayoutView(gameLayout.getLayout());
	gameView.drawLayout();
}


stock game::getBoneyard()
{
	return boneYard;
}

void game::playEngine()
{
	if (humanPlayer.hasEngine(tournRound.getEngine()))
	{
		humanPlayer.playEngine(0, gameLayout, tournRound.getEngine());
		humanPlayer.removeTile(tournRound.getEngine());
	}
	else if (computerPlayer.hasEngine(tournRound.getEngine()))
	{
		computerPlayer.playEngine(1, gameLayout, tournRound.getEngine());

	}
}



void game::setHumanPass(bool pass)
{
	humanPass = pass;
}
void game::setComputerPass(bool pass)
{
	computerPass = pass;
}
bool game::getHumanPass()
{
	return humanPass;
}
bool game::getComputerPass()
{
	return computerPass;
}