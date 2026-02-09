#include <iostream>
#include "headers/tile.h"

std::ostream& operator<<(std::ostream& out, const Tile& tile)
{
  if (tile.getNum() == 0)
    out << "    ";
  else if(tile.getNum() < 10)
    out << "  " << tile.getNum() << " ";
  else
    out << " " << tile.getNum() << " ";
  return out;
}