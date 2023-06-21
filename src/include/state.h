#pragma once

#include <iostream>
#include <valarray>
#include <math.h>
#include <vector>
#include <string>

typedef enum action {
    UP,
    LEFT,
    RIGHT,
    DOWN,
    NONE,
        
}action;


class State {
    public:
        long pathCost;
        long costH;
        action lastAction;
        int cursor;
        State* parent;
        int heuristic;

        std::string game;

        State(std::string newGame);
        State(std::string newGame, int cursorPosition, action newAction, long pathCost, State* parent);

        bool isPossibleMove(action move);
        State nextState(action move);

        int manhattan();

        int hash() const;
        bool operator== (const State &secondState);
        bool operator< (const State &secondState) const
        {
            return this->hash() < secondState.hash();
        }

        void print();
        std::vector<State> expand();

        State() = default;
        ~State() = default;
};


