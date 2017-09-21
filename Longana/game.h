#pragma once
#include"tile.h"
#include"player.h"
#include"human.h"
#include"stock.h"
#include<vector>
#include<algorithm>
#include<time.h>

using namespace std;

class game
{
public:
	game();
	~game();
	void startGame();
private:
	human humanPlayer;
	stock boneYard;
	
};

