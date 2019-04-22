#ifndef CS3052_P02_REDUCTIONS_COL_H
#define CS3052_P02_REDUCTIONS_COL_H


#include "../parsers/parserCOL.h"
#include "SAT.h"
#define NUM_NODES_INDEX 2
#define NUM_EDGES_INDEX 3
#define FIRST_NODE 1
#define SECOND_NODE 2

class SAT;

using namespace std;

/**
 * Class representing the COL format
 */
class COL {
public:
    //Constructors
    explicit COL();
    explicit COL(vector<string> file);

    //Function to convert COL to SAT
    SAT* toSAT();

    //Function to print object
    void print();

private:
    //Stores edges of graph
    vector<pair<int, int>> edges;
    //Number of colours
    int k;
    //Stores number of nodes and edges
    int numNodes;
    int numEdges;
public:
    //Getters and setters:

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
