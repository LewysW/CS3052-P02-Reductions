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

/**
 * Parser class for CNF input files
 */
class ParserCNF {
public:
    //Reads the input for standard input
    vector<string> readInput();

    //Validates an input file for CNF (0 if valid and an error code if not)
    int validFile(vector<string>& file);

    //Tokenizes a string into a list of tokens
    static vector<string> tokenizeLine(string line);

    //Checks whether a string is made up of digit characters
    bool is_digits(const std::string &str);
};

#endif //CS3052_P02_REDUCTIONS_PARSER_H
