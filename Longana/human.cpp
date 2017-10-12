#include "human.h"


using namespace std;

human::human()
{
}


human::~human()
{
}


//right now the player can select a tile from his hand and it will check the player hand to make sure they have that tile
//the string entered will be parsed for digits, this means that anything the player enters that is not a number will be ignored
//this allows the function to also validate the at the tile entered is actually a valid tile entry, meaning it has 2 numbers representing the
//pips on the left and right of the tile.
//Still need to validate if the tile can be played or not. 
bool human::play(tile leftOpen)
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
	//tileString.clear();
	cin.clear();
	while (hasTile(selectedTile) == false)
	{
		cout << "Invalid input. you either do not have the tile entered or entered the tile incorrectly" << endl;
		cout << "Please try again" << endl << endl;

		cout << "Please select the tile you want to play: ";
		cin >> tileString;
		selectedTile = parseTileInput(tileString);
		//tileString.clear();
		cin.clear();
	}

	//selectedTile
	
	

	return false;
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