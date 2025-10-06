//Time Complexity: O(V^2), i.e. O(n^2)
#include <iostream>
#include <climits>

using namespace std;

class Graph {
private:
    int V;          // Number of vertices
    int** graph;    // Adjacency matrix representation
    
public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        
        // Allocate memory for adjacency matrix
        graph = new int*[V];
        for (int i = 0; i < V; i++) {
            graph[i] = new int[V];
            // Initialize all edges as 0 (no connection)
            for (int j = 0; j < V; j++)
                graph[i][j] = 0;
        }
    }
    
    // Destructor to free allocated memory
    ~Graph() {
        for (int i = 0; i < V; i++)
            delete[] graph[i];
    
        delete[] graph;
    }
    
    // Function to add an edge to the graph
    void addEdge(int source, int destination, int weight) {
        if ((source >= 0) && (source < V) && (destination >= 0) && (destination < V)) {
            graph[source][destination] = weight;
            // Remove this line if directed graph is needed
            graph[destination][source] = weight;  // For undirected graph
        }
    }
    
    // Utility function to find vertex with minimum distance
    int minDistance(int dist[], bool visited[]) {
        int min = INT_MAX;
        int min_index = -1;
        
        for (int v = 0; v < V; v++) {
            if ((!visited[v]) && (dist[v] <= min)) {
                min = dist[v];
                min_index = v;
            }
        }
        return min_index;
    }
    
    // Utility function to print the solution
    void printSolution(int dist[], int parent[]) {
        cout << "Vertex \t Distance from Source \t Path" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << "\t\t" << dist[i] << "\t\t ";
            printPath(parent, i);
            cout << endl;
        }
    }
    
    // Utility function to print the path from source to current vertex
    void printPath(int parent[], int j) {
        // Base Case: If j is source
        if (parent[j] == -1) {
            cout << j;
            return;
        }
        printPath(parent, parent[j]);
        cout << " -> " << j;
    }
    
    // Main Dijkstra's algorithm implementation, Time Complexity: O(V + V^2 + V^2) = O(V^2)
    void dijkstra(int source) {
        // Arrays to store shortest path tree
        int* dist = new int[V];     // Distance array
        bool* visited = new bool[V]; // Visited array
        int* parent = new int[V];    // Parent array for path reconstruction
        
        // Initialize all distances as infinite and visited[] as false
        for (int i = 0; i < V; i++) {
            dist[i] = INT_MAX;
            visited[i] = false;
            parent[i] = -1;
        }
        
        // Distance of source vertex from itself is always 0
        dist[source] = 0;
        
        // Find shortest path for all vertices
        for (int count = 0; count < V - 1; count++) {
            // Pick the minimum distance vertex from the unvisited set
            int u = minDistance(dist, visited);
            
            // Mark the picked vertex as visited
            visited[u] = true;
            
            // Update dist[] value of adjacent vertices
            for (int v = 0; v < V; v++) {
                // Update dist[v] only if:
                // 1. There is an edge from u to v
                // 2. Vertex v is not visited
                // 3. Total weight of path from source to v through u is less than current value of dist[v]
                if((!visited[v]) && (graph[u][v] != 0) && (dist[u] != INT_MAX) && (dist[u] + graph[u][v] < dist[v])) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;  // Update parent for path reconstruction
                }
            }
        }
        
        // Print the solution
        printSolution(dist, parent);
        
        // Clean up
        delete[] dist;
        delete[] visited;
        delete[] parent;
    }
};

int main() {
    // Create a graph with 6 vertices
    Graph g(6);
    
    g.addEdge(0, 1, 8);
    g.addEdge(0, 2, 2);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 4, 6);
    g.addEdge(3, 5, 7);
    g.addEdge(4, 5, 5);
    
    cout << "Shortest paths from vertex 0:" << endl;
    g.dijkstra(0);
    
    return 0;
}