#include <iostream>
#include <string>
#include <vector>
#include "snake.h"

void assert(bool cond, std::string message)
{
  if(cond)
    std::cout << message << " succeeded" << std::endl;
  else
    std::cout << message << " FAILED!" << std::endl;
}

bool initial_setup()
{
  int hx = 10;
  int hy = 10;
  auto snake = Snake(Point(hx, hy), Dir::Up, 2);
  auto res = true;

  snake.iter([=, &res, &hy](const Point& pt) -> 
	     void { if(pt != Point(hx, hy++)) res = false; });
  return res;
}
bool move_up()
{
  int hx = 10;
  int hy = 10;
  auto snake = Snake(Point(hx, hy), Dir::Up, 3);
  snake.move();
  
  hy--;
  auto res = true;
  snake.iter([=, &res, &hy](const Point& pt) ->
	     void { if(pt != Point(hx, hy++)) res = false; });

  return res;
}
bool move_left()
{
  int hx = 10, hy = 10;
  auto snake = Snake(Point(hx, hy), Dir::Up, 3);
  snake.turn(Dir::Left);
  snake.move();
  // gather the segments, since we haven't got access to them directly
  std::vector<Point> points;
  snake.iter([&points](const Point& pt) -> 
	     void { points.push_back(pt); });

  if(points[0] != Point(hx-1, hy)) return false;
  if(points[1] != Point(hx, hy)) return false;
  if(points[2] != Point(hx, hy+1)) return false;
  return true;
}
bool move_right()
{
  int hx = 10, hy = 10;
  auto snake = Snake(Point(hx, hy), Dir::Up, 3);
  snake.turn(Dir::Right);
  snake.move();

  std::vector<Point> points;
  snake.iter([&points](const Point& pt) -> void { points.push_back(pt); });

  if(points[0] != Point(hx+1, hy)) return false;
  if(points[1] != Point(hx, hy)) return false;
  if(points[2] != Point(hx, hy+1)) return false;
  return true;
}
bool move_down()
{
  int hx = 10, hy = 10;
  auto snake = Snake(Point(hx, hy), Dir::Right, 3);
  snake.turn(Dir::Down);
  snake.move();

  std::vector<Point> points;
  snake.iter([&points](const Point& pt) -> void { points.push_back(pt); });

  if(points[0] != Point(hx, hy+1)) return false;
  if(points[1] != Point(hx, hy)) return false;
  if(points[2] != Point(hx-1, hy)) return false;

  return true;
}
int main()
{
  std::cout << "Running tests..." << std::endl;
  assert(initial_setup(), "Initial setup"); 
  assert(move_up(), "Moving up");  
  assert(move_left(), "Moving left");
  assert(move_right(), "Moving right");  
  assert(move_down(), "Moving down");  
  return 0;
}
