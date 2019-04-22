#include "COL.h"

COL::COL() = default;

COL::COL(vector<string> file) {
    vector<string> line;
    vector<pair<int, int>> tempEdges;
    for (auto it = file.begin(); it != file.end(); it++) {
        line = ParserCOL::tokenizeLine(*it);
        if (line.front() == "p") {
            setNumNodes(stoi(line[NUM_NODES_INDEX]));
            setNumEdges(stoi(line[NUM_EDGES_INDEX]));
        } else if (line.front() == "colours") {
            setK(stoi(line.back()));
        } else if (line.front() == "e") {
            tempEdges.emplace_back(std::make_pair(stoi(line[FIRST_NODE]), stoi(line[SECOND_NODE])));
        }
    }

    setEdges(tempEdges);
}

SAT* COL::toSAT() {
    auto sat = new SAT;
    vector<Clause> tempClauses;
    sat->setNumVars(0);
    sat->setNumClauses(0);

    //At-least-one clauses (ALO)
    for (int node = 0; node < getNumNodes(); node++) {
        auto* clause = new Clause;
        vector<string> vars;

        for (int col = 1; col <= getK(); col++) {
            vars.push_back(to_string(node * getK() + col));
            sat->setNumVars(sat->getNumVars() + 1);
        }

        clause->setVars(vars);
        tempClauses.push_back(*clause);
    }

    //At-most-one clauses (AMO)
    for (int node = 0; node < getNumNodes(); node++) {
        for (int col = 1; col < getK(); col++) {
            int colCount = col + 1;
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

    //Edge clauses
    for (auto it = getEdges().begin(); it != getEdges().end(); it++) {
        int first = it->first;
        int second = it->second;

        for (int col = 1; col <= getK(); col++) {
            Clause clause;
            vector<string> vars;
            vars.push_back(to_string(((first - 1) * getK() + col) * -1));
            vars.push_back(to_string(((second - 1) * getK() + col) * -1));
            clause.setVars(vars);
            tempClauses.push_back(clause);
        }
    }

    sat->setClauses(tempClauses);
    sat->setNumClauses(tempClauses.size());

    return sat;
}

void COL::print() {
    cout << "p edge " << getNumNodes() << " " << getNumEdges() << endl;
    cout << "colours " << getK() << endl;

    for (auto it = edges.begin(); it != edges.end(); it++) {
        cout << "e " << it->first << " " << it->second << endl;
    }
}

vector<pair<int, int>> &COL::getEdges() {
    return edges;
}

void COL::setEdges(vector<pair<int, int>> &edges) {
    COL::edges = edges;
}

int COL::getK() const {
    return k;
}

void COL::setK(int k) {
    COL::k = k;
}

int COL::getNumNodes() const {
    return numNodes;
}

void COL::setNumNodes(int numNodes) {
    COL::numNodes = numNodes;
}

int COL::getNumEdges() const {
    return numEdges;
}

void COL::setNumEdges(int numEdges) {
    COL::numEdges = numEdges;
}
