#include <iostream>
#include "GameField.h"
#include "Ship.h"
#include "Cell.h"

void printShips(const std::vector<Ship>& ships) {
    for (const auto& ship : ships) {
        std::cout << &ship << " ";
    }
    std::cout << std::endl;
}

void printSegment(const std::vector<SegmentState> &segments) {
    for (const auto& segment : segments) {
        std::cout << segment << " ";
    }
    std::cout << std::endl;
}


int main() {

    std::initializer_list<int> list = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    int count = list.size();
    Field field(10, 10);
    ShipManager manager(count, list);
    std::vector<Ship> ships = manager.getShipsVector();
    int x, y;
    for (int i = 0; i < count; i++) {
        std::cin >> x >> y;

        field.placeShip(x, y, ships[i]);
    }

    int x1, y1;
    std::cin >> x1 >> y1;
    Cell& cell = field.getCell(x1, y1);
    cell.attackCell();
    cell.attackCell();
    field.printField();
    // std::cout << cell.getShip()<<std::endl;
    // printSegment(ships[0].getSegments());
    //printShips(ships);
    return 0;
}