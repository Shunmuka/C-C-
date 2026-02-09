#include <iostream>
#include "headers/tile.h"
#include "headers/board.h"
#include "headers/point.h"

// Your code goes here

// Note: save your main() from the prior step, as you'll need it again in the next step
int main()
{
    Board board{};
    board.randomize(1000);
    while (true)
    {
      std::cout << board;
      if (Board::playerWon(board)){
        std::cout << "\n\nYou Win!\n\n";
        break;
      }
      char input{UserInput::getUserInput()};
      if (input == 'q'){
        std::cout << "\n\nBye!\n\n";
        break;
      }
      board.moveTile(UserInput::convertInput(input));
    }
    return 0;
}