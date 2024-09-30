#include <iostream>
#include "GameField.h"
#include "Ship.h"

void printShips(const std::vector<Ship>& ships) {
    for (const auto& ship : ships) {
        std::cout << &ship << " ";
    }
    std::cout << std::endl;
}

void printSegment(const std::vector<Ship::Segment> &segments) {
    for (const auto& segment : segments) {
        std::cout << segment.state << " ";
    }
    std::cout << std::endl;
}


int main() {

   std::initializer_list<int> list = {1, 1, 1, 1, 2};
   int count = list.size();
   Field field(10, 10);
   ShipManager manager(count, list);
   std::vector<Ship> ships = manager.getShipsVector();
   int x, y;
   for (int i = 0; i < count; i++) {
      std::cin >> x;
      std::cin >> y;
      field.placeShip(x, y, ships[i]);
   }

    std::cout <<&ships[3].getSegment(40)<< std::endl;

    printSegment(ships[3].getSegments());


    field.printField();
    printShips(ships);
   
   return 0;
}