#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <vector>

namespace Tile
{
  enum Enum
  {
    Empty,
    Wall,
    Food
  };
}

class Level 
{
  std::vector<Tile::Enum> grid;
  int width;
  int height;

  Tile::Enum& get_tile(int x, int y);

 public:
  Level(int width, int height);

  bool is_empty(int x, int y);
  bool is_wall(int x, int y);
  bool is_food(int x, int y);

  const Tile::Enum& get(int, int);
  void put(Tile::Enum, int, int);
  void clear(int, int);
};

#endif
