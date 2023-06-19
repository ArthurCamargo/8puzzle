#include "include/util.h"

void processArgs(int argc, char* argv[])
{
    int opt_char;

    const std::string usage = "Usage: ./main <option> instance \n";

    static struct option long_options[] = {
        {"bfs", no_argument, 0, 'b'},
        {"astar", no_argument, 0, 'a'},
        {"idfs", no_argument, 0, 'd'},
        {"idastar", no_argument, 0, 'i'},
        {"gbfs", no_argument, 0, 'g'},
        {NULL, no_argument, 0, 0},
    };

    std::cout << "Number of arguments: " << argc << std::endl;

    
    while((opt_char = getopt_long_only(argc, argv, "b:a:d:i:g:",
                    long_options, NULL)) != -1) {
        switch (opt_char) {
            case (int)'b':
                std::cout << "it's bfs" << std::endl;
                break;
            case (int)'a':
                std::cout << "astar" << std::endl;
                break;
            case (int)'d':
                std::cout << "idfs" << std::endl;
                break;
            case (int)'i':
                std::cout << "idastar" << std::endl;
                break;
            case (int)'g': //101
                std::cout << "gbfs" << std::endl;
                break;
            default:
                std::cout << "none of the above" << std::endl;
                break;
       }
   }
}
