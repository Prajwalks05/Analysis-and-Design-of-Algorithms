#include <stdio.h>
#include <conio.h>

#define MAX_EDGES 100
#define MAX_NODES 10

// Arrays to store edges and weights
int u[MAX_EDGES], v[MAX_EDGES], weight[MAX_EDGES];
int parent[MAX_NODES];

int find(int v)
{
    while (parent[v] != v)
    {
        v = parent[v];
    }
    return v;
}

void union1(int i, int j)
{
    if (i < j)
        parent[j] = i;
    else
        parent[i] = j;
}

void kruskal(int n, int edgeCount)
{
    int i, j, count = 0, sum = 0;
    int mst_u[MAX_NODES - 1], mst_v[MAX_NODES - 1], mst_weight[MAX_NODES - 1];

    // Initialize parent array
    for (i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges based on weight (simple bubble sort)
    for (i = 0; i < edgeCount - 1; i++)
    {
        for (j = i + 1; j < edgeCount; j++)
        {
            if (weight[i] > weight[j])
            {
                // Swap u, v, and weight arrays
                int temp_u = u[i], temp_v = v[i], temp_w = weight[i];
                u[i] = u[j];
                v[i] = v[j];
                weight[i] = weight[j];
                u[j] = temp_u;
                v[j] = temp_v;
                weight[j] = temp_w;
            }
        }
    }

    // Kruskal's Algorithm
    for (i = 0; i < edgeCount && count < n - 1; i++)
    {
        int uRoot = find(u[i]);
        int vRoot = find(v[i]);

        if (uRoot != vRoot)
        {
            union1(uRoot, vRoot);
            mst_u[count] = u[i];
            mst_v[count] = v[i];
            mst_weight[count] = weight[i];
            sum += weight[i];
            count++;
        }
    }

    if (count == n - 1)
    {
        printf("Spanning Tree:\n");
        for (i = 0; i < count; i++)
        {
            printf("%d - %d\tWeight: %d\n", mst_u[i], mst_v[i], mst_weight[i]);
        }
        printf("Cost of Spanning Tree = %d\n", sum);
    }
    else
    {
        printf("Spanning Tree does not exist.\n");
    }
}

void main()
{
    int n, edgeCount, i;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);

    printf("Enter the number of edges:\n");
    scanf("%d", &edgeCount);

    printf("Enter edges in the format: u v weight\n");
    for (i = 0; i < edgeCount; i++)
    {
        scanf("%d %d %d", &u[i], &v[i], &weight[i]);
    }
    kruskal(n, edgeCount);
}
