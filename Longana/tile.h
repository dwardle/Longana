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
	inline bool isDouble() const;
	inline tile getTile() const;
	void swapPips();
private:
	int leftPips;
	int rightPips;
	bool isDoubleTile;


};

