#include "include/util.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(int argc, char *argv[]) {

  Problem currentProblem;
  algorithmEnum algorithmType;
  currentProblem = createProblem(argc, argv);
  algorithmType = processArgs(argc, argv);

  switch (algorithmType) {
      case BFS: {
        for (int i = 0; i < currentProblem.instances.size(); i++) {
          Bfs bfs;
          Solution s = bfs.solve(currentProblem.instances[i]);
          s.print();
        }
      } break;
      case ASTAR: {
        for (int i = 0; i < currentProblem.instances.size(); i++) {
          Astar astar;
          Solution s = astar.solve(currentProblem.instances[i]);
          s.print();
        }
      } break;
      case GBFS: {
        for (int i = 0; i < currentProblem.instances.size(); i++) {
          class GBFS gbfs;
          // Solution s = gbfs.solve(currentProblem.instances[i]);
          // s.print();
        }

      } break;
      case IDASTAR: {
        for (int i = 0; i < currentProblem.instances.size(); i++) {
          IDAstar idastar;
          // Solution s = idastar.solve(currentProblem.instances[i]);
          // s.print();
        }
      } break;
      case IDFS: {
        for (int i = 0; i < currentProblem.instances.size(); i++) {
          class IDFS idfs;
          // Solution s = idfs.solve(currentProblem.instances[i]);
          // s.print();
        }
      } break;
  }

  return 0;
}
