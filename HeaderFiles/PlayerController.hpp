/*
    PlayerController.hpp

    Base class to inherit for different types of players

    The players will have the ability to take an action based on a reference of a game state
    The players cannot change the game state but must be passed to the Game object
*/


#ifndef PlayerControler_hpp
#define PlayerControler_hpp

#include "Action.hpp"
#include "GameState.hpp"

class PlayerController
{
public:
    virtual ~PlayerController() = default;
    // Function which must be overriden  
    virtual Action chooseAction(const GameState& state) = 0;
    std::string playerName;
};


#endif