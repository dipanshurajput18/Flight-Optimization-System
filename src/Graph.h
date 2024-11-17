#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <string>
#include <limits>

class Graph {
private:
    // Adjacency list to store the graph
    std::unordered_map<std::string, std::list<std::pair<std::string, double>>> adjList;

public:
    // Add an edge to the graph
    void addEdge(const std::string& source, const std::string& destination, double weight);

    // Print the graph
    void printGraph();
};

#endif