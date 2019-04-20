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
#include "clause.h"
#include <vector>

using namespace std;

class SAT {
public:
    explicit SAT();
    explicit SAT(vector<string> file);

    SAT* to3SAT();

    vector<Clause>& getClauses();

    void setClauses(vector<Clause> &clauses);

    int getNumVars() const;

    int getNumClauses() const;

    void print();

    void setNumVars(int numVars);

    void setNumClauses(int numClauses);
private:
    int numVars;
    int numClauses;
    vector<Clause> clauses;
};

#endif //CS3052_P02_REDUCTIONS_SAT_H
