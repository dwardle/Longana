#include "human.h"


using namespace std;

human::human()
{
	humanTurn = false;
	inHelpMode = false;
}


human::~human()
{
}


//need to fix this. I want this function to be able to call selectTile, tilePlacement, and validatePlay. then call gameLayout.placeTile. validate play might
//need to be changed to check if the player is allowed to play on the side they choose
void human::play(layout& gameLayout, computer computerPlayer, bool lastPlayerPass) //play(tile playedTile, layout &gameLayout, char placement, bool lastPlayerPass)
{
	
	while (true)
	{
		tile playedTile = selectTile();
		if (inHelpMode == false)
		{
			char placement;
			if (playedTile.isDouble() || lastPlayerPass == true)
			{
				placement = tilePlacement();
			}
			else
			{
				placement = 'L';
			}

			if (placement == 'L')
			{
				if (validatePlay(gameLayout.getOpenLeft(), playedTile, 'L') == true)
				{
					gameLayout.placeTile(placement, playedTile);
					removeTile(playedTile);
				}
			}
			else if (placement == 'R')
			{
				if (validatePlay(gameLayout.getOpenRight(), playedTile, 'R') == true)
				{
					gameLayout.placeTile(placement, playedTile);
					removeTile(playedTile);
				}
			}
			break;
		}
		else
		{
			helpMode(computerPlayer, gameLayout, lastPlayerPass);
			inHelpMode = false;
		}
	}
}
	

tile human::selectTile()
{
	string tileString;
	cout << "Your hand: ";
	for each (tile t in getHand2())
	{
		cout << t.getLeftPips() << '-' << t.getRightPips();
		cout << " ";
	}
	cout << endl;
	cout << "Please select the tile you want to play: ";
	cin >> tileString;
	if (tileString == "h" || tileString == "help")
	{
		inHelpMode = true;
		cin.clear();
		return tile();
	}
	tile selectedTile = parseTileInput(tileString);
	cin.clear();
	cin.ignore();
	if (hasTile(selectedTile) == false)
	{
		selectedTile.swapPips();
		if (hasTile(selectedTile) == false)
		{
			throw "Error: Invalid input. you either do not have that tile or entered the tile incorrectly. type h or help to get help from the computer";
		}
	}


	return selectedTile;
	//selectedTile
}

char human::tilePlacement()
{
	char side;
	cout << "Which side would you like to play the tile(L/R)?" << endl;
	cout << "side: ";
	cin >> side;
	side = toupper(side);
	if (side == 'L' || side == 'R')
	{
		return side;
	}
	else
	{
		throw "Error: invalid placement, please type L for left or R for right";
	}
}



tile human::parseTileInput(string selectedTile)
{
	stringstream ss(selectedTile);
	int left = -1;
	int right = -1;
	while (!ss.eof())
	{
		if (left == -1)
		{
			if (isdigit(ss.peek()))
			{
				ss >> left;
			}
			else
			{
				ss.ignore();
			}
		}
		else if (right == -1)
		{
			if (isdigit(ss.peek()))
			{
				ss >> right;
			}
			else
			{
				ss.ignore();
			}
		}
	}
	tile selection;
	selection.setPips(left, right);
	return selection;
}

bool human::hasTile(tile selectedTile)
{
	for each(tile t in getHand2())
	{
		if (t == selectedTile)
		{
			return true;
		}
	}
	return false;
}

bool human::validatePlay(tile openTile, tile& playedTile, char placement)
{
	if (placement == 'L')
	{
		if (playedTile.getRightPips() == openTile.getLeftPips())
		{
			return true;
		}
		else if (playedTile.getLeftPips() == openTile.getLeftPips())
		{
			playedTile.swapPips();
			return true;
		}
	}
	else if (placement == 'R')
	{
		if (playedTile.getLeftPips() == openTile.getRightPips())
		{
			return true;
		}
		else if (playedTile.getRightPips() == openTile.getRightPips())
		{
			playedTile.swapPips();
			return true;
		}
	}
	throw "Error: invalid play, you can not play that tile there";
	return false;
}

void human::setHumanTurn(bool turn)
{
	humanTurn = turn;
}

bool human::isHumanTurn()
{
	return humanTurn;
}

void human::helpMode(computer computerPlayer, layout gameLayout, bool lastPlayerPass)
{
	cout << "Help mode entered" << endl << endl;
	computerPlayer.helpHuman(getHand2(), gameLayout, lastPlayerPass);
}