#pragma once
#include "tile.h"
#include<vector>
#include<algorithm>
#include<time.h>

using namespace std;

class game
{
public:
	game();
	~game();
	void createBoneyard();
	void shuffleBoneyard();
private:
	vector<tile> boneyard;
	
};

