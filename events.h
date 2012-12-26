#ifndef __EVENTS_H__
#define __EVENTS_H__

#include <allegro5/allegro.h>
#include <functional>

class Events {
  ALLEGRO_EVENT_QUEUE* events;
  ALLEGRO_TIMER* timer;

  // callbacks
  std::function<void(void)>* update = nullptr;
 public:
  Events();
  ~Events();

  bool init(const ALLEGRO_DISPLAY* display, float fps);
  void run();

  void register_update(const std::function<void(void)>&);
};

#endif
