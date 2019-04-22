#ifndef CS3052_P02_REDUCTIONS_CLAUSE_H
#define CS3052_P02_REDUCTIONS_CLAUSE_H
#include <string>
#include <vector>
using namespace std;

/**
 * Class to represent clauses of a SAT representation
 */
class Clause {

public:
    //Getter for variables of clause
    vector<string> &getVars();

    //Setter for variables of clause
    void setVars(const vector<string> &vars);

private:
    //Variables of clause
    vector<string> vars;
};


#endif //CS3052_P02_REDUCTIONS_CLAUSE_H
