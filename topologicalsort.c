#include <stdio.h>
#include <stdlib.h>

// Function to perform DFS and find topological sort
void dfs(int node, int **graph, int *visited, int *stack, int *top, int vertices) {
    // Mark the node as visited
    visited[node] = 1;

    // Recurse for all the adjacent vertices of the current node
    for (int i = 0; i < vertices; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, graph, visited, stack, top, vertices);
        }
    }

    // Push the current node to the stack after all adjacent nodes are visited
    stack[(*top)++] = node;
}

// Function to perform topological sort using DFS
void topologicalSort(int vertices, int **graph) {
    int *visited = (int *)calloc(vertices, sizeof(int)); // Initialize all nodes as unvisited
    int *stack = (int *)malloc(vertices * sizeof(int));  // To store the topological order
    int top = 0;                                        // Index to insert in stack

    // Perform DFS for each unvisited node
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited, stack, &top, vertices);
        }
    }

    // Print the topological sort by popping elements from the stack
    printf("Topological Sort: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");

    // Free allocated memory
    free(visited);
    free(stack);
}

int main() {
    int vertices;
    
    // Read number of vertices
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    
    // Dynamically allocate memory for the adjacency matrix
    int **graph = (int **)malloc(vertices * sizeof(int *));
    for (int i = 0; i < vertices; i++) {
        graph[i] = (int *)malloc(vertices * sizeof(int)); // Allocate memory for each row
    }
    
    // Read the adjacency matrix
    printf("Enter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);  // Fill the adjacency matrix
        }
    }

    // Perform topological sort
    topologicalSort(vertices, graph);
    
    // Free allocated memory for the graph
    for (int i = 0; i < vertices; i++) {
        free(graph[i]);
    }
    free(graph);
    
    return 0;
}
