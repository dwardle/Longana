#include "game.h"

using namespace std;


game::game()
{
}


game::~game()
{
}


void game::createBoneyard()
{
	tile nextTile;
	for(int i = 0; i < 7; i++)
	{
		for (int j = i; j < 7; j++)
		{
			nextTile.setPips(i, j);
			boneyard.push_back(nextTile);
		}
	}
}

void game::shuffleBoneyard()
{
	srand(time(NULL));
	random_shuffle(boneyard.begin(), boneyard.end());
}