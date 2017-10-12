#include "game.h"

using namespace std;


game::game()
{
	roundNum = 0;
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

	//this is probably un nessasry
	/*while (choice != 'y' || choice != 'n')
	{
		cout << "Welcome to Longana, would you like to start a tournament? y for yes, n for no: ";
		cin >> choice;
		choice = tolower(choice);
		if (cin.fail())
		{
			cout << "invalud input. please enter y or n" << endl << endl;
			cin.clear();
			cin.ignore();
			choice = ' ';
		}
		else if (choice != 'y' && choice != 'n')
		{
			cout << "invalud input. please enter y or n" << endl << endl;
			cin.clear();
			cin.ignore();
			choice = ' ';
		}
	}*/



	//may remove this
	//humanPlayer.drawHand(boneYard);
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
	humanPlayer.play(openLeft);
}

//using player hand right now for testing. must be changed.
void game::setLayout()
{
	for each(tile t in humanPlayer.getHand2())
	{
		gameLayout.placeTile(0, t);
	}
	gameLayout.setLayout();
}

void game::drawLayout()
{
	char gameBoard[3][58];
	gameLayout.getLayout(gameBoard);
	gameView.drawLayout(gameBoard);
}