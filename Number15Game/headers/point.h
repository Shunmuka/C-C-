#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "direction.h"

class Point
{
public:
  explicit Point(int x=0, int y=0) : m_x{x}, m_y{y}{}
  Point getAdjacentPoint(const Direction& direction) const;
  int x() const { return m_x; }
  int y() const { return m_y; }
  friend bool operator==(const Point& p1, const Point& p2);
  friend bool operator!=(const Point& p1, const Point& p2) { return !(p1 == p2); }

private:
  int m_x{};
  int m_y{};
};

#endif