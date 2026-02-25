// Mohammed Al-Sheikh
// Game.cpp

#include <iostream>
#include <vector>
#include "Game.h"

// Default Constructor
Game::Game()
: choices { 1, 2, 3, 4, 5, 6, 7, 8, 9 }, playerOnePicks {}, playerTwoPicks {}, isPlayerOnesTurn(true)
{
    // Nothing Here
}

// Tests if the vector parameter has won the game and returns truth value
bool Game::IsWinner(const std::vector<int>& PICKS) const
{
    if(PICKS.size() < 3)
    {
        return false;
    }

    for(int i = 0; i < PICKS.size(); i++)
    {
        for(int j = i + 1; j < PICKS.size(); j++)
        {
            for(int k = j + 1; k < PICKS.size(); k++)
            {
                if(PICKS[i] + PICKS[j] + PICKS[k] == 15)
                    return true;
            }
        }
    }
    
    return false;
}

// Tests if the game is over if either player won or there are no choices remaining, and returns truth value
bool Game::IsGameOver() const
{
    if(IsWinner(playerOnePicks))
    {
        return true;
    }
    else if(IsWinner(playerTwoPicks))
    {
        return true;
    }
    else if(choices.size() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Checks game status: -1 if game is still active, 1 if player one won, 2 if player two won, 0 if draw
int Game::GetGameStatus() const
{
    if(!IsGameOver())
    {
        return -1;
    }
    else if(IsWinner(playerOnePicks))
    {
        return 1;
    }
    else if(IsWinner(playerTwoPicks))
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

// Prints display of choices remaining, player one selections, player two selections
std::ostream& operator <<(std::ostream& ostr, const Game& rhs)
{
    ostr << "Choices Remaining:     ";
    
    for(int x : rhs.choices)
    {
        ostr << x << "  ";
    }
    
    ostr << std::endl << "Player One's Choices:  ";
    
    for(int y : rhs.playerOnePicks)
    {
        ostr << y << "  ";
    }
    
    ostr << std::endl << "Player Two's Choices:  ";
    
    for(int z : rhs.playerTwoPicks)
    {
        ostr << z << "  ";
    }
        
    return ostr;
}

// Check if game is over. If not, allow player with turn to make a valid selection from remaining choices
void Game::MakePick()
{
    if(IsGameOver())
    {
        std::cout << "GAME IS OVER...  NO MORE PICKS TO MAKE!" << std::endl << std::endl;
        return;
    }
    
    std::cout << *this << std::endl;

    int choice;
    bool validPick = false;

    while(validPick == false)
    {
        if(isPlayerOnesTurn)
        {
            std::cout << "Player One's Pick?     ";
        }
        else
        {
            std::cout << "Player Two's Pick?     ";
        }

        std::cin >> choice;
        std::cout << std::endl;

        for(int i = 0; i < choices.size(); i++)
        {
            if(choices[i] == choice)
            {
                choices.erase(choices.begin() + i);
                validPick = true;
                break;
            }
        }
    }

    if(isPlayerOnesTurn)
    {
        playerOnePicks.push_back(choice);
    }
    else
    {
        playerTwoPicks.push_back(choice);
    }

    isPlayerOnesTurn = !isPlayerOnesTurn;
}
