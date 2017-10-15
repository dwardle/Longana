#include "layoutView.h"
using namespace std;


layoutView::layoutView()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			gameView[i][j] = ' ';
			
		}
	}
}


layoutView::~layoutView()
{
}

//void layoutView::drawLayout(char gameLayout[][58])
//{
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 58; j++)
//		{
//			if (gameLayout[i][j] == '|' || gameLayout[i][j] == '-' || gameLayout[i][j] == ' ' || gameLayout[i][j] == 'L' || gameLayout[i][j] == 'R')
//			{
//				cout << gameLayout[i][j];
//			}
//			else
//			{
//				cout << static_cast<int>(gameLayout[i][j]);
//			}
//		}
//		cout << endl;
//	}
//}

void layoutView::setLayoutView(vector<tile> gameBoard)
{
	int count = 0;
	char leftside;
	char rightside;
	clearView();
	//strncpy(*gameView, *emptyView, sizeof(gameView[3][101]));
	//gameView = emptyView;
	gameView[1][0] = 'L';
	int i = 2;
	for each(tile t in gameBoard)
	{
		leftside = t.getLeftPips();
		rightside = t.getRightPips();
		leftside += 48;
		rightside += 48;
		if (t.isDouble())
		{
			gameView[0][i] = leftside;
			gameView[1][i] = '|';
			gameView[2][i] = rightside;
			i += 2;
			count++;
		}
		else
		{
			gameView[1][i] = leftside;
			gameView[1][i + 1] = '-';
			gameView[1][i + 2] = rightside;
			i += 4;
		}
	}
	gameView[1][i] = 'R';
	//system("Pause");
}

void layoutView::drawLayout()
{
	//string testst;
	
	//testst = *gameView;
	//cout << testst;
	for (int i = 0; i < 3; i++)
	{
		cout << "   ";
		for (int j = 0; j < 101; j++)
		{
			cout << gameView[i][j];
		}
		cout << endl;
	}
}

void layoutView::clearView()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 101; j++)
		{
			gameView[i][j] = ' ';
		}
	}
}