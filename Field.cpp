#include "Field.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include "Error.h"

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
   field.field.clear();
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

// std::vector <std::vector<Cell>>&Field::getField(){
   
//    return field;
// }


Cell& Field::getCell(int x, int y) {

   if (x >= field.size() or y >= field[0].size()) throw "index out of range";
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
         if (newY >= 0 && newY < height && newX >= 0 && newX < width) {
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
   if(orientation < 0 || orientation > 1) return INCORRECT_ORIENTATION;
   if(orientation != orientation_default) ship.switchOrientation();

   if (x < 0 || y < 0 || x >= width || y >= height) return OUT_OF_BOUNDS;
   if ((x + size > width)  && orientation == 0) return SIZE_TOO_LARGE;
   if ((y + size > height) && orientation == 1) return SIZE_TOO_LARGE;

   if (!field[y][x].isEmpty()) return CELL_NOT_EMPTY;
   if (checkSurr(x, y, orientation, size)) return SURROUNDING_CHECK_FAILED;
   
   for (int i = 0; i < size; i++) {
      if (orientation == 0) field[y][x + i].setSegment(i, ship);
      else field[y + i][x].setSegment(i, ship);
   }

   return 0;
}

// int Field::updateField(){

// }

void Field::printField() {
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         Ship *ship = field[i][j].getShip();
         CellState cellState = field[i][j].getStateEnum();
         int index = field[i][j].getSegmant();
         char symbol;
         switch (cellState) {
         case CellState::EMPTY:
            symbol = '.';
            break;
         case CellState::FOGOFWAR:
            symbol = 'F';
            break;
         case CellState::SHIP_HERE: {
            switch (ship->getSegment(index)) {
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