#include <iostream>
#include <limits>
#include <vector>
#include "Session.h"

int Session::getLivesLeft() const
{
  return m_lives_left;  
}

int Session::getCorrectGuesses() const
{
  return m_correct_guesses;
}

void Session::displayGame() const
{
  std::cout << "Welcome to C++ man (a variant of Hangman)\n";
  std::cout << "To win: guess the word.  To lose: run out of pluses.\n";
  std::cout << "\n";
}

char Session::getUserInput() const
{
  while (true)
  {
    std::cout << "The word: ";
    for (const auto& i : m_blank_word)
      std::cout << i;

    std::cout << "\tWrong guesses: ";
    for (const auto& i : m_lives)
      std::cout << i;
    std::cout << "\n";

    std::cout << "Enter your next letter: ";
    char input{};
    std::cin >> input;
    if (!std::cin)
    {
      if (std::cin.eof())
      {
        std::exit(0);
      }
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cin.clear();
      continue;
    }  
    
    if (static_cast<int>(input) < 97 || static_cast<int>(input) > 122)
    {
      std::cout << "That was not a valid input. Try again\n";
      continue;
    }
    else
      std::cout << "You entered: " << input << "\n\n";  
      return input; 
  }
}

Session::GuessType Session::checkUserGuess(char guess) const
{
  for (const auto&ch : m_blank_word)
  {
    if (ch == guess)
      return guessed;
  }
  
  for (const auto& ch : m_lives)
  {
    if (ch == guess)
      return guessed;
  }

  for (const auto& ch : m_word)
  {
    if (ch == guess)
      return correct;
  }
  
  return incorrect;
}

std::vector<std::size_t> Session::getCorrectIndices(char guess) const
{
  std::vector<std::size_t> indices{};
  for (std::size_t i{0}; i < m_word.size(); ++i)
  {
    if (m_word[i] == guess)
    {
      indices.push_back(i);
    }
  }
  
  return indices;
}

void Session::updateGuesses(const std::vector<std::size_t>& indices, char guess)
{
  for(const auto& index : indices)
  {
    m_correct_guesses++;
    m_blank_word[index] = guess;
  }
}

void Session::updateLives(char guess)
{
  if(m_lives_left >= 0)
  {
    m_lives[m_lives_left] = guess;
    m_lives_left--;
  }
}

