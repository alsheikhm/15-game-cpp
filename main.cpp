// Mohammed Al-Sheikh
// main.cpp

#include <iostream>
#include "Game.h"

int main()
{
	// Tests constructor
	Game game;

	// Tests game loop capabilities and output printing from within
	while (game.IsGameOver()== false)
		game.MakePick();
	
	// Tests output printing
	std::cout << game << std::endl;
	
	// Tests game status capabilities
	int result = game.GetGameStatus();
	if (result == 1)
		std::cout << "Player ONE has won the game!";
	else if (result == 2)
		std::cout << "Player TWO has won the game!";
	else if (result == 0)
		std::cout << "The game was a DRAW!";
	else
		std::cout << "ERROR!  How did we get here?!  The game is over but it's not over?!?!";
	
	std::cout << std::endl << std::endl;

	// Tests completed game status
	game.MakePick();

	return 0;
}
