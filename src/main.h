#ifndef CS3052_P02_REDUCTIONS_MAIN_H
#define CS3052_P02_REDUCTIONS_MAIN_H
#include <iostream>
#include <cstring>
#include "parsers/parserCNF.h"
#include "parsers/parserCOL.h"
#include "formats/COL.h"
#include "formats/SAT.h"
#define EMPTY_FILE (-4)
#define NOT_3SAT (-5)
#define EXEC_NOT_RECOGNISED (-6)

using namespace std;

/*Runs the procedure corresponding to
 the executable name provided */
int run(string execName);

//Returns whether a given string ends with a given suffix
bool endsWith(std::string str, std::string suffix);

#endif //CS3052_P02_REDUCTIONS_MAIN_H
