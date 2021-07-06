#include "move.hpp"
#include <iostream>

Move::Move(int i, int j, int d)
  : coord({i, j}), dir(d){}

void Move::print(){
  std::cout << "i: " << coord.first << " j: " << coord.second << " dir: " << dir << std::endl;
}
