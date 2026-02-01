#include <string>
#include <vector>
#include <string_view>

class Session
{
  public:
    enum GuessType
    {
      correct,
      incorrect,
      guessed,
    };
    
    Session(std::string_view word) : m_word{word}, m_blank_word(static_cast<int>(word.size()), '_'), m_lives(6, '+'), m_lives_left{5}, m_correct_guesses{0}{}
    int getCorrectGuesses() const;
    int getLivesLeft() const;
    void displayGame() const;
    char getUserInput() const;
    GuessType checkUserGuess(char guess) const;
    std::vector<std::size_t> getCorrectIndices(char guess) const;
    void updateGuesses(const std::vector<std::size_t>& indices, char guess);
    void updateLives(char guess);
    

  private:
    const std::string m_word{};
    std::vector<char> m_blank_word{};
    std::vector<char> m_lives{};
    int m_lives_left{};
    int m_correct_guesses{};
};
