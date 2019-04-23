#include "SAT.h"

/**
 * Default constructor
 */
SAT::SAT() = default;

/**
 * Constructor for SAT object
 * @param file - validated input file to represent SAT object
 */
SAT::SAT(vector<string> file) {
    vector<string>::iterator pos;

    //Assigns the values of the problem line to numVars and numClauses
    for (auto it = file.begin(); it != file.end(); it++) {
        if (it[0][0] == 'p') {
            vector<string> line = ParserCNF::tokenizeLine(*it);
            setNumVars(stoi(line[NUM_VARIABLE_INDEX]));
            setNumClauses((unsigned long) stoi(line[NUM_CLAUSE_INDEX]));
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

/**
 * Converts SAT object from SAT to 3SAT
 * @return - SAT object complying with constraints of 3SAT
 */
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

    //Assigns the list of clauses and number of clauses to 3-SAT object
    threeSAT->setClauses(tempClauses);
    threeSAT->setNumClauses(tempClauses.size());

    return threeSAT;
}

/**
 * Converts the SAT object to k-COL
 * @return a pointer to a COL object
 */
COL* SAT::toKCOL() {
    //Stores the number of variables, number of clauses, COL object, and list of edges
    int n = getNumVars();
    unsigned long k = getNumClauses();
    auto* col = new COL;
    vector<pair<int, int>> tempEdges;

    //Sets the k colour value of col
    col->setK(n + 1);

    //Sets the number of vertices (nodes)
    col->setNumNodes(3 * n + k);

    //Each vertex xi is joined to ¬xi
    for (int i = 1; i <= n; i++) {
        tempEdges.emplace_back(make_pair(i, i + n));
    }

    //Each vertex yi is joined to every other yj
    for (int i = 2*n + 1; i <= (2*n + n); i++) {
        for (int j = i + 1; j <= (2*n + n); j++) {
            tempEdges.emplace_back(make_pair(i, j));
        }
    }

    //Each vertex yi is joined to xj and ¬xj provided j != i
    for (int i = 2*n + 1; i <= (2*n + n); i++) {
        for (int j = 1; j <= 2*n; j++) {
            //Checks that j != i for each vertex yi joining to xj and ¬xj
            if ((i % n) != (j % n)) {
                tempEdges.emplace_back(make_pair(i, j));
            }
        }
    }

    //Each vertex Ci is joined to each literal xj or ¬xj which is is not in clause i
    for (unsigned int i = 1; i <= k; i++) {
        vector<string> vars = getClauses()[i - 1].getVars();
        for (int j = 1; j <= 2*n; j++) {
            string var;
            //Converts j to a correct CNF variable value
            if (j > n && j <= 2*n) {
                var = to_string((j - n) * -1);
            } else {
                var = to_string(j);
            }

            if (find(vars.begin(), vars.end(), var) == vars.end()) {
                tempEdges.emplace_back(make_pair(3 * n + i, j));
            }
        }

        cout << endl;
    }

    //Assigns the number of edges and list of edges to the COL object
    col->setNumEdges(tempEdges.size());
    col->setEdges(tempEdges);

    return col;
}

/**
 * Checks if SAT object is in 3SAT
 * @return - whether or not SAT object is in 3SAT
 */
bool SAT::is3SAT() {
    //Iterates through each clause in the SAT object and checks whether any clause has more than 3 variables
    for (auto it = getClauses().begin(); it != getClauses().end(); it++) {
        if (it->getVars().size() > 3) {
            return false;
        }
    }

    return true;
}

/**
 * Setter for the list of clauses
 * @param clauses - list of clauses to assign
 */
void SAT::setClauses(vector<Clause> &clauses) {
    SAT::clauses = clauses;
}

/**
 * Getter for list of clauses
 * @return - list of clauses
 */
vector<Clause> &SAT::getClauses() {
    return clauses;
}

/**
 * Prints the SAT object
 */
void SAT::print() {
    cout << "p cnf " << getNumVars() << " " << getNumClauses() << endl;

    for (auto it = clauses.begin(); it != clauses.end(); it++) {
        for (auto it1 = it->getVars().begin(); it1 != it->getVars().end(); it1++) {
            cout << *it1 << " ";
        }

        cout << "0" << endl;
    }
}

/**
 * Getter for the number of variables
 * @return - the number of variables in the SAT object
 */
int SAT::getNumVars() const {
    return numVars;
}

/**
 * Getter for the number of clauses
 * @return - number of clauses
 */
unsigned long SAT::getNumClauses() const {
    return numClauses;
}

/**
 * Setter for number of variables
 * @param numVars - number of variables to assign
 */
void SAT::setNumVars(int numVars) {
    SAT::numVars = numVars;
}

/**
 * Setter for number of clauses
 * @param numClauses - number of clauses to assign
 */
void SAT::setNumClauses(unsigned long numClauses) {
    SAT::numClauses = numClauses;
}

