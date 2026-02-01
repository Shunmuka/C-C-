#include <iostream>
#include <vector>
#include <string> 
#include <string_view>
#include <limits>
#include "random.h"
#include "Session.h"

namespace WordList
{
  const std::vector<std::string_view> m_words{"mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage"};

  const std::string_view getRandomWord()
  {
    return m_words[Random::get(0, static_cast<int>(m_words.size() - 1))];
  }
};





int main()
{
  std::string random_word {WordList::getRandomWord()};
  Session session {random_word};
  session.displayGame();

  while (true)
  {
    if (session.getLivesLeft() < 0)
    {
      std::cout << "You lost! The correct word was: " << random_word;
      break;
    }
    
    if (session.getCorrectGuesses() == random_word.size()){
      std::cout << "You Win! The word was: " << random_word;
      break;
    }

    char input{session.getUserInput()};
    std::vector<std::size_t> indices{};
    Session::GuessType guess {session.checkUserGuess(input)};
    if (guess == Session::correct)
      {
        indices = session.getCorrectIndices(input);
        session.updateGuesses(indices, input);
      }
    else if (guess == Session::guessed)
      std::cout << "You already guessed that. Try Again.\n"; 
    else
      session.updateLives(input); 
  }

    
  return 0;
}