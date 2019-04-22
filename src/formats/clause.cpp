#include "clause.h"

/**
 * Getter for variables of clause
 * @return - variables of clause
 */
vector<string>& Clause::getVars() {
    return vars;
}

/**
 * Setter for variables of clause
 * @param vars - variables to assign to clause
 */
void Clause::setVars(const vector<string> &vars) {
    Clause::vars = vars;
}
