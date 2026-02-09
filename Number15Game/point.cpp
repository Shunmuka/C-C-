#include <iostream>
#include <cassert>
#include "headers/point.h"
#include "headers/direction.h"

Point Point::getAdjacentPoint(const Direction& direction) const
{
  switch(direction.getDirection())
  {
  case (Direction::up): return Point{m_x - 1, m_y};    
  case (Direction::down): return Point{m_x + 1, m_y};
  case (Direction::right): return Point{m_x, m_y + 1};
  case (Direction::left): return Point{m_x, m_y - 1};
  } 
  assert(false && "Point::getAdjacentPoint: Invalid Direction");
}

bool operator==(const Point& p1, const Point& p2)
{
  return (p1.m_x == p2.m_x) && (p1.m_y == p2.m_y);
}