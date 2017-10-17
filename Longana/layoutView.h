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
	void setLayoutView(vector<tile> gameBoard);
	void clearView();
	void drawLayout();
private:
	char gameView[3][101];
};

