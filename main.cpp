#include <iostream>
#include "snake.h"
#include "game.h"
#include "gfx.h"
#include "events.h"

int main()
{
  Gfx gfx;
  Events events;
  Game game;

  if(!al_init()) {
    fprintf(stderr, "failed to initialize allegro!\n");
    return -1;
  }

  gfx.init();
  events.init(gfx.get_display(), 2.0);  
  events.register_update([]() { std::cout << "Tick!" << std::endl; });
  std::cout << "Hello" << std::endl;  
  events.run();  
  return 0;
}
