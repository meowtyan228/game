#ifndef MANAGER
#define MANAGER
#include "Ship.h"
#include <vector>

class ShipManager
{

public:
	ShipManager(int n, std::initializer_list<int> list);
	std::vector<Ship> getShipsVector();
	//void changeCoord(int x, int y);
	// void setShipsVector(std::initializer_list<int> list);
	// Ship* getShips();
	// void showShips();
	// void printShips();
	// void addShips(int count, std::vector<int>& lengths);
	// std::vector<int> getShipLengths();
	// Ship getShip(std::vector<Ship> ships);
	// void getShips( std::vector<Ship>);

private:

	int num;
	std::vector<Ship> ships;

};

#endif