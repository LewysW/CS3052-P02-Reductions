//
// Created by locw on 21/04/19.
//

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
