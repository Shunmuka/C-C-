#include <iostream>
#include <random>
#include <chrono>
#include <string_view>
#include <string>

namespace Random{
	inline std::mt19937 generate() {
		std::random_device rd{};
		
		std::seed_seq ss{ static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()), rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ss};
	}

	inline std::mt19937 mt{generate()};

	inline int get(int min, int max){
		return std::uniform_int_distribution{min, max}(mt);
	}
}

int getUserGuess(int i){
	std::cout << "\nGuess #" << i << ": ";
	int input{};
	std::cin>>input;
	
	return input;
}

char getUserOption(){
	std::cout << "\nWould you like to play again (y/n)?";
	char c{};
	std::cin >> c;
	return c;
}



int main() {
	while(true){
		//Initialize the target value
		const int target{Random::get(1, 100)};
		std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.";
		bool win{false};
		for (int i{1}; i <= 7; ++i){
			int guess{getUserGuess(i)};

			if (guess > target)
				std::cout << "Your guess is too high.\n";
			else if (guess < target)
				std::cout << "Your guess is too low.\n";
			else
			{
				std::cout << "Correct! You win!\n";
				win = true;
				break;
			}
		}

		if (!win)
			std::cout << "Sorry, you lose. The correct number was " << target << ".\n";

		char c{};
		do 
		{
			c = getUserOption();
		}
		while ((c != 'y') && (c != 'n'));

		if (c == 'n')
			break;	

	}
	std::cout << "Thank you for playing!" << std::endl;

	return 0;
}


