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

/**
 * Class to represent the SAT format
 */
class SAT {
public:
    //Constructors
    explicit SAT();
    explicit SAT(vector<string> file);

    //Function to convert to 3SAT
    SAT* to3SAT();

    //Function to check if SAT object is in 3-SAT
    bool is3SAT();

    //Function to convert to kCOL
    COL* toKCOL();

    //Function to print SAT object
    void print();

    //Getters and setters:

    vector<Clause>& getClauses();

    void setClauses(vector<Clause> &clauses);

    int getNumVars() const;

    unsigned long getNumClauses() const;

    void setNumVars(int numVars);

    void setNumClauses(unsigned long numClauses);
private:
    //Number of variables, number of clauses, and list of clauses in SAT object
    int numVars;
    unsigned long numClauses;
    vector<Clause> clauses;
};

#endif //CS3052_P02_REDUCTIONS_SAT_H
