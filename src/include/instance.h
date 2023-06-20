#pragma once

#include <iostream>

#include "state.h"

class Instance {
    public:
        State initial_state;
        State final_state;
        int size;

        Instance(State new_initial_state, const State new_final_state, int new_size) {
            this->initial_state = new_initial_state;
            this->final_state = new_final_state;
            this->size = new_size;
        }

        void print()
        {
            std::cout << "Instance size: " << size << std::endl;
            std::cout << "Initial State: ";
            initial_state.print();
            std::cout << "Final State: ";
            final_state.print();
        }

        Instance() = default;
};
