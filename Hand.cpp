#include "HeaderFiles/Hand.hpp"

// Sets the current hand to 0s 
// To get the hand ready for the next player
void Hand::reset()
{
    for (int i = 0; i < sizeof(this->playerHand)/sizeof(this->playerHand[0]); i++)
    {
        this->playerHand[i] = 0;
        this->lockedDice[i] = false;
    }
}

// Initialise the arrays 
Hand::Hand()
{
    reset();
}

// Roll each of the dice based on their locked state
void Hand::rollDice()
{
    for (int i = 0; i < sizeof(this->playerHand)/sizeof(this->playerHand[0]); i++)
    {
        if (this->lockedDice[i] == false)
        {
            this->playerHand[i] = dice.roll();
        }
    }
}

// Will negate the current state of the dice locked
// positionsToLock will have values 1 -> 6 representing the locations of dice
// Need index locations 0 -> 1 so need to do a -1 on all values
void Hand::lockHand(std::vector<int> positionsToLock)
{
    for (int i = 0; i < positionsToLock.size(); i++)
    {
        this->lockedDice[positionsToLock.at(i) - 1] = !this->lockedDice[positionsToLock.at(i) - 1];
    }
}

// To print the current hand
void Hand::printHand()
{
    std::cout << "Current Hand: ";

    for (int i = 0; i < sizeof(this->playerHand)/sizeof(this->playerHand[0]); i++)
    {
        std::cout << this->playerHand[i] << "  ";
    }

    std::cout << std::endl;
}