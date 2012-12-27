#include <time.h>
#include <stdlib.h>
#include "game.h"

Game::Game()
  : speed(20)
{
  srand(time(nullptr));
}
void Game::new_game()
{
  level = new Level(32, 16);
  snake = new Snake(Point(16, 8), Dir::Up, 3);
  dir = Dir::Up;
  Point p = find_free_tile();
  level->put(Tile::Food, p.X, p.Y);
}
void Game::quit()
{
  if(level != nullptr) delete level;
  if(snake != nullptr) delete snake;
}
void Game::update()
{
  bool ate = false;
  if(counter > speed) { 
    auto target = snake->get_target();
    if(level->get(target.X, target.Y) == Tile::Food) {
      snake->eat();
      level->clear(target.X, target.Y);
      speed *= 0.9;
      ate = true;
    }
    snake->move(dir);
    if(ate) {
      Point f = find_free_tile();
      level->put(Tile::Food, f.X, f.Y);
      ate = false;
    }
    counter = 0;
  }
  counter++;
}
void Game::move(Dir dir)
{
  this->dir = dir;
}
Point Game::find_free_tile() const
{
  while(true) {
    int x = rand() % level->get_width();
    int y = rand() % level->get_height();
    Point pt(x, y);

    if(level->get(x, y) != Tile::Empty) continue;
    if(snake->contains(pt)) continue;

    return pt;
  }
}
