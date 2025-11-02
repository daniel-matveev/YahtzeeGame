/*
    PlayerController.hpp
*/


#ifndef PlayerControler_hpp
#define PlayerControler_hpp

#include "Action.hpp"
#include "GameState.hpp"

class PlayerController
{
public:
    virtual ~PlayerController() = default;
    virtual Action chooseAction(const GameState& state) = 0;
    std::string playerName;
};


#endif