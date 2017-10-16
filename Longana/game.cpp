#include "game.h"

using namespace std;


game::game()
{
	roundNum = 1;
	setHumanPass(false);
	setComputerPass(false);
	tournRound = round::round(roundNum);
}


game::~game()
{
}

void game::startGame()
{
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
	bool exceptionThrow = false;
	if (humanPlayer.isHumanTurn())
	{
		system("Pause");
		cout << "Human players turn" << endl << endl;
		//system("Pause");
		if (humanPlayer.canPlayTile(openLeft, openRight, getComputerPass(), 'L') == false)
		{
			if (boneYard.isEmpty() == false)
			{
				humanPlayer.drawTile(boneYard);
				tile tempTile = humanPlayer.getHand2().back();
				cout << "You have no playable tiles." << endl;
				cout << "You draw the tile " << tempTile.getLeftPips() << "-" << tempTile.getRightPips() << " from the boneyard" << endl;
				if (humanPlayer.canPlayTile(openLeft, openRight, computerPass, 'L') == false)//&& boneYard.isEmpty() == false)
				{
					cout << "After drawing a tile you still have no playable tiles. You pass your turn" << endl;
					setHumanPass(true);
					humanPlayer.setHumanTurn(false);
					computerPlayer.setComputerTurn(true);
					return;
				}
			}
			else
			{
				cout << "you have no playable tiles and the boneyard is empty" << endl;
				cout << "you pass your turn" << endl;
				setHumanPass(true);
				tournRound.setNumPasses(tournRound.getNumPasses() + 1);
				humanPlayer.setHumanTurn(false);
				computerPlayer.setComputerTurn(true);
				return;
			}
		}
		
		tile playedTile;
		do
		{
			try
			{
				exceptionThrow = false;
				humanPlayer.play(gameLayout, computerPass);
				setHumanPass(false);
				humanPlayer.setHumanTurn(false);
				tournRound.setNumPasses(0);
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
		system("Pause");
		cout << "Computer players turn" << endl << endl;
		cout << "computers hand: ";
		
		for each(tile t in computerPlayer.getHand2())
		{
			cout << t.getLeftPips() << '-' << t.getRightPips() << " ";
		}
		//system("Pause");
		cout << endl;
		if (computerPlayer.player::canPlayTile(openLeft, openRight, getHumanPass(), 'R') == false)
		{
			if(boneYard.isEmpty() == false)
			{
				cout << "The computer player has no playable tiles." << endl;
				cout << "The computer player draws a tile from the boneyard" << endl;
				computerPlayer.drawTile(boneYard);
				if (computerPlayer.player::canPlayTile(openLeft, openRight, getHumanPass(), 'R') == false)
				{
					cout << "ComputerPlayer passes its turn" << endl << endl;
					setComputerPass(true);
					computerPlayer.setComputerTurn(false);
					humanPlayer.setHumanTurn(true);
					return;
				}
			}
			else
			{
				cout << "Computer player passes its turn" << endl;
				tournRound.setNumPasses(tournRound.getNumPasses() + 1);
				setComputerPass(true);
				computerPlayer.setComputerTurn(false);
				humanPlayer.setHumanTurn(true);
				return;
			}

		}
		computerPlayer.play(gameLayout, getHumanPass());
		computerPlayer.setComputerTurn(false);
		setComputerPass(false);
		tournRound.setNumPasses(0);
		gameLayout.setLayout();
		openLeft = gameLayout.getOpenLeft();
		openRight = gameLayout.getOpenRight();
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
		computerPlayer.removeTile(tournRound.getEngine());

	}
}


void game::nextRound()
{
	roundNum++;
	tournRound.setRoundNum(roundNum + 1);
	boneYard.clearBoneyard();
	boneYard.createBoneyard();
	boneYard.shuffleBoneyard();
	humanPlayer.setScore(0);
	computerPlayer.setScore(0);
	humanPlayer.clearHand();
	computerPlayer.clearHand();
	setHumanPass(false);
	setComputerPass(false);
	humanPlayer.setHumanTurn(false);
	computerPlayer.setComputerTurn(false);
	tournRound.setEngine(roundNum);
	tournRound.roundStart(humanPlayer, computerPlayer, boneYard);
	openLeft = tournRound.getEngine();
	openRight = openLeft;

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

bool game::roundEnd()
{
	return tournRound.roundEnd(humanPlayer, computerPlayer, computerPass, humanPass);
}

bool game::tournEnd()
{
	return tourn.tournEnd(humanPlayer, computerPlayer);
}

void game::roundWinner()
{
	int winScore;
	if (humanPlayer.getHand2().empty() == true)
	{
		cout << "Human player wins the round" << endl << endl;
		winScore = totalPips(computerPlayer.getHand2());
		humanPlayer.setScore(winScore);
		humanPlayer.setTotalScore();
		cout << "Human gained " << humanPlayer.getScore() << " points this round" << endl;
		cout << "Human player total score: " << humanPlayer.getTotalScore() << endl;
	}
	else if (computerPlayer.getHand2().empty())
	{
		cout << "Computer player wins the round" << endl << endl;
		winScore = totalPips(humanPlayer.getHand2());
		computerPlayer.setScore(winScore);
		computerPlayer.setTotalScore();
		cout << "Computer gained " << computerPlayer.getScore() << " points this round" << endl;
		cout << "Computer player total score: " << computerPlayer.getTotalScore() << endl << endl;
	}
	else if (humanPass == true && computerPass == true)
	{
		int humanPipCount;
		int computerPipCount;

		humanPipCount = totalPips(computerPlayer.getHand2());
		computerPipCount = totalPips(humanPlayer.getHand2());

		if (humanPipCount < computerPipCount)
		{
			cout << "Human player wins the round" << endl << endl;
			humanPlayer.setScore(computerPipCount);
			humanPlayer.setTotalScore();
			cout << "Human gained " << humanPlayer.getScore() << " points this round" << endl;
			cout << "Human player total score: " << humanPlayer.getTotalScore() << endl;
		}
		else if (computerPipCount < humanPipCount)
		{
			cout << "Computer player wins the round" << endl << endl;
			computerPlayer.setScore(humanPipCount);
			computerPlayer.setTotalScore();
			cout << "Computer gained " << computerPlayer.getScore() << " points this round" << endl;
			cout << "Computer player total score: " << computerPlayer.getTotalScore() << endl << endl;
		}
		else if (humanPipCount == computerPipCount)
		{
			cout << "Round draw" << endl;
			cout << "No points awarded this round" << endl << endl;
		}

	}
}

int game::totalPips(vector<tile> loserHand)
{
	int pipCount = 0;
	for each(tile t in loserHand)
	{
		pipCount += t.getLeftPips() + t.getRightPips();
	}
	return pipCount;
}

void game::serialize()
{
	fstream saveFile;
	bool temp;
	saveFile.open("savedGame.txt", fstream::out);
	temp = saveFile.is_open();
	saveFile << "Tournament Score: " << tourn.getTournScore() << endl;
	saveFile << "Round No.: " << tournRound.getRoundNum() << endl << endl;
	saveFile << "Computer:" << endl;
	saveFile << "   Hand:" << endl;
	saveFile << "   Score:" << endl << endl;
	saveFile << "Human:" << endl;
	saveFile << "   Hand:" << endl;
	saveFile << "   Score:" << endl;


	saveFile.close();
}