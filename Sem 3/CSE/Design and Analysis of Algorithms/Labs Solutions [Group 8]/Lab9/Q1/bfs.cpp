#include <iostream>
using namespace std;
#define MAX 100
#include <math.h>
#include <time.h>


void addEdge(int adj[MAX][MAX], int u, int v)
{
    adj[u][v] = 1;
}

void bfsChoice(int adj[MAX][MAX], int v, int s) // this is our Breadth First Search Function - we pass in the adjacency matrix, the number of vertices and the start node of the bfs
{
    int queue[MAX], front = 0, rear = 0; // we initialize a queue, and make its front = rear = 0
    int visited[MAX] = {0}; // none of the nodes of the graphs are visited, so make their respective truth values 0
    visited[s] = 1; // you start the BFS at a source s, so make s visited
    queue[rear++] = s; // add s to the queue

    while(rear > front)
    {
        int current = queue[front++]; // the front fellow is the current node
        cout << current << endl; // print the node that you are at

        for(int i = 0; i < v; i++)
        {
            if(adj[current][i] == 1 && visited[i] != 1) // in the adjacency matrix, check if there exists any edge from the current node to another node. if yes & if that node hasnt been visited, add that node to the queue (make its visited 1)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void bfsArb(int adj[MAX][MAX], int v) // this is our Breadth First Search Function - we pass in the adjacency matrix and the number of vertices
{
    int queue[MAX], front = 0, rear = 0; // we initialize a queue, and make its front = rear = 0
    int visited[MAX] = {0}; // none of the nodes of the graphs are visited, so make their respective truth values 0
    srand(time(0));
    int s = rand() % v; // randomly generate the source
    visited[s] = 1; // you start the BFS at a source s, so make s visited
    queue[rear++] = s; // add s to the queue

    while(rear > front)
    {
        int current = queue[front++]; // the front fellow is the current node
        cout << current << endl; // print the node that you are at

        for(int i = 0; i < v; i++)
        {
            if(adj[current][i] == 1 && visited[i] != 1) // in the adjacency matrix, check if there exists any edge from the current node to another node. if yes & if that node hasnt been visited, add that node to the queue (make its visited 1)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

void isReachable(int adj[MAX][MAX], int v, int start, int end) // this is our isReachable - we pass in the adjacency matrix, the number of vertices, the start node of the bfs and the end node to be reached
{
    int queue[MAX], front = 0, rear = 0; // we initialize a queue, and make its front = rear = 0
    int visited[MAX] = {0}; // none of the nodes of the graphs are visited, so make their respective truth values 0
    visited[start] = 1; // you start the BFS at a source s, so make s visited
    queue[rear++] = start; // add s to the queue

    while(rear > front)
    {
        int current = queue[front++]; // the front fellow is the current node
        cout << current << endl; // print the node that you are at

        for(int i = 0; i < v; i++)
        {
            if(adj[current][i] == 1 && visited[i] != 1) // in the adjacency matrix, check if there exists any edge from the current node to another node. if yes & if that node hasnt been visited, add that node to the queue (make its visited 1)
            {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    
    if(!visited[end])
	{
		cout << end << " not reachable from " << start << endl;
	}
	else
	{
		cout << end << " reachable from " << start << endl;
	}
}

int main()
{
    int numVertices = 5;
    int adj[MAX][MAX] = {0};

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 4);

    cout << "BFS starting from 0: " << endl;
    bfsChoice(adj, numVertices, 0);
    cout << endl;
    
    cout << "BFS starting from an arbitrary location: " << endl;
    bfsArb(adj, numVertices);
    cout << endl;
    
    isReachable(adj, numVertices, 0, 3);
    isReachable(adj, numVertices, 0, 4);
    
    return 0;
}
