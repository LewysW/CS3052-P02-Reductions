#include "SAT.h"

SAT::SAT() = default;

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

    if (getNumClauses() == 0) return;

    string clauseStr;
    //Combines all of the clauses into a single string
    for (auto it = pos + 1; it != file.end(); it++) {
        clauseStr += *it + " ";
    }

    //Tokenises the clause string into variables and conjunctions
    vector<string> clauseTokens = ParserCNF::tokenizeLine(clauseStr);

    //Parses the clause tokens into clause object, removing conjunctions
    auto* clause = new Clause;
    for (auto it = clauseTokens.begin(); it != clauseTokens.end(); it++) {
        if (*it != "0") {
            clause->getVars().push_back(*it);
        } else {
            if (it + 1 != clauseTokens.end()) {
                clauses.push_back(*clause);
                clause = new Clause;
            }
        }
    }

    clauses.push_back(*clause);
}

SAT* SAT::to3SAT() {
    SAT* threeSAT = new SAT;
    vector<Clause> tempClauses = getClauses();
    threeSAT->setNumVars(getNumVars());

    //Iterates through each clause
    for (auto clause = tempClauses.begin(); clause != tempClauses.end(); clause++) {
        //If size of clause is greater than 3 variables, beginning resizing process
        if (clause->getVars().size() > 3) {
            string var;
            //Loops while clause greater than 3
            for (auto variable = clause->getVars().end() - 1; clause->getVars().size() > 2; variable--) {
                //Copies the variable in the clause and removes it from the clause
                var = *variable;
                cout << "var: " << var << endl;
                clause->getVars().pop_back();

                //If there is a subsequent clause in the list, move variables there
                if (clause + 1 != tempClauses.end()) {
                    (clause + 1)->getVars().insert((clause + 1)->getVars().begin(), var);
                //If new clause has to be created, move variable there
                } else {
                    Clause newClause;
                    vector<string> vars;
                    vars.insert(vars.begin(), var);
                    newClause.setVars(vars);
                    tempClauses.push_back(newClause);
                }
            }
            //Creates new variable
            long newVar = threeSAT->getNumVars() + 1;

            //Inserts new variable at end of current clause and negation of that variable at beginning of next clause
            clause->getVars().push_back(to_string(newVar));

            //TODO - fix the segfault on this line
            (clause + 1)->getVars().insert((clause + 1)->getVars().begin(), to_string(-1 * newVar));
            //Resizes number of variables in threeSAT
            threeSAT->setNumVars(threeSAT->getNumVars() + 1);
        }

        for (auto it = tempClauses.begin(); it != tempClauses.end(); it++) {
            for (auto it1 = it->getVars().begin(); it1 != it->getVars().end(); it1++) {
                cout << *it1 << " ";
            }

            cout << "0 ";
        }
    }

    //TODO - refactor clause size functions (getter/setter)
    threeSAT->setClauses(tempClauses);
    threeSAT->setNumClauses(tempClauses.size());

    return threeSAT;
}

void SAT::setClauses(vector<Clause> &clauses) {
    SAT::clauses = clauses;
}

vector<Clause> &SAT::getClauses() {
    return clauses;
}

void SAT::print() {
    cout << "p cnf " << getNumVars() << " " << getNumClauses() << endl;

    for (auto it = clauses.begin(); it != clauses.end(); it++) {
        for (auto it1 = it->getVars().begin(); it1 != it->getVars().end(); it1++) {
            cout << *it1 << " ";
        }

        cout << "0" << endl;
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

