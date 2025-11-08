/*
    Action.hpp

    Enum definition of what actions are available to the player


*/

#ifndef Action_hpp
#define Action_hpp

#include <vector>
#include <string>

// During each turn the player has 3 actions they can take
enum class ActionType 
{
    RollDice,
    HoldDice,
    ChooseCategory
};

// Each action is performed on a current hand and against a category if "ActionType = ChooseCategory"
struct Action 
{
    ActionType type;
    std::vector<int> diceToRoll;
    std::string category;
};

#endif