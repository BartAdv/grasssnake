#ifndef __GAME_H__
#define __GAME_H__

#include "snake.h"
#include "level.h"

class Game
{
  Level* level;
  Snake* snake;

  int score = 0;

  int speed; // ticks for move
  int counter = 0;
  Dir dir; 

  Point find_free_tile() const;
public:
  int get_score() const { return score; }
  const Snake& get_snake() const { return *snake; }
  const Level& get_level() const { return *level; }
  Dir get_dir() const { return dir; }

  Game();

  void new_game();
  void quit();
  void update();

  void pause();
  void resume();

  void move(Dir);
};

#endif
