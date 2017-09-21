#include<iostream>
#include "game.h"
#include"hand.h"
#include"stock.h"

using namespace std;

int main()
{
	//testing tile functions
	game test;
	test.startGame();
	player p1;
	stock st;
	st.createBoneyard();
	p1.drawHand(st);
	hand testhand = p1.getHand();
	tile testTile;
	testTile.setPips(1, 2);
	testhand.removeTile(testTile);
	
	
	


	system("Pause");
	return 0;
}