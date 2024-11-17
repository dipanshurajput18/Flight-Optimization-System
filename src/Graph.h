#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <string>
#include <limits>

using namespace std;

class Graph {
private:
    // Adjacency list to store the graph
    unordered_map<string, list<pair<string, double>>> adjList;

public:
    // Add an edge to the graph
    void addEdge(const string& source, const string& destination, double weight);

    // Print the graph
    void printGraph();
};

#endif