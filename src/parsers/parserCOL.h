#ifndef CS3052_P02_REDUCTIONS_PARSERCOL_H
#define CS3052_P02_REDUCTIONS_PARSERCOL_H
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#define PROBLEM_LINE_LENGTH 4
#define INVALID_PREAMBLE (-1)
#define INVALID_PROBLEM_LINE (-2)
#define INVALID_COLOURS (-3)
#define INVALID_EDGES (-4)
#define COLOUR_LENGTH 7
#define NUM_COLOUR_TOKENS 2
#define NUM_EDGE_TOKENS 3

using namespace std;

/**
 * Parser class for COL input files
 */
class ParserCOL {
public:
    //Reads the input from standard input
    vector<string> readInput();

    //Validates the input file, returns 0 if valid or an error code if not
    int validFile(vector<string>& file);

    //Tokenizes a line into a vector of string tokens
    static vector<string> tokenizeLine(string line);

    //Checks whether a string is made up of digit characters
    bool is_digits(const std::string &str);
};


#endif //CS3052_P02_REDUCTIONS_PARSERCOL_H
