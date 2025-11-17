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

        bool isCategoryNotUsed = this->currentGameState.scores[this->players[this->currentPlayerIndex]->playerName][toDoAction.category].used == false;
        this->applyAction(toDoAction);

        if (toDoAction.type == ActionType::ChooseCategory && isCategoryNotUsed)
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
            int score = this->computeScore(toDoAction.category);
            this->currentGameState.scores[this->players[this->currentPlayerIndex]->playerName][toDoAction.category] = {score, true};
            break;

    }
}



int Game::computeScore(std::string categoryToCompute)
{
    std::vector<int> counts = this->countDice();
    if (categoryToCompute == this->categories[0]) return counts.at(1);
    else if (categoryToCompute == this->categories[1]) return counts.at(2);
    else if (categoryToCompute == this->categories[2]) return counts.at(3);
    else if (categoryToCompute == this->categories[3]) return counts.at(4);
    else if (categoryToCompute == this->categories[4]) return counts.at(5);
    else if (categoryToCompute == this->categories[5]) return counts.at(6);
    else if (categoryToCompute == this->categories[6]) return counts.at(2);
    else if (categoryToCompute == this->categories[6]) return this->hasNOfAKind(3) ? sumDice() : 0;
    else if (categoryToCompute == this->categories[7]) return this->hasNOfAKind(4) ? sumDice() : 0;
    else if (categoryToCompute == this->categories[8]) return this->hasFullHouse() ? 25 : 0;
    else if (categoryToCompute == this->categories[9]) return this->hasSmallStraight() ? 30 : 0;
    else if (categoryToCompute == this->categories[10]) return this->hasLargeStraight() ? 40 : 0;
    else if (categoryToCompute == this->categories[11]) return this->hasNOfAKind(5) ? 50 : 0;
    else if (categoryToCompute == this->categories[12]) return this->sumDice(); 
    else return 0;
}

int Game::sumDice()
{
    int sum = 0;
    for (int die : this->currentGameState.dice)
    {
        sum += die;
    }
    return sum;
}

bool Game::hasLargeStraight()
{
    std::set<int> orderedDice(this->currentGameState.dice.begin(), this->currentGameState.dice.end());
    
    if (orderedDice.size() != 5) return false;

    std::vector<int> dice(orderedDice.begin(), orderedDice.end());

    return (dice.back() - dice.front() == 4);
}

bool Game::hasSmallStraight()
{
    std::set<int> orderedDice(this->currentGameState.dice.begin(), this->currentGameState.dice.end());
    std::vector<int> dice(orderedDice.begin(), orderedDice.end());
    
    if (dice.size() < 4) return false;

    for (int i = 0; i+3 < dice.size(); i++)
    {
        if (dice.back() - dice.front() == 3) return true;
    }

    return false;
}

bool Game::hasFullHouse()
{
    bool has3 = false;
    bool has2 = false;

    for (int i = 1; i < 7; i++)
    {
        if (this->currentGameState.dice[i] == 2) has2 = true;
        if (this->currentGameState.dice[i] == 3) has3 = true;
    }

    return has2 & has3;
}

bool Game::hasNOfAKind(int n)
{
    for (int i = 1; i < 7; i++)
    {
        if (this->currentGameState.dice[i] == 3) return true;
    }
    return false;
}

std::vector<int> Game::countDice()
{
    std::vector<int> counts = {0, 0, 0, 0, 0, 0, 0};

    for(int die : this->currentGameState.dice)
    {
        counts[die] ++;
    }

    return counts;
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