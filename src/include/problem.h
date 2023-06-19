#pragma once

#include <iostream>
#include <string>

#include "node.h"
#include "instance.h"


class Problem {
    /* Problem class:
     * possible_actions: const vector<Action>
     * std::vector<Instance> instances
     */
    private:
        std::vector<Instance> instances;
        const std::vector<Action> possible_actions;

    public:
        Problem() = default;
        Problem(const std::vector<Action> possible_actions);
        void CreateInstance();
        ~Problem() = default;
};
