#pragma once 

#include "state.h"
#include "action.h"

#include <stdio.h>
#include <iostream>
#include <vector>


class Node {
    /* Node class, defines an node of the problem:
     * current_state: State
     * cost: long
     * parent: Node
     * children: <vector> Node
     * action: 
    */
    private:
        State current_state;
        long cost;
        Node* parent;
        std::vector<Node*> children;
        Action action;

    public:
        Node();
        ~Node();
};
