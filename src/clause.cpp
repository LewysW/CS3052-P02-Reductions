//
// Created by locw on 20/04/19.
//

#include "clause.h"


vector<string>& Clause::getVars() {
    return vars;
}

void Clause::setVars(const vector<string> &vars) {
    Clause::vars = vars;
}
