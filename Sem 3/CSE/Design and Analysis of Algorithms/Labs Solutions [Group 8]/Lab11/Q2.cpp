#include <iostream>
#include <vector>
#include <fstream>
#include <limits.h> // For INT_MAX

using namespace std;

class TSP {
public:
    int n; // number of cities
    vector<vector<int>> matrix; // adjacency matrix for distances
    vector<bool> visited; // to track visited cities
    
    int totalDistance; // to store the total travel distance

    void fill_matrix();
    int travel(int s);
    
};

void TSP::fill_matrix() {
    ifstream p("eil51.tsp");
    int no;
    p >> no; // Read number of cities (nodes)
    
    // Resize matrix to n x n (adjacency matrix)
    matrix.resize(n, vector<int>(n, 0));

    // Fill in the matrix with distances
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p >> matrix[i][j];
        }
    }
    p.close();
}

int TSP::travel(int s) {
    visited[s] = true; // mark city as visited
   
    int minDist = INT_MAX; // initialize minDist to a large number
    int nextCity = -1; // variable to store the next city to visit

    // Try visiting all unvisited cities and choose the closest
    for (int i = 0; i < n; i++) {
        if (!visited[i] && matrix[s][i] < minDist) {
            minDist = matrix[s][i];
            nextCity = i;
        }
    }

    if (nextCity != -1) 
    {
        totalDistance += minDist; // add the distance to the total
        cout << "--" << minDist << "-->" << nextCity << endl;
        return travel(nextCity); // recurse to the next city
    } 
    else 
    {
       
        return s; // return to the starting city
    }
}

int main() 
{
    TSP a;
    ifstream p("eil51.tsp");
    p >> a.n; 
    p.close();
    a.visited.assign(a.n, false); // reset visited cities
   
    a.totalDistance = 0; // reset total distance
    // Fill matrix with distance data
    a.fill_matrix();

    // Start traveling from city 0
    int start = 0;
    cout << "Starting TSP traversal from city " << start << endl;
    int end=a.travel(start);
    cout << "--" << a.matrix[end][start] << "-->" << start << endl;
    a.totalDistance += a.matrix[end][start];
    cout << "Total distance traveled: " << a.totalDistance << endl;
    return 0;
}

