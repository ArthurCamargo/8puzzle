#pragma once

#include <iostream>
#include <stdio.h>
#include <getopt.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <utility>

#include <string.h>

#include "instance.h"
#include "state.h"
#include "algorithms.h"
#include "problem.h"


Problem processArgs(int argc, char* argv[]);
char encode(char* c);
std::pair<int, std::vector<std::string>> stringifyInput(char* argv[], int argc);
Instance getInstance(std::string s);
