#include "ShipManager.h"
#include <iostream>

ShipManager::ShipManager(int num, std::initializer_list<int> list)
   :num(num)
{
   if(list.size()!= num) throw std::invalid_argument("Incorrect count of ships");
   const int* tmp = list.begin();
   for (int i = 0; i < num; i++) {
      if(tmp[i] <= 0 || tmp[i] > 4) 
         throw std::invalid_argument("Incorrect lenght");
      ships.push_back(tmp[i]);
   }
}

std::vector<Ship> ShipManager::getShipsVector(){
   return ships;
}