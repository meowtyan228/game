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