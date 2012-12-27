#ifndef __GFX_H__
#define __GFX_H__

#include <allegro5/allegro.h>
#include "snake.h"
#include "level.h"

class Gfx {
  ALLEGRO_DISPLAY* display;
  ALLEGRO_BITMAP* square;
 public:
  const ALLEGRO_DISPLAY* get_display() const { return display; }

  Gfx();
  ~Gfx();

  bool init();
  void draw_snake(const Snake&);
  void draw_level(const Level&);  
  void present();
  void begin();
};

#endif
