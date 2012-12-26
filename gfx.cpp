#include <stdexcept>
#include "gfx.h"

Gfx::Gfx()
  : display(nullptr)
{
}
Gfx::~Gfx()
{
  if(display != nullptr) {
    al_destroy_display(display);
  }
}
bool Gfx::init()
{
  if(display != nullptr) 
    throw std::logic_error("Allegro display already initialized");
  
  display = al_create_display(640, 480);
  if(display == nullptr) {
    fprintf(stderr, "failed to create display!\n");
    return false;
  }

  return true;
}
