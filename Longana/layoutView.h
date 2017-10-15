#pragma once
#include"layout.h"
#include<iostream>
#include<string>


using namespace std;
class layoutView
{
public:
	layoutView();
	~layoutView();
	//void drawLayout(char gameLayout[][58]);
	void drawLayout();
	void setLayoutView(vector<tile> gameBoard);
	void clearView();
private:
	char gameView[3][101];
	//char emptyView[3][101];
};

