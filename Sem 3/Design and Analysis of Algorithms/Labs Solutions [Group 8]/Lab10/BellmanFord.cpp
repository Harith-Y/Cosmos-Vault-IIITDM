//Time Complexity: O(V*E) i.e. O(n^3), But O(V^3) for dense graphs and O(V^2) for sparse graphs
#include <iostream>
#include <climits>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int source;
    int destination;
    int weight;
};

class Graph {
    private: int V;  // Number of vertices
    private: int E;  // Number of edges
    private: Edge* edges;  // Array of edges
    private: int currentEdge;  // To keep track of number of edges added

    // Constructor
    public: Graph(int vertices, int edgeCount) {
        V = vertices;
        E = edgeCount;
        edges = new Edge[E];  // Dynamically allocate array of edges
        currentEdge = 0;  // Initialize edge counter
    }

    // Destructor to free allocated memory
    public: ~Graph() {
        delete[] edges;
    }

    // Function to add an edge to the graph
    public: void addEdge(int src, int dest, int weight) {
        if (currentEdge < E) {
            edges[currentEdge].source = src;
            edges[currentEdge].destination = dest;
            edges[currentEdge].weight = weight;
            currentEdge++;
        }
        else
            cout << "Cannot add more edges, graph is full!" << endl;
    }

    // Utility function to print the solution
    public: void printSolution(int dist[]) {
        cout << "Vertex Distance from Source\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX)
                cout << i << "\t\tINF" << endl;
            else
                cout << i << "\t\t" << dist[i] << endl;
        }
    }

    // Main Bellman-Ford algorithm implementation, Time complexity: O(V + V*E + E) = O(V*E)
    public: bool bellmanFord(int source) {
        // Step 1: Initialize distances
        int* distance = new int[V];
        for (int i = 0; i < V; i++)
            distance[i] = INT_MAX;

        distance[source] = 0;

        // Step 2: Relax all edges |V| - 1 times
        for (int i = 1; i <= V - 1; i++) {
            for (int j = 0; j < E; j++) {
                int u = edges[j].source;
                int v = edges[j].destination;
                int weight = edges[j].weight;

                // Relaxation step
                if ((distance[u] != INT_MAX) && (distance[u] + weight < distance[v]))
                    distance[v] = distance[u] + weight;
            }
        }

        // Step 3: Check for negative weight cycles
        for (int i = 0; i < E; i++) {
            int u = edges[i].source;
            int v = edges[i].destination;
            int weight = edges[i].weight;

            if ((distance[u] != INT_MAX) && (distance[u] + weight < distance[v])) {
                cout << "Graph contains negative weight cycle!" << endl;
                delete[] distance;  // Clean up before returning
                return false;
            }
        }

        // Print the solution
        printSolution(distance);

        // Clean up allocated memory
        delete[] distance;
        return true;
    }
};

int main() {
    // Create a graph with 4 vertices and 8 edges
    Graph g(4, 8);

    g.addEdge(0, 1, 1);  // Edge from vertex 0 to 1 with weight 1
    g.addEdge(0, 2, 3);  // Edge from vertex 0 to 2 with weight 3
    g.addEdge(1, 2, 2);  // Edge from vertex 1 to 2 with weight 2
    g.addEdge(1, 3, 2);  // Edge from vertex 1 to 3 with weight 2
    g.addEdge(2, 3, 4);  // Edge from vertex 2 to 3 with weight 4
    g.addEdge(3, 2, 5);  // Edge from vertex 3 to 2 with weight 5
    g.addEdge(0, 3, 6);  // Edge from vertex 0 to 3 with weight 6
    g.addEdge(2, 1, -2); // Edge from vertex 2 to 1 with weight -2

    // Run Bellman-Ford algorithm from vertex 0
    g.bellmanFord(0);

    return 0;
}