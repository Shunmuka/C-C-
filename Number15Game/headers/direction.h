#ifndef DIRECTION_H
#define DIRECTION_H

#include <iostream>
#include "random.h"

class Direction
{
public:
  enum Type
  {
    up,
    down,
    right,
    left,
    maxTypeLen
  };
  
  Direction() = default;
  Direction(Type direction) : m_direction{direction} {}
  Direction operator-() const;
  friend std::ostream& operator<<(std::ostream& out, const Direction& direction);
  static inline Direction getRandom() { return static_cast<Direction::Type>(Random::get(0, 4)); }
  Direction::Type getDirection() const{ return m_direction; }

private:
  Type m_direction{};
};

#endif