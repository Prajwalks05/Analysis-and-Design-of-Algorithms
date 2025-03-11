#include <stdio.h>
#include <stdlib.h>

// Function to perform DFS and find topological sort
void dfs(int node, int n, int graph[n][n], int visited[n], int stack[n], int *top) {
    visited[node] = 1;  // Mark node as visited

    // Recurse for all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, n, graph, visited, stack, top);
        }
    }

    // Push the current node to the stack after all adjacent nodes are visited
    stack[(*top)++] = node;
}

// Function to perform topological sort using DFS
void topologicalSort(int n, int graph[n][n]) {
    int visited[n];  // Array to track visited nodes
    int stack[n];    // Stack to store topological order
    int top = 0;     // Stack index

    // Initialize visited array
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    // Perform DFS for each unvisited node
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, n, graph, visited, stack, &top);
        }
    }

    // Print the topological sort in reverse order (last-in, first-out)
    printf("Topological Sort: ");
    for (int i = top - 1; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Read number of nodes
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    int graph[n][n]; // Adjacency matrix

    // Read the adjacency matrix
    printf("Enter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    // Perform topological sort
    topologicalSort(n, graph);

    return 0;
}
