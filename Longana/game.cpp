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
	char choice;
	cout << "Welcome to Longana" << endl << endl;
	while (true)
	{
		cout << "Please enter an option" << endl;
		cout << "Start new game - N" << endl;
		cout << "Load exisiting game - L" << endl;
		cout << "Selection: ";
		cin >> choice;
		choice = toupper(choice);
		if (choice == 'N')
		{
			boneYard.createBoneyard();
			boneYard.shuffleBoneyard();
			beginTourn();
			playEngine();
			drawLayout();
			saveGame();
			break;
		}
		else if (choice == 'L')
		{
			loadGame();
			drawLayout();
			break;
		}
		else
		{
			cerr << "Error: Invalid selection" << endl;
			cout << "Please try again" << endl << endl;
		}
	}
}

void game::beginTourn()
{
	tourn.setTournScore();
	tournRound.setEngine(roundNum);
	tournRound.roundStart(humanPlayer, computerPlayer, boneYard);
	saveGame();
	//ask if player wants to serialize here

	openLeft = tournRound.getEngine();
	openRight = tournRound.getEngine();
}

void game::playGame()
{
	bool exceptionThrow = false;
	if (humanPlayer.isHumanTurn())
	{
		//system("Pause");
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
					cout << "After drawing a tile you still have no playable tiles. You pass your turn" << endl << endl;
					setHumanPass(true);
					humanPlayer.setHumanTurn(false);
					computerPlayer.setComputerTurn(true);
					return;
				}
			}
			else
			{
				cout << "you have no playable tiles and the boneyard is empty" << endl;
				cout << "you pass your turn" << endl << endl;
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
		//system("Pause");
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
				cout << "Computer player passes its turn" << endl << endl;
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
		cout << "Human player places the engine tile" << endl << endl;
		humanPlayer.playEngine(0, gameLayout, tournRound.getEngine());
		humanPlayer.removeTile(tournRound.getEngine());
		humanPlayer.setHumanTurn(false);
		computerPlayer.setComputerTurn(true);
	}
	else if (computerPlayer.hasEngine(tournRound.getEngine()))
	{
		cout << "Computer player places the engine tile" << endl << endl;
		computerPlayer.playEngine(1, gameLayout, tournRound.getEngine());
		computerPlayer.removeTile(tournRound.getEngine());
		computerPlayer.setComputerTurn(false);
		humanPlayer.setHumanTurn(true);
	}
}


void game::nextRound()
{
	roundNum++;
	tournRound.setRoundNum(roundNum + 1);
	boneYard.clearBoneyard();
	boneYard.createBoneyard();
	boneYard.shuffleBoneyard();
	humanPlayer.setRoundScore(0);
	computerPlayer.setRoundScore(0);
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
		humanPlayer.setRoundScore(winScore);
		humanPlayer.setTotalScore();
		cout << "Human gained " << humanPlayer.getScore() << " points this round" << endl;
		cout << "Human player total score: " << humanPlayer.getTotalScore() << endl;
	}
	else if (computerPlayer.getHand2().empty())
	{
		cout << "Computer player wins the round" << endl << endl;
		winScore = totalPips(humanPlayer.getHand2());
		computerPlayer.setRoundScore(winScore);
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
			humanPlayer.setRoundScore(computerPipCount);
			humanPlayer.setTotalScore();
			cout << "Human gained " << humanPlayer.getScore() << " points this round" << endl;
			cout << "Human player total score: " << humanPlayer.getTotalScore() << endl;
		}
		else if (computerPipCount < humanPipCount)
		{
			cout << "Computer player wins the round" << endl << endl;
			computerPlayer.setRoundScore(humanPipCount);
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
	//humanPlayer.handString();
	fstream saveFile;
	string fileName;
	cout << "Please enter a file name: ";
	cin >> fileName;
	if (fileName.find(".txt") == string::npos)
	{
		fileName += ".txt";
	}
	cout << "Saving game..." << endl;
	bool temp;
	saveFile.open(fileName, fstream::out);
	temp = saveFile.is_open();
	saveFile << "Tournament Score: " << tourn.getTournScore() << endl;
	saveFile << "Round No.: " << tournRound.getRoundNum() << endl << endl;
	saveFile << "Computer:" << endl;
	saveFile << "   Hand: " << computerPlayer.handString() << endl;
	saveFile << "   Score: " << computerPlayer.getTotalScore() << endl << endl;
	saveFile << "Human: "  << endl;
	saveFile << "   Hand: " << humanPlayer.handString() << endl;
	saveFile << "   Score: " << humanPlayer.getTotalScore() << endl << endl;
	saveFile << "Layout:" << endl;
	saveFile << gameLayout.getLayoutString() << endl << endl;
	saveFile << "Boneyard:" << endl;
	saveFile << boneYard.getBoneyardString() << endl << endl;
	saveFile << "Previous Player Passed: ";
	if (humanPlayer.isHumanTurn())
	{
		if (computerPass == true)
		{
			saveFile << "Yes" << endl << endl;
		}
		else
		{
			saveFile << "No" << endl << endl;
		}
		saveFile << "Next Player: Human" << endl;
	}
	else if (computerPlayer.isComputerTurn())
	{
		if (humanPass == true)
		{
			saveFile << "Yes" << endl << endl;
		}
		else
		{
			saveFile << "No" << endl << endl;
		}
		saveFile << "Next Player: Computer" << endl;
	}
	saveFile.close();
	cout << "Game save completed" << endl;
}

void game::saveGame()
{
	char choice;
	while (true)
	{
		cout << "Would you like to continue or save the game and exit? (C/S): ";
		cin >> choice;
		choice = toupper(choice);
		if (choice == 'S')
		{
			serialize();
			cout << "Press enter to exit...";
			cin.clear();
			cin.ignore();
			getchar();
			exit(0);
			break;
		}
		else if (choice == 'C')
		{
			cout << "Game continuing" << endl << endl;
			break;
		}
		else
		{
			cerr << "Error: Invalid selection. type C to continue the game or type S to save the game and exit" << endl;
			cout << "Please try again" << endl << endl;
		}
	}
}

void game::loadGame()
{
	ifstream loadFile;
	string fileName;
	string fileLine;
	string fullFile;

	while (true)
	{
		cout << "Please enter file name for the save file you wish to open" << endl;
		cout << "File name: ";
		cin >> fileName;
		if (fileName.find(".txt") == string::npos)
		{
			fileName += ".txt";
		}
		loadFile.open(fileName);
		if (!loadFile)
		{
			cerr << "Error: Invalid file name" << endl;
			cout << "Please try again" << endl << endl;
		}
		else
		{
			cout << "Loading save file..." << endl;
			break;
		}
	}
	while (!loadFile.eof())
	{
		getline(loadFile, fileLine);
		fullFile += fileLine;
		fullFile += '\n';
	}

	istringstream iss(fullFile);
	string token;
	int tokenNum;

	//get the tournament score and round number and set the engine
	getline(iss, token, ':');
	iss >> tokenNum;
	tourn.setTournScore(tokenNum);
	getline(iss, token, ':');
	iss >> tokenNum;
	tournRound.setRoundNum(tokenNum);
	tournRound.setEngine(tokenNum);


	//get the computer players hand and score
	getline(iss, token, ':');
	getline(iss, token, ':');
	getline(iss, token, '\n');
	computerPlayer.setHand(parseTileString(token));
	getline(iss, token, ':');
	iss >> tokenNum;
	computerPlayer.setTotalScore(tokenNum);

	//get Human players hand and score
	getline(iss, token, ':');
	getline(iss, token, ':');
	getline(iss, token, '\n');
	humanPlayer.setHand(parseTileString(token));
	getline(iss, token, ':');
	iss >> tokenNum;
	humanPlayer.setTotalScore(tokenNum);
	
	//get layout tiles
	getline(iss, token, ':');
	getline(iss, token, 'L');
	getline(iss, token, 'R');
	gameLayout.setTotalLayout(parseTileString(token));
	gameLayout.splitLayout(tournRound.getEngine());
	
	//get Boneyard
	getline(iss, token, ':');
	getline(iss, token, '\n');
	boneYard.setBoneYard(parseTileString(token));

	//get previous player pass and get next player
	bool prevPass;
	getline(iss, token, ':');
	iss >> token;
	if (token == "No")
	{
		prevPass = false;
	}
	else if (token == "Yes")
	{
		prevPass = true;
	}

	getline(iss, token, ':');
	iss >> token;
	if (token == "Computer")
	{
		computerPlayer.setComputerTurn(true);
		humanPlayer.setHumanTurn(true);
		if (prevPass == true)
		{
			humanPass = true;
		}
	}
	else if(token == "Human")
	{
		humanPlayer.setHumanTurn(true);
		computerPlayer.setComputerTurn(false);
		if (prevPass == true)
		{
			computerPass = true;
		}
	}

	cout << "Game loading done." << endl << endl;
	cout << "Continuing Game" << endl << endl;
}

vector<tile> game::parseTileString(string tString)
{
	istringstream tileStream(tString);
	int pos;
	int leftPips;
	int rightPips;
	string tileString;
	vector<tile> tiles;
	while (tileStream >> tileString)
	{
		pos = tileString.find_first_not_of('-');
		leftPips = tileString[pos];
		pos = tileString.find_last_not_of('-');
		rightPips = tileString[pos];
		leftPips -= 48;
		rightPips -= 48;
		tile tempTile(leftPips, rightPips);
		tiles.push_back(tempTile);
	}
	return tiles;
}