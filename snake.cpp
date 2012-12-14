#include <stdexcept>
#include "snake.h"

Point Point::move(Dir::Enum dir) const
{
  switch(dir)
  {
  case Dir::Up: return Point(X, Y-1);
  case Dir::Right: return Point(X+1, Y);
  case Dir::Down: return Point(X, Y+1);
  case Dir::Left: return Point(X-1, Y);
  default: throw std::invalid_argument("dir");
  }
}
bool Point::operator==(const Point& rhs) const
{
  return rhs.X == this->X && rhs.Y == this->Y;
}
bool Point::operator!=(const Point& rhs) const
{
  return rhs.X != this->X || rhs.Y != this->Y;
}

Dir::Enum Dir::opposite(Dir::Enum dir)
{
  switch(dir)
  {
  case Dir::Up: return Dir::Down;
  case Dir::Right: return Dir::Left;
  case Dir::Down: return Dir::Up;
  case Dir::Left: return Dir::Right;
  default: throw std::invalid_argument("dir");
  }
}

Snake::Snake(Point head, Dir::Enum dir, int length)
  : dir(dir)
{
  auto d = Dir::opposite(dir);
  auto pt = head;
  for(int i = 0; i < length; i++, pt = head.move(d))
    points.push_back(pt);
}
void Snake::iter(std::function<void(const Point&)> func)
{
  for(auto it : points)
    func(it);
}

void Snake::turn(Dir::Enum dir)
{
  this->dir = dir;
}
void Snake::move()
{
  // move every segment into place of previous
  for(auto seg = points.end()-1; seg != points.begin(); seg--)
    *seg = *(seg - 1);
  // move the head
  auto head = points.begin();
  *head = head->move(this->dir);
}
