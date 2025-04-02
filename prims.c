#include <stdio.h>

int cost[10][10], vt[10], et[10][10], vis[10], j, n;
int sum = 0;
int x = 1;
int e = 0;

void main()
{
    int i, edges, u, v, weight;
    printf("Enter the number of vertices:\n");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cost[i][j] = 999; // Representing infinity
        }
        vis[i] = 0;
    }

    printf("Enter the number of edges:\n");
    scanf("%d", &edges);

    printf("Enter edges in the format: u v weight\n");
    for (i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &u, &v, &weight);
        if (u >= 1 && u <= n && v >= 1 && v <= n && weight > 0)
        {
            cost[u][v] = weight;
            cost[v][u] = weight; // For undirected graph
        }
        else
        {
            printf("Invalid edge input. Please enter valid vertices and weight.\n");
            i--; // Retry current iteration
        }
    }

    prims();

    printf("Edges of the spanning tree:\n");
    for (i = 1; i <= e; i++)
    {
        printf("%d - %d\t", et[i][0], et[i][1]);
    }
    printf("\nWeight = %d\n", sum);
}

void prims()
{
    int s, min, m, k, u, v;
    vt[x] = 1;
    vis[1] = 1;

    for (s = 1; s < n; s++)
    {
        int j = x;
        min = 999;

        while (j > 0)
        {
            k = vt[j];
            for (m = 2; m <= n; m++)
            {
                if (vis[m] == 0)
                {
                    if (cost[k][m] < min)
                    {
                        min = cost[k][m];
                        u = k;
                        v = m;
                    }
                }
            }
            j--;
        }

        vt[++x] = v;
        et[s][0] = u;
        et[s][1] = v;
        e++;
        vis[v] = 1;
        sum += min;
    }
}
