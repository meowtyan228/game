#include "GameField.h"
#include "Cell.h"
#include <iostream>

Cell::Cell()
	:fogofWar(true), numSegment(0), ship(ship){}

Cell :: ~Cell(){

};

bool Cell::changeFog()
{
	return fogofWar = !fogofWar;
}

bool Cell::isEmpty()
{
	return ship == nullptr;
}

void Cell::setSegment(int n, Ship& ship)
{
	if (n >= ship.getLength() || n < 0)
		throw std::out_of_range("Segment is out of ship");
	numSegment = n;
	this->ship = &ship;
	return;
};

int Cell::getSegmant() {

	return numSegment;

};

Ship* Cell::getShip()
{
	return ship;
}


void Cell::attackCell(Cell& cell){
	int index = cell.getSegmant();
	if(ship) ship->changeState(index);
	cell.changeFog();
}

CellState Cell::getStateEnum(){
	if (fogofWar) return CellState::FOGOFWAR;
	if (!ship) return CellState::EMPTY;
	else return CellState::SHIP_HERE;
};