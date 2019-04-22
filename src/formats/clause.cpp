#include "clause.h"


vector<string>& Clause::getVars() {
    return vars;
}

void Clause::setVars(const vector<string> &vars) {
    Clause::vars = vars;
}
