#ifndef CELL
#define CELL

#include "Ship.h"

enum CellState
{
	EMPTY,
	FOGOFWAR,
	SHIP_HERE
};

class Cell {

public:

	Cell();
	~Cell();
	bool isEmpty();
	void setSegment(SegmentState& segmentState);
	void attackCell();
	CellState getCellState();
	SegmentState getSegmentState();

private:

	bool fogofWar;
	SegmentState* segmentState;
};

#endif