#pragma once

#include "instance.h"

class Problem {
    public:
        std::vector<Instance> instances;

        Problem(std::vector<Instance> newInstances)
        {
            this->instances = newInstances;
        }

        Problem() = default;

        void print();
};
