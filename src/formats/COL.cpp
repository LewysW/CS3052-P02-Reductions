#include "COL.h"

/**
 * Default constructor of COL
 */
COL::COL() = default;

/**
 * Constructor for COL representation
 * @param file - validated input file to assign to COL object
 */
COL::COL(vector<string> file) {
    //Vectors to store tokenized line from file and edges from file
    vector<string> line;
    vector<pair<int, int>> tempEdges;

    //Iterate through each line of the file
    for (auto it = file.begin(); it != file.end(); it++) {
        //Tokenize line into a list of string tokens
        line = ParserCOL::tokenizeLine(*it);

        //Checks if the current line is the problem line
        if (line.front() == "p") {
            //Assigns number of nodes and number of edges
            setNumNodes(stoi(line[NUM_NODES_INDEX]));
            setNumEdges(stoi(line[NUM_EDGES_INDEX]));
        //Checks if the current line is the colours line
        } else if (line.front() == "colours") {
            //Assigns value of k, the number of colours
            setK(stoi(line.back()));
        //Checks that the current line is an edge
        } else if (line.front() == "e") {
            //Assigns the edge to the list of edges
            tempEdges.emplace_back(std::make_pair(stoi(line[FIRST_NODE]), stoi(line[SECOND_NODE])));
        }
    }

    //Assigns the list of edges to the COL object
    setEdges(tempEdges);
}

/**
 * Converts the COL object into
 * a SAT object
 * @return - a SAT object pointer
 */
SAT* COL::toSAT() {
    //Creates SAT object, a list to store clauses,
    // and assigns the number of variables and clauses of the SAT object
    auto sat = new SAT;
    vector<Clause> tempClauses;
    sat->setNumVars(0);
    sat->setNumClauses(0);

    /**
     * TASK 3 kCOL to SAT analysis [1.1]:
     */

    //At-least-one clauses (ALO)
    //A single clause {yi,1, yi,2, . . . yi,k} for each node i, which says that each node has
    //to have at least one colour
    for (int node = 0; node < getNumNodes(); node++) {
        auto* clause = new Clause;
        vector<string> vars;

        /**
         * TASK 3 kCOL to SAT analysis [1.2]:
         */
        for (int col = 1; col <= getK(); col++) {
            vars.push_back(to_string(node * getK() + col));
            sat->setNumVars(sat->getNumVars() + 1);
        }

        clause->setVars(vars);
        tempClauses.push_back(*clause);
    }

    /**
     * TASK 3 kCOL to SAT analysis [2.0]:
     */

    //At-most-one clauses (AMO)
    //A clause for every node and pair j, j0 of colours. The clause {¬yi,j , ¬yi,j0} says
    //that node i can’t be both colour j and colour j0.
    for (int node = 0; node < getNumNodes(); node++) {
        //TASK 3 kCOL to SAT analysis [2.1]
        for (int col = 1; col < getK(); col++) {
            int colCount = col + 1;

            /**
             * TASK 3 kCOL to SAT analysis [2.2]:
             */

            while (colCount <= getK()) {
                auto* clause = new Clause;
                vector<string> vars;
                vars.push_back(to_string((node * getK() + col) * -1));
                vars.push_back(to_string((node * getK() + colCount) * -1));
                colCount++;
                clause->setVars(vars);
                tempClauses.push_back(*clause);
            }
        }
    }

    /**
     * TASK 3 kCOL to SAT analysis [3.0]:
     */

    /* Edge clauses
     * For each edge in the graph connecting nodes i and i0, one clause for each colour j.
     * The clause{¬yi,j , ¬yi0,j} says that either i or i0is not coloured with j (or neither is).
     * */
    for (auto it = getEdges().begin(); it != getEdges().end(); it++) {
        int first = it->first;
        int second = it->second;

        /**
         * TASK 3 kCOL to SAT analysis [3.1]:
         */

        for (int col = 1; col <= getK(); col++) {
            Clause clause;
            vector<string> vars;
            vars.push_back(to_string(((first - 1) * getK() + col) * -1));
            vars.push_back(to_string(((second - 1) * getK() + col) * -1));
            clause.setVars(vars);
            tempClauses.push_back(clause);
        }
    }

    //Assigns list of clauses and number of clauses to SAT object
    sat->setClauses(tempClauses);
    sat->setNumClauses(tempClauses.size());

    return sat;
}

/**
 * Prints the COL object
 */
void COL::print() {
    cout << "p edge " << getNumNodes() << " " << getNumEdges() << endl;
    cout << "colours " << getK() << endl;

    for (auto it = edges.begin(); it != edges.end(); it++) {
        cout << "e " << it->first << " " << it->second << endl;
    }
}

/**
 * Getter for the list of pairs of edges
 * @return - list of edges
 */
vector<pair<int, int>> &COL::getEdges() {
    return edges;
}

/**
 * Setter for list of edges
 * @param edges - list of edges to assign
 */
void COL::setEdges(vector<pair<int, int>> &edges) {
    COL::edges = edges;
}

/**
 * Getter for number of colours k
 * @return - number of colours k
 */
int COL::getK() const {
    return k;
}

/**
 * Setter for number of colours k
 * @param k - number of colours
 */
void COL::setK(int k) {
    COL::k = k;
}

/**
 * Getter for number of nodes
 * @return - number of nodes
 */
int COL::getNumNodes() const {
    return numNodes;
}

/**
 * Setter for number of nodes
 * @param numNodes - number of nodes to assign
 */
void COL::setNumNodes(int numNodes) {
    COL::numNodes = numNodes;
}

/**
 * Getter for number of edges
 * @return - number of edges in graph
 */
int COL::getNumEdges() const {
    return numEdges;
}

/**
 * Setter for number of edges
 * @param numEdges - number of edges in graph to assign
 */
void COL::setNumEdges(int numEdges) {
    COL::numEdges = numEdges;
}
