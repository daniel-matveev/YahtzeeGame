#include "HeaderFiles/Dice.hpp"

Dice::Dice()
{
    
}

// Returns a uniformly distributed random number between 1 and 6 inclusive
int Dice::roll()
{
    return 1 + (rand() % 6);
}