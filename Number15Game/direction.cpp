#include <iostream>
#include <cassert>
#include "headers/direction.h"
#include "headers/random.h"

Direction Direction::operator-() const
{
  switch(m_direction)
  {
  case (Direction::right): return Direction{Direction::left};
  case (Direction::left): return Direction{Direction::right};
  case (Direction::down): return Direction{Direction::up};
  case (Direction::up): return Direction{Direction::down};
  }
  assert(false && "Direction::operator-: invalid key");
}

std::ostream& operator<<(std::ostream& out, const Direction& direction)
{
  switch(direction.m_direction)
  {
  case (Direction::right): 
    out << "right";
    break;
  case (Direction::left): 
    out << "left";
    break;
  case (Direction::down): 
    out << "down";
    break;
  case (Direction::up): 
    out << "up";
    break;
  }
  return out;
}

