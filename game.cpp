#include "game.h"

Game::Game()
{
}
void Game::new_game()
{
  level = new Level(32, 16);
  snake = new Snake(Point(16, 8), Dir::Up, 3);
}
void Game::quit()
{
  if(level != nullptr) delete level;
  if(snake != nullptr) delete snake;
}
void Game::update()
{
  if(counter > speed) { 
    auto target = snake->get_target();
    if(level->get(target.X, target.Y) == Tile::Food) {
      snake->eat();
      level->clear(target.X, target.Y);
    }
    snake->move(snake->get_dir());
    counter = 0;
  }
  counter++;
}
