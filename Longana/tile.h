#pragma once
class tile
{
public:
	tile();
	tile(int lPips, int rPips);
	~tile();
	inline void setPips(int lPips, int rPips);
	inline void setDouble(bool doubleTile);
	int getLeftPips() const;
	int getRightPips() const;
	bool isDouble();
	inline tile getTile() const;
	void swapPips();
	bool operator==(const tile& t);
	bool operator!=(const tile& t);
private:
	int leftPips;
	int rightPips;
	bool isDoubleTile;


};

