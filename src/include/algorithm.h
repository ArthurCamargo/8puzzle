#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <functional>

#include "problem.h"
#include "solution.h"

typedef enum algorithmEnum{
    BFS,
    IDFS,
    ASTAR,
    IDASTAR,
    GBFS,
}algorithmEnum;

class Algorithm {
    public:
        std::string name;
        int numberExpansions;
        long meanHeuristicValue;
        std::unordered_set<long long int> explored;

         virtual ~Algorithm() = default;
};

class Bfs : Algorithm {
    public:
        std::queue<State> open;

        Bfs() {
            open = std::queue<State>();
            Algorithm::name = "BFS";
            Algorithm::numberExpansions = 0;
            Algorithm::meanHeuristicValue = 0;
        };


        Solution solve(Instance currentInstance);
};

typedef bool (*comp)(State, State);

bool aStarCompare(State state1 , State state2);

class Astar: Algorithm {
    public:
        std::priority_queue<State, std::vector<State>, comp> open;

        Astar() : open(aStarCompare) {
            Algorithm::name = "Astar";
            Algorithm::numberExpansions = 0;
            Algorithm::meanHeuristicValue = 0;
        };

        Solution solve(Instance currentInstance);
};



