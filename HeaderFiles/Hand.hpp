/*
    Hand.hpp

    Represents a conceptual current hand made up of 5 dice

    The dice can be locked so that those values are kept and the 'unlocked' dice are rolled

    This object will expect ordinal values regarding position of dice (1st, 2nd, etc) to come in as (1, 2, etc)
    As the functions operating on these values will execute a shift (-1) to convert these to coresponding index locations 
*/ 


#ifndef Hand_hpp
#define Hand_hpp

#include "Dice.hpp"

class Hand
{
    private:
        // Keep track of the dice rolls
        int playerHand[5];
        // Keep track of which dice are locked
        bool lockedDice[5];

        // Unniversal die that will be rolled everytime we roll a die somewhere
        // Each roll is independent so no need for 5 separate dice
        Dice dice;

        // To set each dice value to 0 before each player turn
        void reset();

    public:
        // Initialises the hand 
        Hand();

        // Rolls dice based on which ones are unlocked
        void rollDice();
        // Takes a vector of positions to lock and locks thems
        void lockHand(std::vector<int> positionsToLock);

        // Print the current hand
        void printHand();
};


#endif