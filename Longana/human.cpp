#include "human.h"


using namespace std;

human::human()
{
	humanTurn = false;
}


human::~human()
{
}


//right now the player can select a tile from his hand and it will check the player hand to make sure they have that tile
//the string entered will be parsed for digits, this means that anything the player enters that is not a number will be ignored
//this allows the function to also validate the at the tile entered is actually a valid tile entry, meaning it has 2 numbers representing the
//pips on the left and right of the tile.
//Still need to validate if the tile can be played or not. 
//tile human::play(tile leftOpen)
//{
//	string tileString;
//	cout << "Your hand: ";
//	for each (tile t in getHand2())
//	{
//		cout << t.getLeftPips() << '-' << t.getRightPips();
//		cout << " ";
//	}
//	cout << endl;
//	cout << "Please select the tile you want to play: ";
//	cin >> tileString;
//	tile selectedTile = parseTileInput(tileString);
//	//tileString.clear();
//	cin.clear();
//	if (hasTile(selectedTile) == false)
//	{
//		selectedTile.swapPips();
//		if (hasTile(selectedTile) == false)
//		{
//			throw "Error: Invalid input. you either do not have that tile or entered the tile incorrectly";
//		}
//		
//		//cout << "Invalid input. you either do not have the tile entered or entered the tile incorrectly" << endl;
//		//cout << "Please try again" << endl << endl;
//
//		//cout << "Please select the tile you want to play: ";
//		//cin >> tileString;
//		//selectedTile = parseTileInput(tileString);
//		////tileString.clear();
//		//cin.clear();
//	}
//
//	if (validatePlay(leftOpen, selectedTile) == false)
//	{
//		throw "Error: Invalid play. The tile you selected can not be played";
//	}
//
//	return selectedTile;
//	//selectedTile
//}


//need to fix this. I want this function to be able to call selectTile, tilePlacement, and validatePlay. then call gameLayout.placeTile. validate play might
//need to be changed to check if the player is allowed to play on the side they choose
void human::play(layout& gameLayout, bool lastPlayerPass) //play(tile playedTile, layout &gameLayout, char placement, bool lastPlayerPass)
{
	tile playedTile = selectTile();
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
	tile selectedTile = parseTileInput(tileString);
	cin.clear();
	cin.ignore();
	if (hasTile(selectedTile) == false)
	{
		selectedTile.swapPips();
		if (hasTile(selectedTile) == false)
		{
			throw "Error: Invalid input. you either do not have that tile or entered the tile incorrectly";
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