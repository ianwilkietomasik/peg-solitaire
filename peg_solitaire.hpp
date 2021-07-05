#include<vector>
#include "ps_state.hpp"
class PegSolitaireSolver {
public:
  PegSolitaireSolver(config);
  std::vector<std::pair<int,int>> solve();
}
