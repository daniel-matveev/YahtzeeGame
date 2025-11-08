#include "HeaderFiles/Game.hpp"
#include "HeaderFiles/HumanPlayer.hpp"

int main()
{
    srand(static_cast<unsigned int> (time(NULL)));
    auto p1 = std::make_shared<HumanPlayer>("Player 1");
    auto p2 = std::make_shared<HumanPlayer>("Player 2");
    Game mainGame(p1, p2);

    mainGame.printGameState();
    mainGame.printCurrentHand();
    return 0;
}