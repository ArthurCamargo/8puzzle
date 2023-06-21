#include "include/util.h"

#include <stdlib.h>
#include <stdio.h>

#include <iostream>

int main (int argc, char* argv[]) {

    Problem currentProblem;
    algorithmEnum  algorithmType;
    currentProblem = createProblem(argc, argv);
    algorithmType = processArgs(argc, argv);


    switch (algorithmType) {
        case BFS:
            {
                for(int i = 0; i < currentProblem.instances.size(); i ++) {
                    Bfs algorithmBfs;
                    Solution s = algorithmBfs.solve(currentProblem.instances[i]);
                    s.print();
                }
            }
            break;
        case ASTAR:
            {
                for(int i = 0; i < currentProblem.instances.size(); i ++) {
                    Astar algorithmAstar;
                    Solution s = algorithmAstar.solve(currentProblem.instances[i]);
                    s.print();
                }
            }
            break;
        case GBFS:
            {
            }
            break;
        case IDASTAR:
            {
            }
            break;
        case IDFS:
            {
            }
            break;
    }


    return 0;
}

