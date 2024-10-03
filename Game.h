#ifndef GAME
#define GAME
#include "Field.h"
#include <iostream>
#include <vector>


class Game {

public:
    Game();
    ~Game();
    void setupGame(Field &field, std::vector<Ship>& ships);
private:
    Field* field;
};
#endif