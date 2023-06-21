#include "include/state.h"

std::string name(action move)
{
    switch (move) {
        case UP:
            return "UP";
            break;
        case DOWN:
            return "DOWN";
            break;
        case LEFT:
            return "LEFT";
            break;
        case RIGHT:
            return "RIGHT";
            break;
        case NONE:
            return "NONE";
            break;
    }
}

action reverse(action move) 
{
    switch (move) {
        case UP:
            return DOWN;
            break;
        case DOWN:
            return UP;
            break;
        case LEFT:
            return RIGHT;
            break;
        case RIGHT:
            return LEFT;
            break;
        case NONE:
            return NONE;
            break;
    }
}

std::vector<State> State::expand(){
    std::vector<State> newStates;
    for(int i = UP; i != NONE;  i ++) {
        if(i != reverse(this->lastAction) && isPossibleMove((action) i))
        {
            newStates.push_back(nextState((action)i));
        }
    }

    return newStates;
}

State::State(std::string newGame) {
    this->game = newGame;
    this->cursor = this->game.find('0');
    this->heuristic = this->manhattan();
    this->lastAction = NONE;
    this->pathCost = 0;
    this->parent = NULL;
}

State::State(std::string newGame, int cursorPosition, action newAction, long pathCost, State* parent)
{
    this->game = newGame;
    this->cursor = cursorPosition;
    this->pathCost = pathCost;
    this->parent = parent;
    this->lastAction = newAction;
    this->heuristic = this->manhattan();
}

bool State::isPossibleMove(action move)
{
    int gameSize = game.size();
    int sideSize = sqrt(gameSize);

    switch (move) {
        case UP:
            return cursor > sideSize - 1;
            break;
        case DOWN:
            return cursor <  gameSize - sideSize;
            break;
        case LEFT:
            return cursor % sideSize != 0;
            break;
        case RIGHT:
            return cursor % sideSize != sideSize - 1;
            break;
        case NONE:
            return false;
            break;
    }
}

State State::nextState(action move)
{
    std::string newGame = game;
    int sideSize = sqrt(game.size());
    switch (move) {
        case UP:
            std::swap(newGame[cursor], newGame[cursor - sideSize]);
            return State(newGame, cursor - sideSize,  UP, this->pathCost + 1, this);
            break;
        case DOWN:
            std::swap(newGame[cursor], newGame[cursor + sideSize]);
            return State(newGame, cursor + sideSize, DOWN, this->pathCost + 1, this);
            break;
        case LEFT:
            std::swap(newGame[cursor], newGame[cursor - 1]);
            return State(newGame, cursor - 1, LEFT, this->pathCost + 1, this);
            break;
        case RIGHT:
            std::swap(newGame[cursor], newGame[cursor + 1]);
            return State(newGame, cursor + 1, RIGHT, this->pathCost + 1, this);
            break;
        case NONE:
            return State(newGame);
            break;
    }
}

int State::manhattan()
{
    int score = 0;
    std::string objective = "012345678";

    if(this->game.size() == 15)
        objective = "012345679ABCDEF";

    int sideSize  = sqrt(this->game.size());

    for(int i = 0; i < objective.size(); i ++)
    {
        int pos = this->game.find(objective[i]);
        std::cout << objective [i] << ", " <<  pos << std::endl;
        score += abs(std::floor((int)pos/sideSize) - std::floor((int) i/sideSize));
        score += abs((int)pos%sideSize - (int) i%sideSize);
    }

    return score;
}

bool State::operator== (const State &secondState)
{
    return this->game == secondState.game;
}

void State::print() {
    std::cout << "Game: "; 
    for (int i = 0; i < game.size(); i ++)
    {
        if(i % 3 == 0)
            std::cout << std::endl;

        std::cout << this->game[i];
    }
    std::cout << std::endl;
    std::cout << "Cursor Position: " << this->cursor << std::endl;
    std::cout << "Last Action: " << name(this->lastAction) << std::endl;
    std::cout << "Heuristic: " << this->heuristic << std::endl;
    std::cout << "Cost: " << this->pathCost << std::endl << std::endl;
}



