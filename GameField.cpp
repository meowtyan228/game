#include "GameField.h"
#include <stdexcept>
#include <iostream>
#include <vector>


enum class ERROR
{
   OUT_OF_BOUNDS,           // Координаты вне границ поля
   SIZE_TOO_LARGE,          // Размер корабля превышает границы поля
   CELL_NOT_EMPTY,          // Ячейка уже занята
   SURROUNDING_CHECK_FAILED // Проверка соседних ячеек не пройдена
   
};


Field::Field(int n, int m)
   : height(n), width(m){
   field.resize(height, std::vector<Cell>(width));
}

Field::~Field()
{
}

std::vector <std::vector<Cell>>&Field::getField(){
   
   return field;
}

Cell& Field::getCell(int x, int y) {
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

int Field::placeShip(int x, int y, Ship& ship)
{
   int orientation = ship.getOrientation();
   int size = ship.getLength();

   if (x < 0 || y < 0 || x >= width || y >= height) return -1;
   if ((x + size > width)  && orientation == 0) return -1;
   if ((y + size > height) && orientation == 1) return -1;
   if (!field[y][x].isEmpty()) return -1;
   if (checkSurr(x, y, orientation, size)) return -1;
   if (orientation == 0) {
      for (int i = 0; i < size; i++) {
         field[y][x + i].setSegment(i, ship);
         //ship.getSegment(field[y][x + i].getSegmant()).state = DAMAGED;
         //std::cout <<  field[y][x + i].getSegmant()<<std::endl;
         //std::cout <<ship.getSegment(field[y][x + i].getSegmant()).state<<std::endl;
      }
   }
   else {
      for (int i = 0; i < size; i++) {
         field[y + i][x].setSegment(i, ship);
      }
   }

   return 0;
}

// int Field::updateField(){

// }


void Field::printField() {
   for (int i = 0; i < height; i++) {
      for (int j = 0; j < width; j++) {
         char symbol;
         switch (field[i][j].getStateEnum()) {
         case CellState:: EMPTY:
            symbol = '.';
            break;
         case CellState:: SHIP_HERE:
            symbol = 'X';
            break;
         // case SegmentState:: DAMAGED:
         //    symbol = 'd';
         //    break;
         // case SegmentState:: DESTROYED:
         //    symbol = 'D';
         //    break;
         case CellState:: FOGOFWAR:
            symbol = 'F';
            break;
         }
         std::cout << symbol << " ";  // Выводим символ для клетки
      }
      std::cout << std::endl;  // Переход на новую строку после каждой строки поля
   }
}