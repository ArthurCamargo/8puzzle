#include "include/util.h"

char encode(char* c)
{
    char uniqueChar = '0';
    int l = strlen(c);
    if(l == 1)
        uniqueChar = c[0];
    else if(l == 2 && c[l-1] == ',')
        uniqueChar = c[0];
    else {
        int numberValue = atoi(c);
        uniqueChar = (char) numberValue + 55; // Convert 10 -> A(65) ..
    }

    return uniqueChar;
}

Problem createProblem(int argc, char* argv[], algorithms a)
{
    std::vector<Instance> instances;
    std::string newString;
    std::vector<std::string> newStrings;


    int numberInstances = 0;
    int i = 2;

    while(i < argc)
    {
        newString.push_back(encode(argv[i]));
        if (argv[i][strlen(argv[i])-1] == ',')
        {
            newStrings.push_back(newString);
            newString.clear();
        }
        i++;
    }
    newStrings.push_back(newString); // push the last one

    for (int i = 0; i < newStrings.size(); i++) {
        Instance newInstance = getInstance(newStrings[i]);
        instances.push_back(newInstance);
    }

    Problem p(instances, a);
    return p;
}

Instance getInstance(std::string s)
{

    std::string finalString;

    int size = s.size();

    if (size == 9) {
        finalString = "012345678";
    }
    else if (size == 16) {
        finalString = "0123456789ABCDEF";
    }

    State initialState(s);
    State finalState(finalString);

    Instance new_instance(initialState, finalState, size);

    return new_instance;
}

Problem processArgs(int argc, char* argv[])
{
    int opt_char;

    const std::string usage = "Usage: ./main <option> instance \n";

    int i = 0;
    Problem p;

    static struct option long_options[] = {
        {"bfs", no_argument, 0, 'b'},
        {"astar", no_argument, 0, 'a'},
        {"idfs", no_argument, 0, 'd'},
        {"idastar", no_argument, 0, 'i'},
        {"gbfs", no_argument, 0, 'g'},
        {NULL, no_argument, 0, 0},
    };
    
    while((opt_char = getopt_long_only(argc, argv, "badig",
                    long_options, NULL)) != -1) {
        switch (opt_char) {
            case (int)'b':
                p = createProblem(argc, argv, BFS);
                p.print();
                break;
            case (int)'a':
                p = createProblem(argc, argv, ASTAR);
                break;
            case (int)'d':
                p = createProblem(argc, argv, IDFS);
                break;
            case (int)'i':
                p = createProblem(argc, argv, IDASTAR);
                break;
            case (int)'g': 
                p = createProblem(argc, argv, GBFS);
                break;
            default:
                std::cout << "none of the above" << std::endl;
                exit(1);
                break;
       }
   }
   return p;
}
