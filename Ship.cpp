#include "Ship.h"
#include <iostream>
#include <vector>



Ship::Ship(int length)
   :length(length), orientation(HORIZONTAL){
   segments.resize(length);
}

Ship::~Ship()
{
}

std::vector<SegmentState>& Ship::getSegments() {
    return segments;
}

void Ship::changeState(int index){

   if(segments[index] == INTACT)
      segments[index] = DAMAGED;
   else if(segments[index] == DAMAGED)
      segments[index] = DESTROYED;

}

SegmentState& Ship:: getSegment(int index) {

   return segments[index];
}

int Ship::getOrientation()
{
   return orientation;
}

void Ship::switchOrientation()
{
   if (orientation == VERTICAL)
   {
      orientation = HORIZONTAL;
   }
   else
   {
      orientation = VERTICAL;
   }
  
}

int Ship :: getLength(){

   return length;
}