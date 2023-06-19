#pragma once

#include <iostream>
#include <string>

class State {
    /* Single state of a problem:
     * cost: long
     * body: string
     * heuristic_value: long
     * f_cost: long
     */

    private:
        long cost;
        std::string body;
        long heuristic_value;
        long f_cost;

    public:
        State();
        ~State();
};
