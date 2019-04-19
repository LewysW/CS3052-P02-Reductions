//
// Created by locw on 19/04/19.
//

#ifndef CS3052_P02_REDUCTIONS_SAT_H
#define CS3052_P02_REDUCTIONS_SAT_H
#define NUM_VARIABLE_INDEX 2
#define NUM_CLAUSE_INDEX 3

#include <vector>
#include <string>
#include "parserCNF.h"
#include <vector>

using namespace std;

class SAT {
public:
    explicit SAT(vector<string> file);

    const vector<vector<string>> &SAT::getClauses();

    void setClauses(const vector<vector<string>> &clauses);

    int getNumVars() const;

    int getNumClauses() const;

    void setNumVars(int numVars);

    void setNumClauses(int numClauses);

    vector<string> ParserCNF::tokenizeLine(string line);
private:
    int numVars;
    int numClauses;
    vector<vector<string>> clauses;
};

#endif //CS3052_P02_REDUCTIONS_SAT_H
