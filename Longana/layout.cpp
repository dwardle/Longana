#include "layout.h"

using namespace std;

layout::layout()
{
	//l_playedTiles = vector<tile>();
	//r_playedTiles = vector<tile>();
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

//void layout::setLayout()
//{
//	int rightSide;
//	int leftSide;
//
//	if (l_playedTiles.empty() == true)
//	{
//return;
//	}
//	playedTiles[0][0] = ' ';
//	playedTiles[0][1] = ' ';
//	playedTiles[1][0] = 'L';
//	playedTiles[1][1] = ' ';
//	playedTiles[2][0] = ' ';
//	playedTiles[2][1] = ' ';
//	int i = 2;
//	for each(tile t in l_playedTiles)
//	{
//		leftSide = t.getLeftPips();
//		rightSide = t.getRightPips();
//		if (t.isDouble())
//		{
//			playedTiles[0][i] = leftSide;
//			playedTiles[1][i] = '|';
//			playedTiles[2][i] = rightSide;
//			i++;
//			playedTiles[0][i] = ' ';
//			playedTiles[1][i] = ' ';
//			playedTiles[2][i] = ' ';
//			i++;
//		}
//		else
//		{
//			playedTiles[1][i] = leftSide;
//			i++;
//			playedTiles[1][i] = '-';
//			i++;
//			playedTiles[1][i] = rightSide;
//			i++;
//			playedTiles[1][i] = ' ';
//			i++;
//		}
//	}
//	playedTiles[0][i] = ' ';
//	playedTiles[0][i + 1] = ' ';
//	playedTiles[1][i] = 'R';
//	playedTiles[1][i + 1] = ' ';
//	playedTiles[2][i] = ' ';
//	playedTiles[2][i + 1] = ' ';
//
//	/*for (i = 0; i < 3; i++)
//	{
//
//		for (int j = 0; j < LAYOUT_MAX; j++)
//		{
//			if (playedTiles[i][j] == '|' || playedTiles[i][j] == '-' || playedTiles[i][j] == ' ' || playedTiles[i][j] == 'L' || playedTiles[i][j] == 'R')
//			{
//				cout << playedTiles[i][j];
//			}
//			else
//			{
//				cout << static_cast<int>(playedTiles[i][j]);
//			}
//		}
//		cout << endl;
//	}*/
//
//}

void layout::placeTile(char placement, tile tilePlaced)
{
	if (placement == 'L')
	{
		l_playedTiles.insert(l_playedTiles.begin(), tilePlaced);
	}
	else if (placement = 'R')
	{
		r_playedTiles.push_back(tilePlaced);
	}
}

//void layout::getLayout(char a_layout[3][58])
//{
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 58; j++)
//		{
//			a_layout[i][j] = playedTiles[i][j];
//		}
//	}
//}

void layout::setLayout()
{
	totalLayout.clear();

	if (l_playedTiles.empty() == false)
	{
		totalLayout = l_playedTiles;
		if (r_playedTiles.empty() == false)
		{
			totalLayout.insert(totalLayout.end(), r_playedTiles.begin(), r_playedTiles.end());
		}
	}
	else if (r_playedTiles.empty() == false)
	{
		totalLayout = r_playedTiles;
		if (l_playedTiles.empty() == false)
		{

			totalLayout.insert(totalLayout.begin(), l_playedTiles.begin(), l_playedTiles.end());
		}
		
	}
	//vector<tile> totalLayout = l_playedTiles;
	//totalLayout.insert(totalLayout.end(), r_playedTiles.begin(), r_playedTiles.end());
}
vector<tile> layout::getLayout()
{
	return totalLayout;
	//totalLayout.clear();

	//if (l_playedTiles.empty() == false)
	//{
	//	totalLayout = l_playedTiles;
	//	if (r_playedTiles.empty() == false)
	//	{
	//		totalLayout.insert(totalLayout.end(), r_playedTiles.begin(), r_playedTiles.end());
	//	}
	//	return totalLayout;
	//}
	//else if (r_playedTiles.empty() == false)
	//{
	//	totalLayout = r_playedTiles;
	//	if (l_playedTiles.empty() == false)
	//	{
	//		
	//		totalLayout.insert(totalLayout.begin(), l_playedTiles.begin(), l_playedTiles.end());
	//	}
	//	return totalLayout;
	//}
	////vector<tile> totalLayout = l_playedTiles;
	////totalLayout.insert(totalLayout.end(), r_playedTiles.begin(), r_playedTiles.end());
	//return totalLayout;
}

// dont think i need this anymore
void layout::placeEngineTile(int a_player, tile engineTile)
{
	//tile tempTile = engineTile;
	if (a_player == 0)
	{
		//l_playedTiles.clear();
		l_playedTiles.push_back(engineTile);
	}
	else if (a_player == 1)
	{
		r_playedTiles.push_back(engineTile);
	}
}

tile layout::getOpenLeft()
{
	return totalLayout.front();
}

tile layout::getOpenRight()
{
	return totalLayout.back();
}

string layout::getLayoutString()
{
	string layoutTiles;
	layoutTiles += "L ";
	for each (tile t in totalLayout)
	{
		layoutTiles += (t.getLeftPips() + 48);
		layoutTiles += "-";
		layoutTiles += (t.getRightPips() + 48);
		layoutTiles += " ";
	}
	layoutTiles += "R";
	return layoutTiles;
}

void layout::setTotalLayout(vector<tile> layoutTiles)
{
	totalLayout = layoutTiles;
}

void layout::splitLayout(tile engine)
{
	bool pastEngine = false;
	if (totalLayout.empty() == true)
	{
		return;
	}
	for each (tile t in totalLayout)
	{
		if (pastEngine == false)
		{
			l_playedTiles.push_back(t);
			if (t == engine)
			{
				pastEngine = true;
			}
		}
		else
		{
			r_playedTiles.push_back(t);
		}
	}
}