// Dice object that will be used to generate random numbers from 1-6 to simulate the roll of a dice

#ifndef Dice_hpp

#define Dice_hpp

#include <stdio.h>
#include <cstdlib>
#include <iostream>

class Dice
{
    public:
        Dice();
        
        int roll();
};


#endif