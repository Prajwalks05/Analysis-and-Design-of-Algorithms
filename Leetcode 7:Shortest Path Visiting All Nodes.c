/*
847. Shortest Path Visiting All Nodes
You have an undirected, connected graph of n nodes labeled from 0 to n - 1. You are given an array graph where graph[i] is a list of all the nodes connected with node i by an edge.
Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 12
#define MAX_MASK (1 << MAX_N)

typedef struct {
    int node;
    int mask;
    int steps;
} State;

int shortestPathLength(int** graph, int graphSize, int* graphColSize) {
    int allVisited = (1 << graphSize) - 1;

    // Queue for BFS
    State queue[MAX_N * MAX_MASK];
    int front = 0, back = 0;

    // Visited array
    bool visited[MAX_N][MAX_MASK];
    memset(visited, 0, sizeof(visited));

    // Initialize BFS with all nodes as starting points
    for (int i = 0; i < graphSize; ++i) {
        int mask = 1 << i;
        queue[back++] = (State){i, mask, 0};
        visited[i][mask] = true;
    }

    // BFS loop
    while (front < back) {
        State curr = queue[front++];

        if (curr.mask == allVisited) {
            return curr.steps;
        }

        for (int i = 0; i < graphColSize[curr.node]; ++i) {
            int neighbor = graph[curr.node][i];
            int nextMask = curr.mask | (1 << neighbor);

            if (!visited[neighbor][nextMask]) {
                visited[neighbor][nextMask] = true;
                queue[back++] = (State){neighbor, nextMask, curr.steps + 1};
            }
        }
    }

    return -1;  // Should never reach here
}
