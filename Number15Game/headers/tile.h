#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile
{
public:
  Tile() = default;
  explicit Tile(int num) : m_num{num} {}
  bool isEmpty() const { return m_num == 0; }
  int getNum() const { return m_num; }

private:
  int m_num{};
};

std::ostream& operator<<(std::ostream& out, const Tile& tile);

#endif