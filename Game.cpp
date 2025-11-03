#include "HeaderFiles/Game.hpp"

// Game constructor, initialising memeber variables
Game::Game(std::shared_ptr<PlayerController> player1, std::shared_ptr<PlayerController> player2) 
    : players{player1, player2} { }