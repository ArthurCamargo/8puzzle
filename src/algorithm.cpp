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
