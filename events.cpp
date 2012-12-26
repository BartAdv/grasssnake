#include <iostream>
#include <stdexcept>
#include "events.h"

Events::Events()
  : events(nullptr),
    timer(nullptr) 
{
}
Events::~Events() 
{
  if(events != nullptr) {
    al_destroy_event_queue(events);
  }
  if(timer != nullptr) {
    al_destroy_timer(timer);
  }
  if(update != nullptr)
    delete update;
}

bool Events::init(const ALLEGRO_DISPLAY* display, float fps)
{
  events = al_create_event_queue();
  if(events == nullptr) {
    std::cerr << "failed to create event queue!" << std::endl;
    return false; 
  }

  timer = al_create_timer(1.0 / fps);
  if(timer == nullptr) {
    std::cerr << "failed to create timer!" << std::endl;
    return false;
  }

  al_register_event_source(events, al_get_timer_event_source(timer));
  al_start_timer(timer);
  al_register_event_source(events, al_get_display_event_source(const_cast<ALLEGRO_DISPLAY*>(display)));
}
void Events::run()
{
  ALLEGRO_EVENT ev;
  while(true) {
    al_wait_for_event(events, &ev);
    
    if(ev.type == ALLEGRO_EVENT_TIMER) {
      if(update != nullptr)
	(*update)();    
    } 
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
      break;
  }
}
void Events::register_update(const std::function<void()>& callback)
{
  if(update != nullptr)
    throw std::logic_error("Update callback already registered");

  this->update = new std::function<void()>(callback);
}
