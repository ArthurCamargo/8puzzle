#pragma once

#include <iostream>

#include "state.h"

class Instance {
    public:
        State initialState;
        State finalState;
        int size;
        int statesExpanded;

        Instance(State newInitialState, State newFinalState, int newSize) {
            this->initialState = newInitialState;
            this->finalState = newFinalState;
            this->size = newSize;
            this->statesExpanded = 0;
        }

        void print()
        {
            std::cout << "Instance size: " << size << std::endl;
            std::cout << "Initial State: ";
            initialState.print();
            std::cout << "Final State: ";
            finalState.print();
        }

        Instance() = default;
};
