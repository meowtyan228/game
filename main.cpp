#include "header.h"

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

    int m = 10;
    int n = 10;

    Game game;
    Field field(n, m);

    std::initializer_list<int> list = {1};

    int count = list.size();

    ShipManager manager(count, list);
    std::vector<Ship> ships = manager.getShipsVector();
    game.setupGame(field, ships);

    int x1, y1;
    std::cin >> x1 >> y1;
    Cell& cell1 = field.getCell(x1, y1);
    std::cout << cell1.getPoint() <<std::endl;

    int x2, y2;
    std::cin >> x2 >> y2;
    Cell& cell2 = field.getCell(x2, y2);
    std::cout << cell2.getPoint() <<std::endl;

    // cell.attackCell();
    // field.printField();

    //std::cout <<&field <<std::endl;

    // Field b = field;
    // std::cout <<&b <<std::endl;

    // b.printField();

    // Cell& cell1 = b.getCell(x1, y1);

    // std::cout << cell1.getStateEnum() <<std::endl;
    // std::cout << &cell1 <<std::endl;

    //printSegment(ships[0].getSegments());
    // printShips(ships);
    return 0;
}