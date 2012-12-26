#ifndef __GFX_H__
#define __GFX_H__

#include <allegro5/allegro.h>

class Gfx {
  ALLEGRO_DISPLAY* display;
 public:
  const ALLEGRO_DISPLAY* get_display() const { return display; }

  Gfx();
  ~Gfx();

  bool init();
};

#endif
