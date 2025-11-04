/*

*/

#ifndef HumanPlayer_hpp
#define HumanPlayer_hpp

#include "PlayerController.hpp"
#include <iostream>

class HumanPlayer : public PlayerController
{
    public:
        HumanPlayer(const std::string& name);
        Action chooseAction(const GameState& state) override;
};



#endif