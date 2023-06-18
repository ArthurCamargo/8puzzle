#pragma once

#include <iostream>
#include <string>

#include "node.h"
#include "instance.h"

class Problem {
    /* Problem class:
     * description: string
     * possible_actions: const vector<Action>
     */
    private:
        std::string description;
        std::vector<Instance*> instances;
        std::vector<Action> possible_actions;

    public:
        Problem(std::string description, std::vector<Action> possible_actions);
        void CreateInstance();
        ~Problem();
};
