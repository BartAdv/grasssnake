#ifndef __GAME_H__
#define __GAME_H__

#include "snake.h"
#include "level.h"

class Game
{
  Level* level;
  Snake* snake;

  int score = 0;

  int speed = 500; // milliseconds for move
  int last_tick = 0; 
public:
  int get_score() const { return score; }
  const Snake* get_snake() const { return snake; }
  const Level* get_level() const { return level; }
  
  Game();

  void new_game();
  void quit();
  void update(int); // delta in milliseconds
  void pause();
  void resume();
};

#endif
