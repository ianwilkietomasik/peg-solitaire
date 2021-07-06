#include<vector>
#include "move.hpp"

class PegSolitaireState {  
  std::vector<std::vector<int>> config;
  std::vector<Move> moves;
public:
  PegSolitaireState();
  PegSolitaireState(std::vector<std::vector<int>> c);
  PegSolitaireState(std::vector<std::vector<int>> c,
		    std::vector<Move> m);
  std::vector<PegSolitaireState> get_next_states();
  std::vector<std::vector<int>> get_config();
  std::vector<Move> get_moves();
  bool is_win();
  void add_move(Move m);
  void print();
  static PegSolitaireState win;
  // bool is_dead();
};
