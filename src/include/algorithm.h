#pragma once

#include <vector>
#include <string>
#include <chrono>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <functional>

#include "problem.h"
#include "solution.h"
#include "timer.h"

typedef enum algorithmEnum{
    BFS,
    IDFS,
    ASTAR,
    IDASTAR,
    GBFS,
}algorithmEnum;

class Algorithm {
    public:
        Timer t;
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
            Algorithm::t.reset();
        };


        Solution solve(Instance currentInstance);
};

typedef bool (*comp)(State, State);

bool aStarCompare(State state1 , State state2);

class Astar: Algorithm {
    public:
        std::priority_queue<State, std::vector<State>, comp> open;
        std::unordered_map<std::string, int> distances;

        Astar() : open(aStarCompare), distances() {
            distances = std::unordered_map<std::string, int>();
            Algorithm::name = "Astar";
            Algorithm::numberExpansions = 0;
            Algorithm::meanHeuristicValue = 0;
        };

        Solution solve(Instance currentInstance);
};

class IDAstar: Algorithm {
    public:
        std::priority_queue<State, std::vector<State>, comp> open;
        std::unordered_map<std::string, int> distances;
    
        IDAstar() : open(), distances() {
            distances = std::unordered_map<std::string, int>();
            Algorithm::name = "IDAstar";
            Algorithm::numberExpansions = 0;
            Algorithm::meanHeuristicValue = 0;

        };
        
        Solution solve(Instance currentInstance);
};


class GBFS: Algorithm {
    public:
        std::priority_queue<State, std::vector<State>, comp> open;
        std::unordered_map<std::string, int> distances;
    
        GBFS() : open(), distances() {
            distances = std::unordered_map<std::string, int>();
            Algorithm::name = "GBFS";
            Algorithm::numberExpansions = 0;
            Algorithm::meanHeuristicValue = 0;

        };
        
        Solution solve(Instance currentInstance);
};

class IDFS: Algorithm {
    public:
        std::priority_queue<State, std::vector<State>, comp> open;
        std::unordered_map<std::string, int> distances;
    
        IDFS() : open(), distances() {
            distances = std::unordered_map<std::string, int>();
            Algorithm::name = "IDFS";
            Algorithm::numberExpansions = 0;
            Algorithm::meanHeuristicValue = 0;

        };
        
        Solution solve(Instance currentInstance);
};



