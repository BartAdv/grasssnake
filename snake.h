#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <deque> 
#include <functional>

enum class Dir
{
  Up,
  Right,
  Down,
  Left
};
Dir opposite(Dir);


struct Point
{
  int X;
  int Y;
  Point(int x, int y) : X(x), Y(y) {};
  Point move(Dir) const;
  bool operator==(const Point&) const;
  bool operator!=(const Point&) const;
};

class Snake
{
  std::deque<Dir> segments;
  Point head;
public:
  const Dir get_dir() const { return opposite(segments[0]); }
  Point get_target() const { return head.move(get_dir()); }

  Snake(Point head, Dir dir = Dir::Up, int length = 2);
  void move(Dir);
  void eat();
  
  // checks whether snake would eat himself on potential move
  bool can_move(Dir) const;
  void iter(std::function<void(const Point&)> func);
};

#endif
