
#include "HeaderFiles/Hand.hpp"

int main()
{
    // Set the seed to the current time
    srand(static_cast<unsigned>(time(NULL)));

    // Testing
    Hand hand1;

    hand1.printHand();

    hand1.rollDice();

    std::vector<int> lockedDice = {1, 3};

    hand1.lockHand(lockedDice);

    hand1.rollDice();
    hand1.printHand();

    hand1.rollDice();
    hand1.printHand();

    hand1.rollDice();
    hand1.printHand();

    return 0;
}