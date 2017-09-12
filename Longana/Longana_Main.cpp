#include<iostream>
#include "game.h"

using namespace std;

int main()
{
	//testing tile functions
	game newGame;
	newGame.createBoneyard();
	newGame.shuffleBoneyard();
	system("pause");
	return 0;
}