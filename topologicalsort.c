#include<stdio.h>
#include<stdlib.h>
#define max 10

int stack[max];
int top = -1;

void dfs(int graph[max][max], int visited[max], int vertex, int vertices)
{
    visited[vertex] = 1;
    for (int i = 0; i < vertices; i++)
    {
        if (graph[vertex][i] == 1 && !visited[i])
        {
            dfs(graph, visited, i, vertices);
        }
    }
    stack[++top] = vertex;
}
void topological(int graph[max][max], int vertices)
{
    int visited[max] = {0};
    for (int i = 0; i < vertices; i++)
    {
        if (!visited[i])
        {
            dfs(graph, visited, i, vertices);
        }
    }
    printf("\nTopological sort: ");
    while (top != -1)
    {
        printf("%d ", stack[top--]);
    }
    printf("\n");
}
int main()
{
    int graph[max][max] = {0};
    int vertices, edges, u, v;
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
    }
    topological(graph, vertices);
    return 0;
}
