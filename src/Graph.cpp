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

void Graph::bellmanFord(const string& source, const string& destination) {
    unordered_map<string, double> distances;
    unordered_map<string, string> parent;

    // Initialize distances to infinity and parent to empty
    for (const auto& node : adjList) {
        distances[node.first] = numeric_limits<double>::infinity();
        parent[node.first] = "";
    }
    distances[source] = 0; // Distance to source is 0

    // Relax all edges |V| - 1 times
    for (size_t i = 1; i < adjList.size(); ++i) {
        for (const auto& node : adjList) {
            for (const auto& neighbor : node.second) {
                const string& u = node.first;
                const string& v = neighbor.first;
                double weight = neighbor.second;

                if (distances[u] != numeric_limits<double>::infinity() &&
                    distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    parent[v] = u;
                }
            }
        }
    }

    // Check for negative weight cycles
    for (const auto& node : adjList) {
        for (const auto& neighbor : node.second) {
            const string& u = node.first;
            const string& v = neighbor.first;
            double weight = neighbor.second;

            if (distances[u] != numeric_limits<double>::infinity() &&
                distances[u] + weight < distances[v]) {
                cout << "Graph contains a negative weight cycle!" << endl;
                return;
            }
        }
    }

    // Output the shortest path to the destination
    cout << "Shortest path from " << source << " to " << destination << ":" << endl;

    if (distances[destination] == numeric_limits<double>::infinity()) {
        cout << "No path exists." << endl;
        return;
    }

    vector<string> path;
    string temp = destination;

    while (temp != source && temp != "") {
        path.push_back(temp);
        temp = parent[temp];
    }
    if (temp == "") {
        cout << "No path exists." << endl;
        return;
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
