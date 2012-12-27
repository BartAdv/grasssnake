#include <iostream>
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
    std::cerr << "failed to create display!" << std::endl;
    return false;
  }

  square = al_create_bitmap(16, 16);
  if(square == nullptr) {
    std::cerr << "failed to create bitmap!" << std::endl;
    return false;
  }
  al_set_target_bitmap(square);
  al_clear_to_color(al_map_rgb(0, 255, 0));

  al_set_target_bitmap(al_get_backbuffer(display));
  return true;
}
void Gfx::draw_snake(const Snake& snake)
{
  snake.iter([this](const Point& pt) {
      al_draw_bitmap(square, pt.X * 16, pt.Y * 16, 0);
    });
}
void Gfx::present()
{
  al_flip_display();
}
void Gfx::begin()
{
  al_clear_to_color(al_map_rgb(0, 0, 0));
}
