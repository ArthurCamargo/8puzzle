#pragma once

#include <iostream>
#include <string>


class Solution {
    public:
        int numExpanded;
        int optimalSolutionLength;
        long double meanHeuristicValue;
        long initialHeuristicValue;
        double time;

        Solution() = default;

        void print() const {
            std::cout << this->numExpanded << ",";
            std::cout << this->optimalSolutionLength << ",";
            std::cout << this->time << ",";
            std::cout << this->meanHeuristicValue << ",";
            std::cout << this->initialHeuristicValue << std::endl;
        }
};
