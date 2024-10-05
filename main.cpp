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
    int count = 2;

    Game game;
    Field field(n, m);

    std::initializer_list<int> list = {1, 2};

    ShipManager manager(count, list);
    std::vector<Ship> ships = manager.getShipsVector();

    game.setupGame(field, ships);

    int x1, y1;
    do {
        std::cout << "Enter coord attack" << std::endl;
        std::cin >> x1 >> y1;
    } while (x1 < 0 or x1 >= m or y1 < 0 or y1 >= n);
   
    Cell& cell1 = field.getCell(x1, y1);
    cell1.attackCell();
    std::cout << cell1.getCellState()<<std::endl;
    std::cout << cell1.getSegmentState()<<std::endl;
    field.printField();
    std::cout <<*(ships[0].getSegment(0))<<std::endl;

    // Field b = field;
    // int x2, y2;

    // Cell& cell2 = b.getCell(x2, y2);
    // cell2.attackCell();

    // std::cout << cell2.getStateEnum() <<std::endl;
    // std::cout << cell2.getPoint()<<std::endl;
    // std::cout << cell1.getStateEnum() <<std::endl;
    // std::cout << cell1.getPoint() <<std::endl;


    // field.printField();
    // std::cout << "______" <<std::endl;
    // b.printField();


    // for(int i = 0; i < count; i++){
    //     for(int j = 0; j < ships[i].getLength(); j++)
    //     std::cout << ships[i].getSegment(j) << " "  << i+1 << " " << j+1<< std::endl;
    // }

    // std::cout << "______" <<std::endl;


    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         Cell& cell = b.getCell(i, j);
    //         std::cout << cell.getPoint() <<std::endl;
    //     }
    // }



    // b.printField();

    // Cell& cell1 = b.getCell(x1, y1);

    // std::cout << cell1.getStateEnum() <<std::endl;
    // std::cout << &cell1 <<std::endl;

    //printSegment(ships[0].getSegments());
    // printShips(ships);

    return 0;
}