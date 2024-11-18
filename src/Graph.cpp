#include "Graph.h"
#include <algorithm>


// Add an edge to the graph
void Graph::addEdge(const string& source, const string& destination, double weight) {
    adjList[source].push_back({destination, weight});
    adjList[destination].push_back({source, weight}); // For undirected graph
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

// Dijkstra's Algorithm (using distance vector and priority queue)
void Graph::dijkstra(const string& source, const string& destination) {
    unordered_map<string, double> distances;
    unordered_map<string, string> parent;
    unordered_map<string, bool> visited;
    
    // Priority queue (min-heap) to store {distance, node}
    priority_queue<pair<double, string>, vector<pair<double, string>>, greater<pair<double, string>>> pq;

    // Initialize distances to infinity and visited to false
    for (const auto& node : adjList) {
        distances[node.first] = numeric_limits<double>::infinity();
        visited[node.first] = false;
    }

    // Initialize source node
    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        // Get the node with the smallest distance
        string currentNode = pq.top().second;
        double currentDistance = pq.top().first;
        pq.pop();

        // Mark as visited
        if (visited[currentNode]) continue;
        visited[currentNode] = true;

        // Traverse neighbors
        for (const auto& neighbor : adjList[currentNode]) {
            const string& nextNode = neighbor.first;
            double edgeWeight = neighbor.second;

            // Relaxation step
            if (!visited[nextNode] && currentDistance + edgeWeight < distances[nextNode]) {
                distances[nextNode] = currentDistance + edgeWeight;
                pq.push({distances[nextNode], nextNode});
                parent[nextNode] = currentNode;
            }
        }
    }

    // Output the shortest path
    cout << "Shortest path from " << source << " to " << destination << ":" << endl;

    if (distances[destination] == numeric_limits<double>::infinity()) {
        cout << "No path exists." << endl;
        return;
    }

    vector<string> path;
    string temp = destination;

    while (temp != source) {
        path.push_back(temp);
        temp = parent[temp];
    }
    path.push_back(source);

    // Reverse and print the path
    reverse(path.begin(), path.end());
    for (const auto& node : path) {
        cout << node << " ";
    }
    cout << endl;

    cout << "Total cost: " << distances[destination] << endl;
}
