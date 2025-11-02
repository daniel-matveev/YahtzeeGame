/*
    GameState.hpp
*/

#ifndef GameState_hpp
#define GameState_hpp

#include <vector>
#include <map>

struct CategoryData
{
    int score = 0;
    int used = false;
};

struct GameState
{
    std::vector<int> dice;
    std::map< std::string, std::map< std::string, CategoryData > > scores;
    int rollsLeft = 3;
};

#endif