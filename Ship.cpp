#include "header.h"


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

SegmentState Ship::getSegment(int index) {
   if (index < 0 || index >= length) {
         throw std::out_of_range("Index out of range");
   }
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