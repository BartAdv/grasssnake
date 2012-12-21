#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <deque> 
#include <functional>

namespace Dir
{
  enum Enum
  {
    Up,
    Right,
    Down,
    Left
  };
  Enum opposite(Enum dir);
}

struct Point
{
  int X;
  int Y;
  Point(int x, int y) : X(x), Y(y) {};
  Point move(Dir::Enum) const;
  bool operator==(const Point&) const;
  bool operator!=(const Point&) const;
};

class Snake
{
  std::deque<Point> points;
  Dir::Enum dir;
public:
  Snake(Point head, Dir::Enum dir = Dir::Up, int length = 2);
  void move();
  void turn_left();
  void turn_right();
  void eat();
  
  // checks whether snake would eat himself on potential move
  bool can_move() const;
  void iter(std::function<void(const Point&)> func);
};

#endif
