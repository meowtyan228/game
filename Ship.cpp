#include "Ship.h"
#include <iostream>
#include <vector>



Ship::Ship(int length)
   :length(length), orientation(HORIZONTAL) {
   segments.resize(length);
}

Ship::~Ship()
{
}

std::vector<Ship::Segment>& Ship::getSegments() {

    return segments;
}



// Ship::Segment& Ship::setSegment(int n, Cell& cell){

// }

void Ship::changeState(int index){

   if(segments[index].state == INTACT)
      segments[index].state = DAMAGED;
   else if(segments[index].state == DAMAGED)
      segments[index].state = DESTROYED;

}

Ship::Segment& Ship:: getSegment(int index) {

   return segments.at(index);
}




int Ship::getOrientation()
{
   return orientation;
}

int Ship::switchOrientation()
{
   return orientation = ~orientation;
}

int Ship :: getLength(){

   return length;
}