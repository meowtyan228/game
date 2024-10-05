#include "header.h"

Cell::Cell()
	:fogofWar(false){}

Cell :: ~Cell(){

};

Cell* Cell::getPoint() {
    return this;
}

bool Cell::isEmpty()
{
	return segmentState == nullptr;
}

void Cell::setSegment(SegmentState& segmentState){
	this->segmentState = &segmentState;

}

SegmentState Cell::getSegmentState() {

	return *segmentState;
};

void Cell::attackCell(){ 
	
	if(segmentState) { 
		switch (*segmentState) { 
  		case INTACT: 
			*segmentState = DAMAGED; 
			break; 
  		case DAMAGED: 
   			*segmentState = DESTROYED; 
   			break; 
  		default: 
  			break; 
		}
	}

	fogofWar = false; 
}


CellState Cell::getCellState(){
	if (fogofWar) return CellState::FOGOFWAR;
	if (!segmentState) return CellState::EMPTY;
	else return CellState::SHIP_HERE;
}