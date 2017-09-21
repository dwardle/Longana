#pragma once
#include"tile.h"
#include<vector>
#include<time.h>
#include<algorithm>

using namespace std;

class stock
{
public:
	stock();
	~stock();
	void createBoneyard();
	void shuffleBoneyard();
	tile drawTile();
private:
	vector<tile> boneyard;
	
};
