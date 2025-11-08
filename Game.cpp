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
    this->currentGameState.dice = std::vector<int>(5, 0);

    this->currentPlayerIndex = 0;
}

void Game::resetGameState()
{
    this->currentGameState.rollsLeft = 3;

    this->currentGameState.dice = std::vector<int>(5, 0);
}


void Game::startGame()
{
    for (int roundNumber; roundNumber < 26; roundNumber++)
    {
        this->playTurn();
        // To swap the player
        this->currentPlayerIndex = 1 - this->currentPlayerIndex;
    }
}

void Game::playTurn()
{
    auto currentPlayer = players[this->currentPlayerIndex];
    this->resetGameState();
    
    bool turnOver = false;
    while (!turnOver)
    {
        Action toDoAction = currentPlayer->chooseAction(this->currentGameState);

        this->applyAction(toDoAction);
        if (toDoAction.type == ActionType::ChooseCategory)
        {
            turnOver = true;
        }
    }
}

void Game::applyAction(Action& toDoAction)
{
    switch (toDoAction.type)
    {
    case ActionType::RollDice:
        this->rollDice({});
        break;
    case ActionType::HoldDice:
        this->rollDice(toDoAction.diceToRoll);
        break;
    case ActionType::ChooseCategory:

        break;
    default:
        break;
    }
}


void Game::rollDice(std::vector<int> holdIndices)
{

    for (int index : holdIndices)
    {
        int diceRoll = rand() % 6 + 1;
        this->currentGameState.dice[index - 1] = diceRoll;
    }
    
}

// Utility function to get the total scores of players in a vector {player1, player2}
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

void Game::printCurrentHand()
{
    std::cout << "\nCurrent Hand:\n\t";
    for (int i = 0; i < 5; i++)
    {
        std::cout << this->currentGameState.dice[i] << " ";
    }
    std::cout << "\n";
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