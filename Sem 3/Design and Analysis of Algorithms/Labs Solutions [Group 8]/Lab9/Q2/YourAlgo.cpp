//Time Complexity : O(V^2 * E^2)

#include <iostream>
#include <climits>

#define V 100 // maximum number of vertices

using namespace std;

class Graph {
    private:
        int graph[V][V];
        int vertices;

    public:
        // Time complexity: O(V^2)
        Graph(int v) {
            vertices = v;
            for (int i = 0; i < v; i++)
                for (int j = 0; j < v; j++)
                    graph[i][j] = 0;
        }

        // Time complexity: O(1)
        void addEdge(int src, int dest, int weight) {
            if (src >= 0 && src < vertices && dest >= 0 && dest < vertices) {
                graph[src][dest] = weight;
                graph[dest][src] = weight;
            }
            else
                cout << "Invalid input" << endl;
        }

        // Time complexity: O(V^2)
        void printGraph() {
            cout << "The Adjacency Matrix is as follows: " << endl;

            for (int i = 0; i < vertices; i++) {
                for (int j = 0; j < vertices; j++)
                    cout << graph[i][j] << " ";

                cout << endl;
            }
        }

        void printMST(int mst[][2], int edgeCount) {
            int totalWeight = 0;
            cout << "Minimum Spanning Tree Edges: " << endl;
            cout << "Edge Weight" << endl;
            for (int i = 0; i < edgeCount; i++) {
                cout << mst[i][0] << " - " << mst[i][1] << " " << graph[mst[i][0]][mst[i][1]] << endl;
                totalWeight += graph[mst[i][0]][mst[i][1]];
            }
            cout << "Total Weight of MST = " << totalWeight << endl;
        }

        bool isConnected() {
            bool visited[V] = {false};
            dfs(0, visited);
            for (int i = 0; i < vertices; i++) {
                if (!visited[i]) return false;
            }
            return true;
        }

        void dfs(int v, bool visited[]) {
            visited[v] = true;
            for (int i = 0; i < vertices; i++) {
                if (graph[v][i] != 0 && !visited[i]) {
                    dfs(i, visited);
                }
            }
        }

        // Time complexity: O(V^2 * E^2)
        void reverseDeleteAlgo() {
            int edges[V * (V - 1) / 2][3];
            int edgeCount = 0;

            for (int u = 0; u < vertices; u++) {
                for (int v = u + 1; v < vertices; v++) {
                    if (graph[u][v] != 0) {
                        edges[edgeCount][0] = graph[u][v];
                        edges[edgeCount][1] = u;
                        edges[edgeCount][2] = v;
                        edgeCount++;
                    }
                }
            }

            // Time complexity : O(E^2)
            for (int i = 0; i < edgeCount - 1; i++) {
                for (int j = 0; j < edgeCount - i - 1; j++) {
                    if (edges[j][0] < edges[j + 1][0]) {
                        int temp[3];
                        temp[0] = edges[j][0];
                        temp[1] = edges[j][1];
                        temp[2] = edges[j][2];
                        edges[j][0] = edges[j + 1][0];
                        edges[j][1] = edges[j + 1][1];
                        edges[j][2] = edges[j + 1][2];
                        edges[j + 1][0] = temp[0];
                        edges[j + 1][1] = temp[1];
                        edges[j + 1][2] = temp[2];
                    }
                }
            }

            int mst[V - 1][2];
            int mstEdgeCount = 0;

            // Time Complexity : O((E^2)*(V^2))
            for (int i = 0; i < edgeCount; i++) {
                int u = edges[i][1];
                int v = edges[i][2];

                graph[u][v] = 0;
                graph[v][u] = 0;

                if (!isConnected()) {
                    graph[u][v] = edges[i][0];
                    graph[v][u] = edges[i][0];
                    mst[mstEdgeCount][0] = u;
                    mst[mstEdgeCount][1] = v;
                    mstEdgeCount++;
                }
            }

            printMST(mst, mstEdgeCount);
        }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    g.reverseDeleteAlgo();

    return 0;
}