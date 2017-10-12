#pragma once
#include "player.h"
#include<string>
#include<sstream>

using namespace std;

class human : public player
{
public:
	human();
	~human();
	bool play(tile leftOpen);
	tile parseTileInput(string selectedTile);
	bool hasTile(tile selectedTile);
};

