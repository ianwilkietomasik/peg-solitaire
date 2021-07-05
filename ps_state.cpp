#include <iostream>
#include "ps_state.hpp"

PegSolitaireState PegSolitaireState::win(
					 {
					  {2,2,0,0,0,2,2},
					  {2,2,0,0,0,2,2},
					  {0,0,0,0,0,0,0},
					  {0,0,0,1,0,0,0},
					  {0,0,0,0,0,0,0},
					  {2,2,0,0,0,2,2},
					  {2,2,0,0,0,2,2}
					 }
					 );

std::vector<std::vector<int>> PegSolitaireState::get_config(){
  return config;
}

bool is_valid_square(std::pair<int,int> p){
  if(p.second > 1 && p.second < 5){
    return p.first > -1 && p.first < 7;
  }
  else if ((p.second < 2 && p.second > -1) ||
	   (p.second > 4 && p.second < 7)){
    return p.first > 1 && p.first < 5;
  }
  return false;
}

PegSolitaireState::PegSolitaireState(){
  std::vector<std::vector<int>> c(7, std::vector<int>(7));
  config = c;
  for(int i = 0; i < 7; i++){
    for(int j  = 0; j < 7; j++){
      if(j == i && j == 3){
	config[i][j] = 0;
      }
      else{
	config[i][j] = is_valid_square({i, j}) ? 1 : 2;
      }
    }
  }
}

PegSolitaireState::PegSolitaireState(std::vector<std::vector<int>> c)
  : config(c){}

std::vector<std::pair<int,int>> get_adjacent_squares(std::pair<int, int> pos, bool next){
  return {
	  {pos.first + 1 + next, pos.second}, // down
	  {pos.first - 1 - next, pos.second}, // up
	  {pos.first, pos.second + 1 + next}, // right
	  {pos.first, pos.second - 1 - next}  // left
  };
}

std::vector<PegSolitaireState> PegSolitaireState::get_next_states(){
  std::vector<PegSolitaireState> next_states;
  for(int i = 0; i < 7; i++){
    for(int j = 0; j < 7; j++){
      if(config[i][j] == 1){
	std::vector<std::pair<int, int>> jumps = get_adjacent_squares({i, j}, false);
	std::vector<std::pair<int, int>> dests = get_adjacent_squares({i, j}, true);
	for(int k = 0; k < 4; k++){
	  if(is_valid_square(jumps[k]) && is_valid_square(dests[k]) &&
	     config[jumps[k].first][jumps[k].second] && !config[dests[k].first][dests[k].second]){
	    std::vector<std::vector<int>> new_config = config;
	    new_config[i][j] = 0;
	    new_config[jumps[k].first][jumps[k].second] = 0;
	    new_config[dests[k].first][dests[k].second] = 1;
	    PegSolitaireState new_state(new_config);
	    next_states.push_back(new_state);
	  }
	}
      }
    }
  }
  return next_states;
}

bool PegSolitaireState::is_win(){
  return config == PegSolitaireState::win.get_config();
}

void PegSolitaireState::print(){
  for(int i = 0; i < 7; i++){
    for(int j = 0; j < 7; j++){
      std::cout << config[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
