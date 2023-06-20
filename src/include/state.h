#pragma once

#include <iostream>
#include <vector>
#include <string>

class State {
    public:
        std::string game;

        State(std::string new_game) {
            this->game = new_game;
        }

        void print() {
            std::cout << "Game: " << game << std::endl;
        }

        State() = default;
        ~State() = default;
};
