#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph flightGraph;

    // Adding sample edges
    flightGraph.addEdge("Delhi", "Mumbai", 1500.5);
    flightGraph.addEdge("Mumbai", "Chennai", 1200.0);
    flightGraph.addEdge("Delhi", "Kolkata", 2000.75);
    flightGraph.addEdge("Kolkata", "Chennai", 1700.25);

    // Printing the graph
    cout << "Flight Routes:" << endl;
    flightGraph.printGraph();

    cout << "\nChoose an algorithm to find the shortest path:" << endl;
    cout << "1. Dijkstra's Algorithm" << endl;
    cout << "2. Bellman-Ford Algorithm" << endl;
    cout << "Enter your choice (1 or 2): ";

    int choice;
    cin >> choice;

    string source, destination;
    if (choice == 1) {
        cout << "Enter source and destination for Dijkstra's Algorithm: ";
        cin >> source >> destination;
        cout << "\nFinding shortest path using Dijkstra's Algorithm:" << endl;
        flightGraph.dijkstra(source, destination);
    } else if (choice == 2) {
        cout << "Enter source and destination for Bellman-Ford Algorithm: ";
        cin >> source >> destination;
        cout << "\nFinding shortest path using Bellman-Ford Algorithm:" << endl;
        flightGraph.bellmanFord(source, destination);
    } else {
        cout << "Invalid choice. Exiting program." << endl;
    }

    return 0;
}
