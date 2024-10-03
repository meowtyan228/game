#include <iostream>
#include "Field.h"
#include "Ship.h"
#include "Cell.h"
#include "Game.h"

// void printShips(const std::vector<Ship>& ships) {
//     for (const auto& ship : ships) {
//         std::cout << &ship << " ";
//     }
//     std::cout << std::endl;
// }

// void printSegment(const std::vector<SegmentState> &segments) {
//     for (const auto& segment : segments) {
//         std::cout << segment << " ";
//     }
//     std::cout << std::endl;
// }

int main() {

    Game game;
    Field field(10, 10);
    std::initializer_list<int> list = {1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
    int count = list.size();
    ShipManager manager(count, list);
    std::vector<Ship> ships = manager.getShipsVector();
    game.setupGame(field, ships);
    field.printField();

    int x1, y1;
    std::cin >> x1 >> y1; 
    Cell& cell = field.getCell(x1, y1);
    cell.attackCell();

    field.printField();
    // printSegment(ships[0].getSegments());
    // printShips(ships);
    return 0;
}