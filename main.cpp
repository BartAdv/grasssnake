#include <iostream>
#include "snake.h"
#include "game.h"
#include "gfx.h"

ALLEGRO_EVENT_QUEUE* init_events()
{
  ALLEGRO_EVENT_QUEUE* events = al_create_event_queue();
  if(events == nullptr) {
    std::cerr << "failed to create event queue!" << std::endl;
  }
  return events;
}
ALLEGRO_TIMER* init_timer(float fps)
{
  ALLEGRO_TIMER* timer = al_create_timer(1.0 / fps);
  if(timer == nullptr) {
    std::cerr << "failed to create timer!" << std::endl;
  }
  return timer;
}

int main()
{
  Gfx gfx;
  Game game;

  if(!al_init()) {
    std::cerr << "Failed to initialize allegro!" << std::endl;
    return -1;
  }
  if(!al_install_keyboard()) {
    std::cerr << "Failed to install keyboard!" << std::endl;
    return -1;
  }
  gfx.init();
  ALLEGRO_EVENT_QUEUE* events = init_events();
  ALLEGRO_TIMER* timer = init_timer(60.0);

  al_register_event_source(events, al_get_timer_event_source(timer));
  al_start_timer(timer);
  al_register_event_source(events, al_get_keyboard_event_source());
  al_register_event_source(events, al_get_display_event_source(const_cast<ALLEGRO_DISPLAY*>(gfx.get_display())));

  game.new_game();
  ALLEGRO_EVENT ev;
  bool redraw = true;

  while(true) {
    al_wait_for_event(events, &ev);
    
    if(ev.type == ALLEGRO_EVENT_TIMER) {
      game.update();
      redraw = true;
    } 
    else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
      switch(ev.keyboard.keycode) {
      case ALLEGRO_KEY_UP:
	game.move(Dir::Up);
	break;
      case ALLEGRO_KEY_RIGHT:
	game.move(Dir::Right);
	break;
      case ALLEGRO_KEY_DOWN:
	game.move(Dir::Down);
	break;
      case ALLEGRO_KEY_LEFT:
	game.move(Dir::Left);
	break;
      }
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
      break;
    if(redraw && al_is_event_queue_empty(events)) {
      gfx.begin();
      gfx.draw_level(game.get_level());
      gfx.draw_snake(game.get_snake());
      gfx.present();

      redraw = false;
    }
  }

  if(events != nullptr) {
    al_destroy_event_queue(events);
  }
  if(timer != nullptr) {
    al_destroy_timer(timer);
  }

  return 0;
}
