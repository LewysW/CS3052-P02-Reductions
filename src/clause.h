//
// Created by locw on 20/04/19.
//

#ifndef CS3052_P02_REDUCTIONS_CLAUSE_H
#define CS3052_P02_REDUCTIONS_CLAUSE_H
#include <string>
#include <vector>
using namespace std;

class Clause {

public:
    vector<string> &getVars();

private:
    vector<string> vars;
};


#endif //CS3052_P02_REDUCTIONS_CLAUSE_H
