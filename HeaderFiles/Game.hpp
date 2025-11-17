/*
    Game.hpp

    "Controller" for the GameState.
*/
#ifndef Game_hpp
#define Game_hpp

#include <iostream>
#include <iomanip>
#include <set>

#include "GameState.hpp"
#include "PlayerController.hpp"



class Game
{
    private:
        // Stores the players
        std::vector< std::shared_ptr< PlayerController > > players;
        
        GameState currentGameState;
        std::vector<std::string> categories;

        std::vector<int> getTotalScores();

        int currentPlayerIndex;
        void initialiseGameState();
        void resetGameState();

        void playTurn();

        void applyAction(Action& toDoAction);

        bool hasLargeStraight();
        bool hasSmallStraight();
        bool hasNOfAKind(int n);
        bool hasFullHouse();

        int sumDice();
        std::vector<int> countDice();
        void rollDice(std::vector<int> rollIndices);
    public:
        // Constructor taking in the two players
        Game(std::shared_ptr< PlayerController > player1, std::shared_ptr< PlayerController > player2);
        
        int computeScore(std::string category);

        void printCurrentHand();
        void printGameState();

        void startGame();

};

#endif