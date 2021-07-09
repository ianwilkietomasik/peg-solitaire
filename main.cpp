#include "peg_solitaire.hpp"
#include <iostream>
int main(){
  PegSolitaireSolver solver;
  PegSolitaireState state;
  std::vector<Move> soln = solver.solve(state);
  for(auto m : soln){
    m.print();
  }
  return 0;
}
