#include <iostream>
#include <cassert>
#include "headers/board.h"

std::ostream& operator<<(std::ostream& out, const Board& board)
{
  for(std::size_t i{0}; i < static_cast<std::size_t>(g_consoleLines); ++i)
    std::cout << '\n';

  for(std::size_t i{0}; i < static_cast<std::size_t>(board.N*board.N); ++i){
    if (!(i % 4))
      out << '\n';
    out << board.m_tiles[i];
  }
  out << '\n';
  return out;
}

bool operator==(const Board& b1, const Board& b2)
{
  for (std::size_t i{0}; i < b1.N*b1.N; ++i){
    if (b1.m_tiles[i].getNum() != b2.m_tiles[i].getNum()){
      return false;
    }
  }
  
  return true;
}

Point Board::findEmptyTile()
{
  for(std::size_t i{0}; i < N * N; ++i)
  {
    if (m_tiles[i].getNum() == 0)
      return Point{static_cast<int>(i) / N, static_cast<int>(i) % N}; 
  }
  assert(false && "Board::findEmptyTile: No tile found, board is invalid");
}

void Board::randomize(int iterations)
{
  for(int i{0}; i < iterations; ++i)
    moveTile(Direction{static_cast<Direction::Type>(Random::get(0, Direction::maxTypeLen - 1))});
}

void Board::moveTile(const Direction& direction)
{
  Point point = this->findEmptyTile();
  Point to_move = point.getAdjacentPoint(-direction);
  if(!(this->validMove(to_move))) return;

  m_tiles[this->index(point)] = m_tiles[this->index(to_move)];
  m_tiles[this->index(to_move)] = Tile {0};
}


char UserInput::getUserInput()
{
  char input{};
  while (true)
  {
    std::cin >> input;
    if(!std::cin)
    {
      if(std::cin.eof()){
        std::exit(0);
      }
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (input == 'w' || input == 'a' || input == 's' || input == 'd' || input == 'q')
      break;
  }
  return input;
}

Direction UserInput::convertInput(const char input)
{
  switch(input)
  {
  case 'w': return Direction{Direction::up};
  case 'a': return Direction{Direction::left};
  case 's': return Direction{Direction::down};
  case 'd': return Direction{Direction::right};
  }
  assert(false && "convertInput: invalid key");
}
