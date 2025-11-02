/*
    Action.hpp
*/

#ifndef Action_hpp
#define Action_hpp

#include <vector>
#include <string>

enum class ActionType 
{
    RollDice,
    HoldDice,
    ChooseCategory
};

struct Action 
{
    ActionType type;
    std::vector<int> playerHand;
    std::string category;

};

#endif