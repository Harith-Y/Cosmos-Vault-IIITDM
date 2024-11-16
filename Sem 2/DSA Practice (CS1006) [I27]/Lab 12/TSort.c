#include <stdio.h>
#include <stdlib.h>


void Add_Edge(int graph[10][10], int start, int end) {
    graph[start][end] = 1;
}

void Sub_TSort(int graph[10][10], int current_vertex, int visited[10], int stack[10], int *stack_index) {
    visited[current_vertex] = 1;

    for (int i = 0; i < 10; i++) {
        if (graph[current_vertex][i] && !visited[i]) {
            Sub_TSort(graph, i, visited, stack, stack_index);
        }
    }    
    
    stack[(*stack_index)++] = current_vertex;
}

void TSort(int graph[10][10], int vertices) {
    int visited[10] = {0};
    int stack[10];
    int stack_index = 0;
    
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            Sub_TSort(graph, i, visited, stack, &stack_index);
        }
    }
    
    printf("Topological Sorting : ");
    while (stack_index > 0)
        printf("%d ", stack[--stack_index]);
}

void main() {
    int i, vertices, edges;
    
    printf("Please Enter the number of Vertices : ");
    scanf(" %d", &vertices);
    printf("Please Enter the number of Edges : ");
    scanf(" %d", &edges);
    
    int graph[10][10] = {0};
    int start, end;
    
    while (i < edges) {
        printf("Please enter the starting vertex and ending vertex");
        scanf(" %d %d", &start, &end);
        Add_Edge(graph, start, end);
        i++;
    }
    
    TSort(graph, vertices);
}