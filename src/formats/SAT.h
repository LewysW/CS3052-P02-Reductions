#ifndef CS3052_P02_REDUCTIONS_SAT_H
#define CS3052_P02_REDUCTIONS_SAT_H
#define NUM_VARIABLE_INDEX 2
#define NUM_CLAUSE_INDEX 3

#include <vector>
#include <string>
#include "../parsers/parserCNF.h"
#include "clause.h"
#include <vector>
#include "COL.h"


class COL;

using namespace std;

class SAT {
public:
    explicit SAT();
    explicit SAT(vector<string> file);

    SAT* to3SAT();
    bool is3SAT();

    COL* toKCOL();

    vector<Clause>& getClauses();

    void setClauses(vector<Clause> &clauses);

    int getNumVars() const;

    unsigned long getNumClauses() const;

    void print();

    void setNumVars(int numVars);

    void setNumClauses(unsigned long numClauses);
private:
    int numVars;
    unsigned long numClauses;
    vector<Clause> clauses;
};

#endif //CS3052_P02_REDUCTIONS_SAT_H
