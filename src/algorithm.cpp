#include "include/algorithm.h"
#include <codecvt>
#include <cstdint>
#include <iostream>
#include <string>

Solution Bfs::solve(Instance currentInstance) {
    Solution s;
    std::vector<State> newStates;
    State actualState;
    State initialState = currentInstance.initialState;
    s.initialHeuristicValue = initialState.heuristic;
    this->open.push(initialState);

    if (initialState == currentInstance.finalState) {
        s.time = this->t.elapsed();
        s.numExpanded = 1;
        s.optimalSolutionLength = 0;
        s.meanHeuristicValue = State::sumValues / (float)State::count;
        return s;
    }

    while (true) {
        if (this->open.empty()) {
            std::cout << "There is no solution" << std::endl;
            return s;
        }

        actualState = this->open.front();
        // actualState.print();
        this->open.pop();
        long long int numberRepresentation = actualState.numberRepresentation();

        if (this->expanded.find(numberRepresentation) == this->expanded.end()) {
            this->expanded.insert(numberRepresentation);
            currentInstance.statesExpanded++;
            newStates = actualState.expand();
            for (State expandedState : newStates) {
                if (expandedState == currentInstance.finalState) {
                    s.time = this->t.elapsed();
                    s.numExpanded = currentInstance.statesExpanded;
                    s.meanHeuristicValue = State::sumValues / (float)State::count;
                    s.optimalSolutionLength = expandedState.pathCost;
                    return s;
                }
                this->open.push(expandedState);
            }
        }
    }
    return s;
};

bool aStarCompare(State state1, State state2) {
    int state1Cost = state1.heuristic + state1.pathCost;
    int state2Cost = state2.heuristic + state2.pathCost;

    if (state1Cost == state2Cost) {
        return state1.heuristic > state2.heuristic;
    }
    return state1Cost > state2Cost;
}

Solution Astar::solve(Instance currentInstance) {
    Solution s;
    std::vector<State> newStates;
    State actualState;
    this->open.push(currentInstance.initialState);
    currentInstance.statesExpanded++;

    while (!this->open.empty()) {

        actualState = this->open.top();
        //actualState.print();
        this->open.pop();

        if (distances.count(actualState.game) == 0) {
            distances[actualState.game] = actualState.pathCost;

            if (actualState == currentInstance.finalState) {
                s.time = this->t.elapsed();
                s.numExpanded = currentInstance.statesExpanded;
                s.optimalSolutionLength = actualState.pathCost;
                return s;
            }
            newStates = actualState.expand();
            currentInstance.statesExpanded++;
            for (State expandedState : newStates) {
                open.push(expandedState);
            }
        }
    }
    std::cout << "There is no solution" << std::endl << std::endl;
    return s;
};

Solution GBFS::solve(Instance currentInstance) {
    Solution s;
    std::vector<State> newStates;
    State actualState;
    this->open.push(currentInstance.initialState);
    currentInstance.statesExpanded++;

    while (!this->open.empty()) {

        actualState = this->open.top();
        //actualState.print();
        this->open.pop();

        if (distances.count(actualState.game) == 0) {
            distances[actualState.game] = actualState.pathCost;

            if (actualState == currentInstance.finalState) {
                s.time = this->t.elapsed();
                s.numExpanded = currentInstance.statesExpanded;
                s.optimalSolutionLength = actualState.pathCost;
                return s;
            }
            newStates = actualState.expand();
            currentInstance.statesExpanded++;
            for (State expandedState : newStates) {
                open.push(expandedState);
            }
        }
    }

    std::cout << "There is no solution" << std::endl << std::endl;
    return s;
};
