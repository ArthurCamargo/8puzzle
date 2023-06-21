#include "include/algorithm.h"

Solution Bfs::solve(Instance currentInstance) {
    Solution s;
    std::vector<State> newStates;
    State actualState;
    this->open.push(currentInstance.initialState);

    if(currentInstance.initialState == currentInstance.finalState)
    {
        s.numExpanded = currentInstance.statesExpanded;
        return s;
    }


    while(true) {
        if(this->open.empty())
        {
            std::cout << "There is no solution" << std::endl;
            return s;
        }

        actualState = this->open.front();
        actualState.print();
        this->open.pop();


        if(std::find(this->explored.begin(), this->explored.end(), actualState) == this->explored.end())
        {
            this->explored.push_back(actualState);
            currentInstance.statesExpanded ++;
            newStates = actualState.expand();
            for (State expandedState : newStates)
            {
                if(expandedState == currentInstance.finalState)
                {
                    s.numExpanded = currentInstance.statesExpanded;
                    return s;
                }

                this->open.push(expandedState);
            }
        }
    }
    return s;
};


bool aStarCompare(State state1 , State state2) {
     int state1Cost = state1.heuristic + state1.pathCost;
     int state2Cost = state2.heuristic + state2.pathCost;

     if(state1Cost == state2Cost)
     {
             return state1.heuristic > state2.heuristic;
     }
     return state1Cost > state2Cost;
}



Solution Astar::solve(Instance currentInstance) {
    Solution s;
    std::vector<State> newStates;
    State actualState;
    this->open.push(currentInstance.initialState);

    s.initialHeuristicValue = currentInstance.initialState.heuristic;
    if(currentInstance.initialState == currentInstance.finalState)
    {
        s.numExpanded = currentInstance.statesExpanded;
        return s;
    }


    while(true) {
        if(this->open.empty())
        {
            std::cout << "There is no solution" << std::endl;
            return s;
        }

        actualState = this->open.top();
        actualState.print();
        this->open.pop();


        if(std::find(this->explored.begin(), this->explored.end(), actualState) == this->explored.end())
        {
            this->explored.push_back(actualState);
            currentInstance.statesExpanded ++;
            newStates = actualState.expand();
            for (State expandedState : newStates)
            {
                if(expandedState == currentInstance.finalState)
                {
                    s.numExpanded = currentInstance.statesExpanded;
                    return s;
                }

                this->open.push(expandedState);
            }
        }
    }
    return s;
};






