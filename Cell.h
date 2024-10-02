#ifndef CELL
#define CELL

#include "Ship.h"

enum class CellState
{
	EMPTY,
	FOGOFWAR,
	SHIP_HERE
};

class Cell {

public:
	Cell();
	~Cell();
	bool changeFog();
	bool isEmpty();
	void setSegment(int n, Ship& ship);
	int getSegmant();
	void attackCell(Cell& cell);
	Ship* getShip();
	CellState getStateEnum();

private:

	bool fogofWar;
	int numSegment;
	Ship* ship;
};

#endif