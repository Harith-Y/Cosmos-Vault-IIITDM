#include <iostream>
using namespace std;
#define MAX 100
#include <math.h>
#include <time.h>


class Graph
{
    public:
        int adjMatrix[MAX][MAX];
        int numNodes;
        int arbitrary;

        Graph(int n)
        {
            numNodes = n;
            srand(time(0));
            arbitrary = rand() % numNodes;
            
            for(int i = 0; i < numNodes; i++)
            {
                for(int j = 0; j < numNodes; j++)
                {
                    adjMatrix[i][j] = 0;
                }
            }
        }

        void addEdge(int u, int v)
        {
            adjMatrix[u][v] = 1;
        }

        void dfsChoice(int start)
        {
            int visited[MAX] = {0};
            int stack[MAX];
            int top = -1;

            visited[start] = 1;
            stack[++top] = start;

            while(top != -1)
            {
                int node = stack[top--];
                cout << node << endl;

                for(int i = 0; i < numNodes; i++)
                {
                    if(adjMatrix[node][i] == 1 && visited[i] != 1)
                    {
                        visited[i] = 1;
                        stack[++top] = i;
                    }
                }
            }
        }
        
        void dfsArb()
        {
            int visited[MAX] = {0};
            int stack[MAX];
            int top = -1;

            visited[arbitrary] = 1;
            stack[++top] = arbitrary;

            while(top != -1)
            {
                int node = stack[top--];
                cout << node << endl;

                for(int i = 0; i < numNodes; i++)
                {
                    if(adjMatrix[node][i] == 1 && visited[i] != 1)
                    {
                        visited[i] = 1;
                        stack[++top] = i;
                    }
                }
            }
        }
        
        void isReachable(int start, int end)
        {
            int visited[MAX] = {0};
            int stack[MAX];
            int top = -1;

            visited[start] = 1;
            stack[++top] = start;

            while(top != -1)
            {
                int node = stack[top--];
                for(int i = 0; i < numNodes; i++)
                {
                    if(adjMatrix[node][i] == 1 && visited[i] != 1)
                    {
                        visited[i] = 1;
                        stack[++top] = i;
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
        
};


int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "DFS Traversal (Choice): " << endl;
    g.dfsChoice(0);
    cout << endl;
	
	cout << "DFS Traversal (Arbitrary): " << endl;
    g.dfsArb();
    cout << endl;
    
    g.isReachable(0, 3);
    g.isReachable(4, 2);
    


    return 0;
}
