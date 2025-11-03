/*
    GameState.hpp

    The game state is defined as a map between player and their score board
    Also keeps track of the number of rolls left
*/

#ifndef GameState_hpp
#define GameState_hpp

#include <vector>
#include <map>

// Each category must have a score associated with it 
// and whether it has been played or not
struct CategoryData
{
    int score = 0;
    int used = false;
};

struct GameState
{
    std::vector<int> dice;
    // Score board mapping done in this way
    // [PlayerName][Category] -> CategoryData (score, used)
    std::map< std::string, std::map< std::string, CategoryData > > scores;
    int rollsLeft = 3;
};

#endif