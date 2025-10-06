#include <iostream>
using namespace std;
#define INF 9999999
#define size 100
void prims(int selected[size],int G[size][size],int V);
int main()
{
  int G[size][size];
  int V;
  cout<<"ENTER THE NUMBER OF VERTICES"<<endl;
  cin>>V;
  cout<<"ENTER THE MATRIX"<<endl;
  for(int i=0;i<V;i++)
  {
  	for(int j=0;j<V;j++)
  	{
  	 cin>>G[i][j];
  	}
  }
  int selected[size]={0};//array to keep track of visited node
  prims(selected,G,V);
  return 0;
}
 
  
void prims(int selected[size],int G[size][size],int V)
{
 
  // set number of edge to 0
  int no_edge = 0;

  // the number of egde in minimum spanning tree will be always less than (V -1), where V is number of vertices in graph


  // choose 0th vertex and make it true
  selected[0] = 1;

  int x;  //  row number
  int y;  //  col number

  // print for edge and weight
  cout << "Edge"
     << " : "
     << "Weight";
  cout << endl;
  while (no_edge < V - 1) 
  {
    //For every vertex in the set S, find the all adjacent vertices, calculate the distance from the vertex selected at step 1.
    // if the vertex is already in the set S, discard it otherwise choose another vertex nearest to selected vertex  at step 1.

    int min = INF;
    x = 0;
    y = 0;

    for (int i = 0; i < V; i++) 
    {
      	if (selected[i]) 
     	 {
        		for (int j = 0; j < V; j++) 
        		{
          		if (!selected[j] && G[i][j]) 
          		{  // not in selected and there is an edge
            			if (min > G[i][j]) 
            			{
					    min = G[i][j];
					    x = i;
					    y = j;
		      		}
		     	}
		     }	
		 }
	}
    cout << x << " - " << y << " :  " << G[x][y];
    cout << endl;
    selected[y] = 1;
    no_edge++;
  }
}
