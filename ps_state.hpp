#include<vector>
class PegSolitaireState {  
  std::vector<std::vector<int>> config;
public:
  PegSolitaireState();
  PegSolitaireState(std::vector<std::vector<int>> c);
  std::vector<PegSolitaireState> get_next_states();
  std::vector<std::vector<int>> get_config();
  bool is_win();
  void print();
  static PegSolitaireState win;
  // bool is_dead();
};
