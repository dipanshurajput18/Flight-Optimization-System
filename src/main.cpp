#include <iostream>
#include "Graph.h"

int main() {
    Graph flightGraph;

    // Adding sample edges
    flightGraph.addEdge("Delhi", "Mumbai", 1500.5);
    flightGraph.addEdge("Mumbai", "Chennai", 1200.0);
    flightGraph.addEdge("Delhi", "Kolkata", 2000.75);

    // Printing the graph
    std::cout << "Flight Routes:" << std::endl;
    flightGraph.printGraph();

    return 0;
}
