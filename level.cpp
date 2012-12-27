#include <iostream>
#include "level.h"

Level::Level(int width, int height)
  : width(width), height(height)
{
  grid.reserve(width * height);
  for(int i = 0; i < width * height; i++)
    grid.push_back(Tile::Empty);
}
Tile& Level::get_tile(int x, int y)
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
const Tile& Level::get(int x, int y)
{
  return get_tile(x, y);
}
void Level::put(Tile what, int x, int y)
{
  std::cout << x << ", " << y << std::endl;
  get_tile(x, y) = what;
}
void Level::clear(int x, int y)
{
  get_tile(x, y) = Tile::Empty;
}
void Level::iter(std::function<void(int, int, Tile)> callback) const
{
  int i = 0;
  for(auto tile : grid) {
    callback(i % width, i / width, tile);
    i++; 
 }
}
