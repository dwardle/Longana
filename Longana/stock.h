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
	vector<tile> getStock();
	string getBoneyardString();
	bool isEmpty();
	void setBoneYard(vector<tile> newBoneyard);
	void clearBoneyard();
	void createBoneyard();
	void shuffleBoneyard();
	tile drawTile();
private:
	vector<tile> boneyard;
};

