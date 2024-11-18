#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph flightGraph;

    // Adding sample edges
    flightGraph.addEdge("Delhi", "Mumbai", 1500.5);
    flightGraph.addEdge("Mumbai", "Chennai", 1200.0);
    flightGraph.addEdge("Delhi", "Kolkata", 2000.75);

    // Printing the graph
    cout << "Flight Routes:" << endl;
    flightGraph.printGraph();

      // Finding shortest path using Dijkstra's Algorithm
    cout << "\nFinding shortest path:" << endl;
    flightGraph.dijkstra("Delhi", "Chennai");

    return 0;
}