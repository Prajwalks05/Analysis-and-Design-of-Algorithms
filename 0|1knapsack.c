#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n, m, i, j;

    int w[10], p[10], v[10][10], selected[10];

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &m);

    printf("Enter weights of the items:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &w[i]);
    }

    printf("Enter profits of the items:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

    // Build DP table
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else if (w[i - 1] <= j)
                v[i][j] = max(p[i - 1] + v[i - 1][j - w[i - 1]], v[i - 1][j]);
            else
                v[i][j] = v[i - 1][j];
        }
    }

    // Print DP table (optional for debugging)
    printf("\nDP Table:\n");
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            printf("%3d ", v[i][j]);
        }
        printf("\n");
    }

    // Find selected items using backtracking
    int totalProfit = v[n][m];
    int capacity = m;
    printf("\nOptimal profit = %d\n", totalProfit);
    printf("Selected items (0-based index): ");

    printf("Selected items (1-based index): ");
    for (i = n; i > 0 && totalProfit > 0; i--)
    {
        if (totalProfit != v[i - 1][capacity])
        {
            printf("%d ", i); // 1-based index
            totalProfit -= p[i - 1];
            capacity -= w[i - 1];
        }
    }

    printf("\n");
    return 0;
}
