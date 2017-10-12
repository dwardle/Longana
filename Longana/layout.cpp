#include "layout.h"

using namespace std;

layout::layout()
{
	//h_playedTiles = vector<tile>();
	//c_playedTiles = vector<tile>();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < LAYOUT_MAX; j++)
		{
			playedTiles[i][j] = ' ';
		}
	}
}


layout::~layout()
{
}

void layout::setLayout()
{
	int rightSide;
	int leftSide;

	if (h_playedTiles.empty() == true)
	{
		return;
	}
	playedTiles[0][0] = ' ';
	playedTiles[0][1] = ' ';
	playedTiles[1][0] = 'L';
	playedTiles[1][1] = ' ';
	playedTiles[2][0] = ' ';
	playedTiles[2][1] = ' ';
	int i = 2;
	for each(tile t in h_playedTiles)
	{
		leftSide = t.getLeftPips();
		rightSide = t.getRightPips();
		if (t.isDouble())
		{
			playedTiles[0][i] = leftSide;
			playedTiles[1][i] = '|';
			playedTiles[2][i] = rightSide;
			i++;
			playedTiles[0][i] = ' ';
			playedTiles[1][i] = ' ';
			playedTiles[2][i] = ' ';
			i++;
		}
		else
		{
			playedTiles[1][i] = leftSide;
			i++;
			playedTiles[1][i] = '-';
			i++;
			playedTiles[1][i] = rightSide;
			i++;
			playedTiles[1][i] = ' ';
			i++;
		}
	}
	playedTiles[0][i] = ' ';
	playedTiles[0][i + 1] = ' ';
	playedTiles[1][i] = 'R';
	playedTiles[1][i + 1] = ' ';
	playedTiles[2][i] = ' ';
	playedTiles[2][i + 1] = ' ';
	
	/*for (i = 0; i < 3; i++)
	{
		
		for (int j = 0; j < LAYOUT_MAX; j++)
		{
			if (playedTiles[i][j] == '|' || playedTiles[i][j] == '-' || playedTiles[i][j] == ' ' || playedTiles[i][j] == 'L' || playedTiles[i][j] == 'R')
			{
				cout << playedTiles[i][j];
			}
			else
			{
				cout << static_cast<int>(playedTiles[i][j]);
			}
		}
		cout << endl;
	}*/
	
}

void layout::placeTile(int a_player, tile tilePlaced)
{
	if (a_player == 0)
	{
		h_playedTiles.push_back(tilePlaced);
	}
	else if (a_player = 1)
	{
		c_playedTiles.push_back(tilePlaced);
	}
}

void layout::getLayout(char a_layout[3][58])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 58; j++)
		{
			a_layout[i][j] = playedTiles[i][j];
		}
	}
}
