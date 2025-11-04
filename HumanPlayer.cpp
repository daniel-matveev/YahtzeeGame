#include "HeaderFiles/HumanPlayer.hpp"

HumanPlayer::HumanPlayer(const std::string& name)
{
    this->playerName = name;
}


Action HumanPlayer::chooseAction(const GameState& state)
{
    std::cout << "Hello from " << this->playerName << std::endl;
}