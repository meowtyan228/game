#include "header.h"

Field::Field(int n, int m)
   : height(n), width(m){
   field.resize(height, std::vector<Cell>(width));
}

Field::~Field()
{
}


void Field ::copyField(const Field& field) {

   width = field.width;
   height = field.height;

   this->field.resize(field.field.size());

   for (int i = 0; i < field.field.size(); i++) {
      this->field[i].resize(field.field.size());
      for (int j = 0; j < field.field[i].size(); j++) {
         this->field[i][j] = field.field[i][j];
      }
   }
}

Field::Field(const Field& field)
{
   copyField(field);
}


Field::Field(Field&& field)
{

   width = field.width;
   height = field.height;

   this->field = std::move(field.field);

   field.width = 0;
   field.height = 0;
}



Field& Field::operator=(Field&& field)
{
   width = field.width;
   height = field.height;

   if(this != &field){
      this->field = std::move(field.field);
   }

   return *this;
}

Field& Field::operator=(const Field& field)
{
   if (this != &field) {
      copyField(field);
   }

   return *this;
}

Cell& Field::getCell(int x, int y) {

   if (x >= field.size() or y >= field[0].size()) throw std::out_of_range ("Index out of range");
   return field[y][x];
}

int Field::checkSurr(int x, int y, int orientation, int size) {

   int checkWidth = (orientation == 0) ? size : 1;
   int checkHeight = (orientation == 0) ? 1 : size;

   for (int dy = -1; dy <= checkHeight; dy++) {
      for (int dx = -1; dx <= checkWidth; dx++) {
         if (dx == 0 && dy == 0) continue;
         int newY = y + dy;
         int newX = x + dx;
         if (newY >= 0 and newY < height and newX >= 0 and newX < width) {
            if (!field[newY][newX].isEmpty()) {
               return 1;
            }
         }
      }
   }
   return 0; 
}

int Field::placeShip(int x, int y, int orientation, Ship& ship)
{
   int orientation_default = ship.getOrientation();
   int size = ship.getLength();

   if(orientation < 0 or orientation > 1) return INCORRECT_ORIENTATION;
   if(orientation != orientation_default) ship.switchOrientation();

   if (x < 0 or y < 0 or x >= width or y >= height) return OUT_OF_BOUNDS;
   if ((x + size > width)  and orientation == 0) return SIZE_TOO_LARGE;
   if ((y + size > height) and orientation == 1) return SIZE_TOO_LARGE;

   if (!field[y][x].isEmpty()) return CELL_NOT_EMPTY;
   if (checkSurr(x, y, orientation, size)) return SURROUNDING_CHECK_FAILED;
   
   for (int i = 0; i < size; i++) {
      SegmentState* segmentPtr = ship.getSegment(i);
      if (orientation == 0) field[y][x + i].setSegment(*segmentPtr);
      else field[y + i][x].setSegment(*segmentPtr);
   }

   return 0;
}

void Field::printField() {
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         CellState cellState = field[i][j].getCellState();
         char symbol;
         switch (cellState) {
         case CellState::EMPTY:
            symbol = '.';
            break;
         case CellState::FOGOFWAR:
            symbol = 'F';
            break;
         case CellState::SHIP_HERE: {
            SegmentState segmentState = field[i][j].getSegmentState();
            switch (segmentState) {
               case DAMAGED:
                  symbol = 'D';
                  break;
               case INTACT:
                  symbol = 'X';
                  break;
               case DESTROYED:
                  symbol = 'Y';
                  break;
               default:
                  break;
               }
               break;
         }
         default:
            break;
         }
         std::cout << symbol << " ";
      }
      std::cout << std::endl;
   
   }
}