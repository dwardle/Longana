#include "game.h"

using namespace std;


game::game()
{
}


game::~game()
{
}

void game::startGame()
{
	boneYard.createBoneyard();
	boneYard.shuffleBoneyard();
	humanPlayer.drawHand(boneYard);

}
