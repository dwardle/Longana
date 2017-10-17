#include "computer.h"



computer::computer()
{
}


computer::~computer()
{
}

void computer::setComputerTurn(bool turn)
{
	computerTurn = turn;
}

bool computer::isComputerTurn()
{
	return computerTurn;
}

void computer::play(layout& gameLayout, bool lastPlayerPass)
{
	vector<tile> possiblePlays;
	tile playedTile;
	char placement;
	possiblePlays = getPlayableTiles(gameLayout.getOpenLeft(), gameLayout.getOpenRight(), lastPlayerPass);
	bool temp;
	temp = possiblePlays.empty();
	if (possiblePlays.empty() == false)
	{
		playedTile = findBestPlay(possiblePlays, gameLayout.getOpenLeft(), gameLayout.getOpenRight());
		placement = getPlaySide(playedTile, gameLayout.getOpenLeft(), gameLayout.getOpenRight(), lastPlayerPass);
		/*gameLayout.placeTile(placement, playedTile);
		cout << "Computer played " << playedTile.getLeftPips() << "-" << playedTile.getRightPips();*/
		if (placement == 'R')
		{
			if (needToFlipTile(playedTile, gameLayout.getOpenRight(), 'R'))
			{
				playedTile.swapPips();
			}
			gameLayout.placeTile(placement, playedTile);
			cout << "Computer played " << playedTile.getLeftPips() << "-" << playedTile.getRightPips();
			cout << " to the right of the engine" << endl << endl;
		}
		else if (placement == 'L')
		{
			if (needToFlipTile(playedTile, gameLayout.getOpenLeft(), 'L'))
			{
				playedTile.swapPips();
			}
			gameLayout.placeTile(placement, playedTile);
			cout << "Computer played " << playedTile.getLeftPips() << "-" << playedTile.getRightPips();
			cout << " to the left of the engine" << endl << endl;
		}
		removeTile(playedTile);
	}
}

vector<tile> computer::getPlayableTiles(tile leftOpen, tile rightOpen, bool lastPlayerPass)
{
	vector<tile> possibleTiles;
	for each(tile t in getHand2())
	{
		if (canPlayTile(t, rightOpen, 'R'))
		{
			possibleTiles.push_back(t);
		}
		else if (lastPlayerPass == true || t.isDouble() == true)
		{
			if (canPlayTile(t, leftOpen, 'L'))
			{
				possibleTiles.push_back(t);
			}
		}
	}

	return possibleTiles;
}

vector<tile> computer::getHumanPlayableTiles(tile leftOpen, tile rightOpen, bool lastPlayerPass)
{
	vector<tile> possibleTiles;
	for each(tile t in getHand2())
	{
		if (canPlayTile(t, leftOpen, 'L'))
		{
			possibleTiles.push_back(t);
		}
		else if (lastPlayerPass == true || t.isDouble() == true)
		{
			if (canPlayTile(t, rightOpen, 'R'))
			{
				possibleTiles.push_back(t);
			}
		}
	}

	return possibleTiles;
}


int computer::numNextPlays(tile tilePlayed)
{
	int left = tilePlayed.getLeftPips();
	int right = tilePlayed.getRightPips();
	int possiblePlays = 0;
	int possibleRightPlays;
	int possibleLeftPlays;
	possibleLeftPlays = nextPlaysLeft(tilePlayed);
	possibleRightPlays = nextPlaysRight(tilePlayed);
	possiblePlays = possibleLeftPlays + possibleRightPlays;
	return possiblePlays;
}


int computer::nextPlaysLeft(tile tilePlayed)
{
	int left = tilePlayed.getLeftPips();
	int right = tilePlayed.getRightPips();
	int possiblePlays = 0;
	for each(tile t in getHand2())
	{
		if (t != tilePlayed)
		{
			if (t.getLeftPips() == left || t.getRightPips() == left)
			{
				possiblePlays++;
			}
		}
	}
	return possiblePlays;
}

int computer::nextPlaysRight(tile tilePlayed)
{
	int left = tilePlayed.getLeftPips();
	int right = tilePlayed.getRightPips();
	int possiblePlays = 0;
	for each(tile t in getHand2())
	{
		if (t.getLeftPips() == right || t.getRightPips() == right)
		{
			possiblePlays++;
		}
	}
	return possiblePlays;
}



bool computer::canPlayTile(tile& playedTile, tile openTile, char placement)
{
	if (placement == 'L')
	{
		if (playedTile.getRightPips() == openTile.getLeftPips()) //|| playedTile.getRightPips() == openTile.getLeftPips())
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
		if (playedTile.getLeftPips() == openTile.getRightPips()) //playedTile.getLeftPips() == openTile.getRightPips() ||
		{
			return true;
		}
		else if (playedTile.getRightPips() == openTile.getRightPips())
		{
			playedTile.swapPips();
			return true;
		}
	}
	return false;
}

tile computer::findBestPlay(vector<tile> possiblePlays, tile openLeft, tile openRight)
{
	tile bestTile = possiblePlays[0];
	int nextPlays = 0;
	int lastTilePlays = 0;
	for each(tile t in possiblePlays)
	{
		nextPlays = numNextPlays(t);
		if (nextPlays > lastTilePlays)
		{
			bestTile = t;
		}
	}

	return bestTile;
}

char computer::getPlaySide(tile playedTile, tile openLeft, tile openRight, bool lastPlayerPass)
{
	if (canPlayTile(playedTile, openRight, 'R') == true)
	{
		return 'R';
	}
	else if (lastPlayerPass == true || playedTile.isDouble())
	{
		if (canPlayTile(playedTile, openLeft, 'L') == true)
		{
			return 'L';
		}
	}
	return NULL;
}

char computer::getHumanPlaySide(tile playedTile, tile openLeft, tile openRight, bool lastPlayerPass)
{
	if (canPlayTile(playedTile, openLeft, 'L') == true)
	{
		return 'L';
	}
	else if (lastPlayerPass == true || playedTile.isDouble())
	{
		if (canPlayTile(playedTile, openRight, 'R') == true)
		{
			return 'R';
		}
	}
	return NULL;
}

bool computer::needToFlipTile(tile tilePlayed, tile openTile, char placement)
{
	if (placement == 'L')
	{
		if (tilePlayed.getRightPips() == openTile.getLeftPips())
		{
			return false;
		}
	}
	else if (placement == 'R')
	{
		if (tilePlayed.getLeftPips() == openTile.getRightPips())
		{
			return false;
		}
	}
	return true;
}

void computer::helpHuman(vector<tile> humanHand, layout gameLayout, bool lastPlayerPass)
{
	vector<tile> tempComputerHand = getHand2();
	setHand(humanHand);
	vector<tile> possiblePlays;
	tile playedTile;
	char placement;
	possiblePlays = getHumanPlayableTiles(gameLayout.getOpenLeft(), gameLayout.getOpenRight(), lastPlayerPass);
	playedTile = findBestPlay(possiblePlays, gameLayout.getOpenLeft(), gameLayout.getOpenRight());
	placement = getHumanPlaySide(playedTile, gameLayout.getOpenLeft(), gameLayout.getOpenRight(), lastPlayerPass);
	cout << "The computer suggests playing the " << playedTile.getLeftPips() << '-' << playedTile.getRightPips();
	if (placement == 'L')
	{
		cout << " to the left of the engine" << endl;
	}
	else if (placement == 'R')
	{
		cout << " to the right of the engine" << endl;
	}
	setHand(tempComputerHand);
}
