#include "move.hpp"
#include <iostream>

Move::Move(int i, int j, std::string d)
  : coord({i, j}), dir(d){}

void Move::print(){
  std::cout << "(" << coord.first << ", " << coord.second << ")" << " : " << dir << std::endl;
}
