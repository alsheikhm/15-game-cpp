// Mohammed Al-Sheikh
// Game.h

#ifndef GAME_H
#define GAME_H

#include <ostream>
#include <vector>

class Game
{
public:
	// Set up the game to be ready for play
	Game();

	// Has someone won?  And if not, are there any choices 
	// left to make?
	bool IsGameOver() const;

	// 1 if player one has won, 2 if player two has won, 
	// 0 if a draw, and -1 if the game is still active
	int GetGameStatus() const;

	// Print choices left first, then player one's choices, 
	// then player two's choices
	friend std::ostream& operator <<(std::ostream& ostr, const Game& rhs);

	// If the game is already over over, let us know and do nothing.
	// Otherwise get the current player to choose a remaining choice
	// and then move it into their collection.
	void MakePick();

private:
	// Starts with choice 1, 2, 3, 4, 5, 6, 7, 8, 9
	std::vector<int> choices;

	// Starts empty
	std::vector<int> playerOnePicks;

	// Starts empty
	std::vector<int> playerTwoPicks;
	
	// Presume if it's not player one's turn, it's player two's turn
	bool isPlayerOnesTurn;

	// Has to be at least three picks to win
	// But do any three of the picks add up to 15?
	bool IsWinner(const std::vector<int>& PICKS) const;
};

#endif
