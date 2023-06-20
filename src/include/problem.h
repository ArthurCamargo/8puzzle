#pragma once

#include "instance.h"
#include "algorithms.h"

class Problem {
    public:
        std::vector<Instance> instances;
        algorithms alg;

        Problem(std::vector<Instance> newInstances, algorithms newAlg)
        {
            this->instances = newInstances;
            this->alg = newAlg;
        }

        Problem() = default;

        void print() {
            
            for(int i = 0; i < instances.size(); i ++)
            {
                std::cout << "Algorithm: " << alg << std::endl;
                instances[i].print();
            }
        }

        void solve() {

        }



};
