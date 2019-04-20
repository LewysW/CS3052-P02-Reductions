#include "SAT.h"

SAT::SAT(vector<string> file) {
    vector<string>::iterator pos;

    //Assigns the values of the problem line to numVars and numClauses
    for (auto it = file.begin(); it != file.end(); it++) {
        if (it[0][0] == 'p') {
            vector<string> line = ParserCNF::tokenizeLine(*it);
            setNumVars(stoi(line[NUM_VARIABLE_INDEX]));
            setNumClauses(stoi(line[NUM_CLAUSE_INDEX]));
            pos = it;
            break;
        }
    }

    string clauseStr;
    //Combines all of the clauses into a single string
    for (auto it = pos + 1; it != file.end(); it++) {
        clauseStr += *it;
    }

    //Tokenises the clause string into variables and conjunctions
    vector<string> clauseTokens = ParserCNF::tokenizeLine(clauseStr);

    //Parses the clause tokens into clause object, removing conjunctions
    auto* clause = new Clause;
    for (auto it = clauseTokens.begin(); it != clauseTokens.end(); it++) {
        if (*it != "0") {
            clause->getVars().push_back(*it);
            cout << *it << endl;
        } else {
            clauses.push_back(*clause);
            clause = new Clause;
        }
    }

    clauses.push_back(*clause);

    cout << "GETS HERE" << endl;
    printClauses();
}

void SAT::setClauses(vector<Clause> &clauses) {
    SAT::clauses = clauses;
}

vector<Clause> &SAT::getClauses() {
    return clauses;
}

void SAT::printClauses() {
    for (auto it = clauses.begin(); it != clauses.end(); it++) {
        cout << "CLAUSE: ";

        for (auto it1 = it->getVars().begin(); it1 != it->getVars().end(); it1++) {
            cout << *it1 << " ";
        }

        cout << endl;
    }
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

