#include "level.h"

Level::Level(int width, int height)
  : width(width), height(height)
{
  grid.reserve(width * height);
  for(int i = 0; i < width * height; i++)
    grid.push_back(Tile::Empty);
}
Tile::Enum& Level::get_tile(int x, int y)
{
  return grid[y * width + x];
}
bool Level::is_empty(int x, int y)
{
  return get_tile(x, y) == Tile::Empty;
}
bool Level::is_wall(int x, int y)
{
  return get_tile(x, y) == Tile::Wall;
}
bool Level::is_food(int x, int y)
{
  return get_tile(x, y) == Tile::Food;
}
void Level::put(Tile::Enum what, int x, int y)
{
  get_tile(x, y) = what;
}
