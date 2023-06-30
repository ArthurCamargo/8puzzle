#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <map>
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

         virtual ~Algorithm() = default;
};

class Bfs : Algorithm {
    public:
        std::queue<State> open;
        std::unordered_set<long long int> expanded;

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
        std::map<std::string, int> distances;

        Astar() : open(aStarCompare) {
            distances = std::map<std::string, int>();
            Algorithm::name = "Astar";
            Algorithm::numberExpansions = 0;
            Algorithm::meanHeuristicValue = 0;
        };

        Solution solve(Instance currentInstance);
};

class IDAstart: Algorithm {
    public:
        std::priority_queue<State, std::vector<State>, comp> open;

};
