#include "Graph.h"

// Add an edge to the graph
void Graph::addEdge(const string& source, const string& destination, double weight) {
    adjList[source].push_back({destination, weight});
    adjList[destination].push_back({source, weight}); // If the graph is bidirectional
}

// Print the graph
void Graph::printGraph() {
    for (const auto& node : adjList) {
        cout << node.first << " -> ";
        for (const auto& neighbor : node.second) {
            cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
        }
        cout << endl;
    }
}
