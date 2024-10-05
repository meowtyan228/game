#ifndef MANAGER
#define MANAGER
#include "Ship.h"
#include <vector>

class ShipManager
{

public:
	ShipManager(int n, std::initializer_list<int> list);
	std::vector<Ship> getShipsVector();
	
private:

	int num;
	std::vector<Ship> ships;

};

#endif