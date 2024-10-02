#ifndef FIELD
#define FIELD
#include <vector>
#include "ShipManager.h"
#include "Cell.h"


class Field
{
public:

	Field(int n, int m);
	~Field();
	int checkSurr(int x, int y, int orientation, int size);
	int placeShip(int x, int y, Ship& ship);
	std::vector <std::vector<Cell>>&getField();
	Cell& getCell(int x, int y);
	void printField();
	void updateField();

private:
	int width; 
	int height;
	std::vector<std::vector<Cell>> field;
};
#endif
