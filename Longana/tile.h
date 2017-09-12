#pragma once
class tile
{
public:
	tile();
	tile(int lPips, int rPips);
	~tile();
	inline void setPips(int lPips, int rPips);
	inline void setDouble(bool doubleTile);
	inline int getLeftPips() const;
	inline int getRightPips() const;
	inline bool isDouble() const;
	inline tile getTile() const;
	void swapPips();
private:
	int leftPips;
	int rightPips;
	bool isDoubleTile;


};

