#include "HeaderFiles/Game.hpp"

// Game constructor, initialising memeber variables
Game::Game(std::shared_ptr<PlayerController> player1, std::shared_ptr<PlayerController> player2) 
    : players{player1, player2} 
{ 
    this->categories = {"Ones", "Twos", "Threes", "Fours", "Fives", "Sixes", "Three of a kind", "Four of a kind", "Full House", "Small Straight", "Large Straight", "YAHTZEE", "Chance"};
    this->initialiseGameState();
}


void Game::initialiseGameState()
{
    for (auto player : players)
    {
        for (int i = 0; i < 13; i++)
        {
            this->currentGameState.scores[player->playerName][this->categories.at(i)];
        }
    }
}


std::vector<int> Game::getTotalScores()
{
    std::vector<int> playerScoresSum = {0, 0};
    int i = 0;
    for (auto& [playerNames, playerScores] : currentGameState.scores)
    {
        for (auto& [cateogry, scores] : playerScores)
        {
            playerScoresSum[i] = playerScoresSum[i] + scores.score;
        }
        i++;
    }
    return playerScoresSum;
}

void Game::printGameState()
{
    // Print the header of the table
    std::cout << std::left <<std::setw(20) << "Category";

    for (auto& [playerName, _]: currentGameState.scores)
    {
        std::cout << std::right << std::setw(10) << playerName;
    }
    std::cout << "\n" << std::string(20 + currentGameState.scores.size() * 10, '-') << std::endl;

    // Print the contents of the table
    for (std::string category : categories)
    {
        std::cout << std::left << std::setw(20) << category;

        for (auto& [playerName, playerScores] : currentGameState.scores)
        {
            std::cout << std::right << std::setw(10) << playerScores[category].score;
        }
        std::cout << "\n";
    }
    std::cout << std::string(20 + currentGameState.scores.size() * 10, '-') << std::endl;

    std::vector<int> totalScores = this->getTotalScores();
    std::cout << std::left << "Total" << std::right << std::setw(25) << totalScores.at(0) << std::right << std::setw(10) << totalScores.at(1) << std::endl;

    
}