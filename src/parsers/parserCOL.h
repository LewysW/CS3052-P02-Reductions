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

class ParserCOL {
public:
    vector<string> readInput();
    int validFile(vector<string>& file);
    static vector<string> tokenizeLine(string line);
    bool is_digits(const std::string &str);
};


#endif //CS3052_P02_REDUCTIONS_PARSERCOL_H
