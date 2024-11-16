#include <iostream>

using namespace std;

struct G {
    int start;
    int end;
    int weight;
};


void bubbleSort(G arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].weight > arr[j + 1].weight) {
                G temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n; // Number of vertices
    cout << "ENTER THE NO OF VERTICES" << endl;
    cin >> n;
    int graph[n][n]; // Adjacency matrix

    cout << "ENTER THE MATRIX" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    G edges[n * n]; // Array to store all edges
    int k = 0; // Number of edges

    // Populate edges array from adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) { // Only one direction for undirected graph
            if (graph[i][j] > 0) {
                edges[k].start = i;
                edges[k].end = j;
                edges[k].weight = graph[i][j];
                k++;
            }
        }
    }

    bubbleSort(edges, k);

    bool visited[n] = {false}; 
    int MST[n - 1][3]; 
    int t = 0;         

    for (int i = 0; i < k && t < n - 1; i++) {
        int u = edges[i].start;
        int v = edges[i].end;

        if (!(visited[u] && visited[v])) {
            MST[t][0] = u;
            MST[t][1] = v;
            MST[t][2] = edges[i].weight;
            visited[u] = true;
            visited[v] = true;
            t++;
        }
    }

    cout << "MST" << endl;
    for (int i = 0; i < t; i++) {
        cout << MST[i][0] << "-" << MST[i][1] << ": Weight:" << MST[i][2] << endl;
    }

    return 0;
}
