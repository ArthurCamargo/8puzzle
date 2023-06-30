#include "include/algorithm.h"
#include <iostream>

Solution Bfs::solve(Instance currentInstance) {
    Solution s;
    std::vector<State> newStates;
    State actualState;
    this->open.push(currentInstance.initialState);

    if (currentInstance.initialState == currentInstance.finalState) {
        s.numExpanded = currentInstance.statesExpanded;
        s.optimalSolutionLength = 0;
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
                    s.numExpanded = currentInstance.statesExpanded;
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
    // TODO: Fix the problems with the reopening
    // Problem reopening
    Solution s;
    std::vector<State> newStates;
    State actualState;
    this->open.push(currentInstance.initialState);
    currentInstance.statesExpanded++;

    while (!this->open.empty()) {

        actualState = this->open.top();
        //actualState.print();
        this->open.pop();

        if(distances.count(actualState.game) == 0)
        {
            distances[actualState.game] = actualState.pathCost;

            if (actualState == currentInstance.finalState) {
                // TODO: Create a function to copy the solution
                // Create the time and meanheuristic value for this
                s.numExpanded = currentInstance.statesExpanded;
                s.optimalSolutionLength = actualState.pathCost;
                return s;
            }

            newStates = actualState.expand();
            currentInstance.statesExpanded ++;
            for (State expandedState : newStates) {
                open.push(expandedState);
            }
        }
    }
    std::cout << "There is no solution" << std::endl << std::endl;
    return s;
};
