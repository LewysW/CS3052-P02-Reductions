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
    auto* threeSAT = new SAT;
    vector<Clause> tempClauses = getClauses();
    threeSAT->setNumVars(getNumVars());
    string var;

    //Used integer loop instead of iterator due to iterator invalidation
    for (unsigned int c = 0; c < tempClauses.size(); c++) {
        //Checks if a clause has more than 3 literals
        if (tempClauses[c].getVars().size() > 3) {
            Clause clause;
            vector<string> vars;

            //Loops until the clause has been reduced to 2 literals
            while (tempClauses[c].getVars().size() > 2) {
                vars.insert(vars.begin(), tempClauses[c].getVars().back());
                tempClauses[c].getVars().pop_back();
            }

            //Creates new variable and increases number of variables in threeSAT
            int newVar = threeSAT->getNumVars() + 1;
            threeSAT->setNumVars(threeSAT->getNumVars() + 1);

            //Adds variable to end of current clause and negation to beginning of next clause
            tempClauses[c].getVars().push_back(to_string(newVar));
            vars.insert(vars.begin(), to_string(newVar * -1));

            //Sets variables of new clause and adds new clause to list
            clause.setVars(vars);
            tempClauses.insert(tempClauses.begin() + c + 1, clause);
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

