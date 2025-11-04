#include "HeaderFiles/Game.hpp"
#include "HeaderFiles/HumanPlayer.hpp"

int main()
{
    auto p1 = std::make_shared<HumanPlayer>("Player 1");
    auto p2 = std::make_shared<HumanPlayer>("Player 2");
    Game mainGame(p1, p2);

    return 0;
}