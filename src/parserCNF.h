//
// Created by locw on 19/04/19.
//

#ifndef CS3052_P02_REDUCTIONS_PARSER_H
#define CS3052_P02_REDUCTIONS_PARSER_H

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#define PROBLEM_LINE_LENGTH 4
#define INVALID_PREAMBLE (-1)
#define INVALID_PROBLEM_LINE (-2)
#define INVALID_CLAUSES (-3)
#define BASE_TEN 10


using namespace std;

class ParserCNF {
public:
    vector<string> readInput();
    int validFile(vector<string>& file);
    static vector<string> tokenizeLine(string line);
    bool is_digits(const std::string &str);
};

#endif //CS3052_P02_REDUCTIONS_PARSER_H
