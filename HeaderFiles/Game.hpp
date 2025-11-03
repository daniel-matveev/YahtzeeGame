/*
    Game.hpp

    "Controller" for the GameState.
*/
#ifndef Game_hpp
#define Game_hpp

#include "GameState.hpp"
#include "PlayerController.hpp"



class Game
{
    private:
        // Stores the players
        std::vector< std::shared_ptr< PlayerController > > players;
        
    public:
        // Constructor taking in the two players
        Game(std::shared_ptr< PlayerController > player1, std::shared_ptr< PlayerController > player2);
        
};

#endif