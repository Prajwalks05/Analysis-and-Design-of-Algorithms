
/*207. Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.*/

#include <stdio.h>
#include <stdlib.h>

#define WHITE 0  // Unvisited
#define GREY 1   // Explore incomplete
#define BLACK 2  // Fully explored 

// Function for depth-first search
int dfs(int node, int** graph, int* visited, int numCourses) {
    visited[node] = GREY;
    
    // Go through all parent nodes (prerequisite courses)
    for (int j = 0; j < numCourses; j++) {
        if (graph[node][j] == 1) {
            // If we end up in an already being explored node, it is a cycle
            if (visited[j] == GREY) {
                return 0;  // Cycle detected
            }
            
            // Explore unvisited node
            if (visited[j] == WHITE) {
                if (!dfs(j, graph, visited, numCourses)) {
                    return 0;  // Cycle detected
                }
            }
        }
    }

    visited[node] = BLACK;
    return 1;  // No cycle detected
}

// Function to check if it is possible to finish all courses
int canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    // Create graph as adjacency matrix
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(numCourses * sizeof(int));
        for (int j = 0; j < numCourses; j++) {
            graph[i][j] = 0;  // Initialize the graph with 0
        }
    }
    
    // Populate graph from prerequisites
    for (int i = 0; i < prerequisitesSize; i++) {
        graph[prerequisites[i][0]][prerequisites[i][1]] = 1;
    }

    // Visited array to track the state of each node (course)
    int* visited = (int*)malloc(numCourses * sizeof(int));
    for (int i = 0; i < numCourses; i++) {
        visited[i] = WHITE;  // Initialize all nodes as unvisited
    }
    
    // Run DFS for each unvisited course
    for (int i = 0; i < numCourses; i++) {
        if (visited[i] == WHITE) {
            if (!dfs(i, graph, visited, numCourses)) {
                // If a cycle is detected, return false
                free(visited);
                for (int j = 0; j < numCourses; j++) {
                    free(graph[j]);
                }
                free(graph);
                return 0;
            }
        }
    }
    
    // No cycle detected, return true
    free(visited);
    for (int j = 0; j < numCourses; j++) {
        free(graph[j]);
    }
    free(graph);
    
    return 1;
}
