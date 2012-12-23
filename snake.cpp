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
  : head(head)
{
  auto d = Dir::opposite(dir);
  for(int i = 0; i < length-1; i++)
    segments.push_back(d);
}
void Snake::iter(std::function<void(const Point&)> func)
{
  Point pt = head;
  func(pt);
  for(auto seg : segments)
  {
    pt = pt.move(seg);
    func(pt);
  }
}
void Snake::move(Dir::Enum dir)
{
  head = head.move(dir);
  segments.push_front(Dir::opposite(dir));
  segments.pop_back();
}
void Snake::eat()
{
  auto last = segments.back();
  segments.push_back(last);
}

bool Snake::can_move(Dir::Enum dir) const
{
  auto target = head.move(dir);
  Point pt = head;
  for(auto seg : segments)
  {
    pt = pt.move(seg);
    if(pt == target)
      return false;
  }
  return true;
}
