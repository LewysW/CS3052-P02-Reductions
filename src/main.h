//
// Created by locw on 19/04/19.
//

#ifndef CS3052_P02_REDUCTIONS_MAIN_H
#define CS3052_P02_REDUCTIONS_MAIN_H
#include <iostream>
#include <cstring>
#include "parsers/parserCNF.h"
#include "parsers/parserCOL.h"
#include "formats/SAT.h"
#define EMPTY_FILE -4

using namespace std;

bool endsWith(std::string str, std::string suffix);
void printFile(vector<string>& file);

#endif //CS3052_P02_REDUCTIONS_MAIN_H
