//
// Created by locw on 21/04/19.
//

#ifndef CS3052_P02_REDUCTIONS_COL_H
#define CS3052_P02_REDUCTIONS_COL_H


#include "../parsers/parserCOL.h"
#include "SAT.h"
#define NUM_NODES_INDEX 2
#define NUM_EDGES_INDEX 3
#define FIRST_NODE 1
#define SECOND_NODE 2

using namespace std;

class COL {
public:
    explicit COL();
    explicit COL(vector<string> file);
    SAT* toSAT();
    void print();

private:
    vector<pair<int, int>> edges;
    int k;
    int numNodes;
    int numEdges;
public:
    vector<pair<int, int>>& getEdges();

    void setEdges(vector<pair<int, int>> &edges);

    int getK() const;

    void setK(int k);

    int getNumNodes() const;

    void setNumNodes(int numNodes);

    int getNumEdges() const;

    void setNumEdges(int numEdges);
};


#endif //CS3052_P02_REDUCTIONS_COL_H