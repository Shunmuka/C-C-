#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <limits>
#include "tile.h"
#include "direction.h"
#include "point.h"

constexpr inline int g_consoleLines{ 25 };

class Board
{
public:
  Board() : m_tiles{std::vector<Tile>(N*N)} {
    for(std::size_t i{0}; i < N*N; ++i){
      if (i == (N*N) - 1)
        m_tiles[i] = Tile{0};
      else
        m_tiles[i] = Tile{static_cast<int>(i) + 1};
    }
  }
 
  
  friend std::ostream& operator<<(std::ostream& out, const Board& board);
  friend bool operator==(const Board& b1, const Board& b2);
  void randomize(int iterations);
  int index(const Point& point) { return point.x() * N + point.y(); }
  bool validMove(const Point& p) const { return (0 <= p.x() && p.x() < N) && (0 <= p.y() && p.y() < N); }
  Point findEmptyTile();
  void moveTile(const Direction& direction);
  bool static playerWon(const Board& board){
    return Board {} == board;
  }


private:
  static constexpr int N {4};
  std::vector<Tile> m_tiles{};
};

namespace UserInput
{
  char getUserInput();
  Direction convertInput(const char input);
};

#endif