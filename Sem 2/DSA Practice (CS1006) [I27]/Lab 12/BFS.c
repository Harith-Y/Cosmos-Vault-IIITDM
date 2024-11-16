#include <stdio.h>
#include <stdlib.h>

struct Adjacency_List_Node {
    int vertex;
    struct Adjacency_List_Node *next;
};

struct Adjacency_List {
    struct Adjacency_List_Node *head;
};

struct graph {
    int num_of_vertices;
    struct Adjacency_List *Array;
};

struct Adjacency_List_Node *New_Adjacency_List_Node(int end) {
    struct Adjacency_List_Node *new_node;
    new_node = (struct Adjacency_List_Node *) malloc(sizeof(struct Adjacency_List_Node));
    
    new_node -> vertex = end;
    new_node -> next = NULL;
    
    return new_node;
    
}

struct graph *Create_Graph(int no_of_vertices) {
    int i;
    struct graph *Graph = (struct graph *) malloc(sizeof(struct graph));
    Graph -> num_of_vertices = no_of_vertices;
    Graph -> Array = (struct Adjacency_List *) malloc (no_of_vertices * sizeof(struct Adjacency_List));

    for (i = 0; i < no_of_vertices; i++)
        Graph -> Array[i].head = NULL;
    
    return Graph;
    
}

void Add_Edge(struct graph *Graph, int start, int end) {
    struct Adjacency_List_Node *new_node;
    new_node = New_Adjacency_List_Node(end);
    new_node -> next = Graph -> Array[start].head;
    Graph -> Array[start].head = new_node;
    
    new_node = New_Adjacency_List_Node(start);
    new_node -> next = Graph -> Array[end].head;
    Graph -> Array[end].head = new_node;
}

void Sub_DFS(int vertex, struct graph *Graph, int visited_array[]) {
    visited_array[vertex] = 1;
    printf("%d", vertex);
    
    struct Adjacency_List_Node *temp = Graph -> Array[vertex].head;
    while (temp != NULL) {
        if (!visited_array[temp -> vertex])
            Sub_DFS(temp -> vertex, Graph, visited_array);
            
        temp = temp -> next;
    }
}

void DFS(struct graph *Graph, int initial_vertex) {
    
    int visited[10] = {0};
    
    Sub_DFS(initial_vertex, Graph, visited);
}

int main() {
    int number_of_vertices, number_of_edges, initial, i = 0, start_vertex, end_vertex;
    printf("Please Enter the Number of Vertices : ");
    scanf(" %d", &number_of_vertices);
    
    struct graph *Graph = Create_Graph(number_of_vertices);
    
    printf("Please Enter the number of Edges : ");
    scanf(" %d", &number_of_edges);
    
    printf("Please Enter the Initial Vertex from which DFS should start : ");
    scanf(" %d", &initial);
    
    printf("Please Enter the Starting and Ending vertices of the edges : \n");
    while (i < number_of_edges) {
        scanf(" %d %d", &start_vertex, &end_vertex);
        Add_Edge(Graph, start_vertex, end_vertex);
        i++;
    }

    printf("DFS Traversal : ");
    DFS(Graph, initial);
    
    return 0;
}
