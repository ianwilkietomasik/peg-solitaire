#include <utility>
class Move{
  std::pair<int, int> coord;
  int dir;
public:
  Move(int i, int j, int dir);
  void print();
};
