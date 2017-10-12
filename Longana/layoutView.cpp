#include "layoutView.h"



layoutView::layoutView()
{
}


layoutView::~layoutView()
{
}

void layoutView::drawLayout(char gameLayout[][58])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 58; j++)
		{
			if (gameLayout[i][j] == '|' || gameLayout[i][j] == '-' || gameLayout[i][j] == ' ' || gameLayout[i][j] == 'L' || gameLayout[i][j] == 'R')
			{
				cout << gameLayout[i][j];
			}
			else
			{
				cout << static_cast<int>(gameLayout[i][j]);
			}
		}
		cout << endl;
	}
}
