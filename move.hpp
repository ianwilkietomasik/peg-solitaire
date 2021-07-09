#include <utility>
#include <string>
class Move{
  std::pair<int, int> coord;
  std::string dir;
public:
  Move(int i, int j, std::string dir);
  void print();
};
