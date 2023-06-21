#pragma once

#include <iostream>
#include <string>


class Solution {
    public:
        int numExpanded;
        int optimalSolutionLength;
        long meanHeuristicValue;
        long initialHeuristicValue;
        long time;

        Solution() = default;

        Solution(int newNumExpanded, int newOptimalSolutionLength, long newMeanHeuristicValue, long newTime)
        {
            this->numExpanded = newNumExpanded;
            this->optimalSolutionLength = newOptimalSolutionLength;
            this->meanHeuristicValue = newMeanHeuristicValue;
            this->time = 0;
        }

        void print() const {
            std::cout << this->numExpanded << ",";
            std::cout << this->optimalSolutionLength << ",";
            std::cout << this->meanHeuristicValue << ",";
            std::cout << this->initialHeuristicValue << std::endl;
        }
};
