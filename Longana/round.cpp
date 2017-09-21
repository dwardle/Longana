#include "round.h"

using namespace std;


round::round()
{
	boneyard.createBoneyard();
}


round::~round()
{
}

void round::roundStart(human h_Player, computer c_Player)
{
	boneyard.shuffleBoneyard();
	engine.setPips(6, 6);
	for (int i = 0; i < 8; i++)
	{
		h_Player.drawTile(boneyard);
		//computer player will draw a tile next to alternate draws
	}
	
	while (h_Player.hasEngine(engine) != true)
	{
		h_Player.drawTile(boneyard);
	}
}
