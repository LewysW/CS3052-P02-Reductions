#include "SAT.h"

SAT::SAT(vector<string> file) {
    vector<string>::iterator pos;

    for (auto it = file.begin(); it != file.end(); it++) {
        if (it[0][0] == 'p') {
            vector<string> line = ParserCNF::tokenizeLine(*it);
            setNumVars(stoi(line[NUM_VARIABLE_INDEX]));
            setNumClauses(stoi(line[NUM_CLAUSE_INDEX]));
            pos = it;
            break;
        }
    }

    for (auto it = pos; it != file.end(); it++) {
        vector<string> line = ParserCNF::tokenizeLine(*it);
        vector<vector<string>> clauses;


        for (auto it1 = line.begin(); it1 != line.end(); it1++) {
            //TODO - assign values to clauses of SAT class
            //if (*it1 != )
        }
    }
}

void SAT::setClauses(const vector<vector<string>> &clauses) {
    SAT::clauses = clauses;
}

int SAT::getNumVars() const {
    return numVars;
}

int SAT::getNumClauses() const {
    return numClauses;
}

void SAT::setNumVars(int numVars) {
    SAT::numVars = numVars;
}

void SAT::setNumClauses(int numClauses) {
    SAT::numClauses = numClauses;
}
