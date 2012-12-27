#ifndef __LEVEL_H__
#define __LEVEL_H__

#include <vector>
#include <functional>

enum class Tile
{
  Empty,
  Wall,
  Food
};

class Level 
{
  std::vector<Tile> grid;
  int width;
  int height;

  Tile& get_tile(int x, int y);

 public:
  int get_width() const { return width; }
  int get_height() const { return height; }

  Level(int width, int height);

  bool is_empty(int x, int y);
  bool is_wall(int x, int y);
  bool is_food(int x, int y);

  const Tile& get(int, int);
  void put(Tile, int, int);
  void clear(int, int);
  void iter(std::function<void(int, int, Tile)>) const;
};

#endif
