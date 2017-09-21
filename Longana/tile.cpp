#include "tile.h"

using namespace std;


tile::tile()
{
	setPips(0, 0);
	setDouble(true);
}

tile::tile(int lPips, int rPips)
{
	setPips(lPips, rPips);
	if (lPips == rPips)
	{
		setDouble(true);
	}
	else
	{
		setDouble(false);
	}
}

tile::~tile()
{
}
/*

Setter functions

*/

void tile::setPips(int lPips, int rPips)
{
	leftPips = lPips;
	rightPips = rPips;
	if (lPips == rPips)
	{
		setDouble(true);
	}
	else
	{
		setDouble(false);
	}
}

void tile::setDouble(bool doubleTile)
{
	isDoubleTile = doubleTile;
}

/*

Getter functions

*/

int tile::getLeftPips() const
{
	return leftPips;
}

int tile::getRightPips() const
{
	return rightPips;
}

bool tile::isDouble() const
{
	return isDoubleTile;
}

tile tile::getTile() const
{
	tile temp(leftPips, rightPips);
	return temp;
}

void tile::swapPips()
{
	int temp = leftPips;
	leftPips = rightPips;
	rightPips = temp;
}