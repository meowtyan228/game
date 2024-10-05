#include "Game.h"
#include <iostream>
#include <limits>
#include "Error.h"
using namespace std;

Game::Game(){
}


Game::~Game()
{
}

void Game::setupGame(Field& field, std::vector<Ship>& ships) {

    int x, y, orientation;

    for (int i = 0; i < ships.size(); i++) {
        bool placed = false;
        while (!placed) {
            cout << "Input coordinates and orientation for ship " << i + 1 << " (x,y,o): ";
            cin >> x >> y >> orientation;

            if (cin.fail()) {
                cout <<"\033[95mInvalid input, please enter numbers for x and y coordinates and for orientation!\033[0m" << endl;
                cin.clear();
                cin.ignore(numeric_limits<std::streamsize>::max(),'\n');
                continue;
            }
            switch (field.placeShip(x, y, orientation, ships[i]))
            {
            case OUT_OF_BOUNDS:
                cout << "\033[95mInvalid coordinates, out of bounds, try again!\033[0m" << endl;
                break;
            case INCORRECT_ORIENTATION:
                cout << "\033[95mInvalid coordinates, incorrect orientation, try again!\033[0m" << endl;
                break;
            case SIZE_TOO_LARGE:
                cout << "\033[95mInvalid coordinates, size too large, try again!\033[0m" << endl;
                break;
            case CELL_NOT_EMPTY:
                cout << "\033[95mInvalid coordinates, cell is not empty, try again!\033[0m" << endl;
                break;
            case SURROUNDING_CHECK_FAILED:
                cout << "\033[95mInvalid coordinates, surrounding check failed try again!\033[0m" << endl;
                break;
            default:
                placed = true;
                cout << "\033[96mThe ship has been successfully deployed!\033[0m" << endl;
                field.printField();
                break;
            }

        }
    }
};