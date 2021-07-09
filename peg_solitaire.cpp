#include <vector>
#include "peg_solitaire.hpp"
#include <iostream>

std::vector<Move> PegSolitaireSolver::solve(PegSolitaireState state){
  if(state.is_win()){
    return state.get_moves();
  }
  for(auto s : state.get_next_states()){
    std::vector<Move> res = solve(s);
    if(!res.empty()){
      return res;
    }
  }
  return {};
}
