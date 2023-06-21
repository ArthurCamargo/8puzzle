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
                Bfs algorithmBfs;
                for(int i = 0; i < currentProblem.instances.size(); i ++) {
                    Solution s = algorithmBfs.solve(currentProblem.instances[i]);
                    s.print();
                }
            }
            break;
        case ASTAR:
            {
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

