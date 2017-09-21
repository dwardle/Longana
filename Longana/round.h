#pragma once
#include<iostream>
#include"human.h"
#include"computer.h"
#include"stock.h"


using namespace std;

class round
{
public:
	round();
	~round();
	//functions below may be temporary/moved to different class
	void roundStart(human h_Player, computer c_Player);
private:
	stock boneyard;
	tile engine;
};

