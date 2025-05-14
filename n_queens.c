#include <stdio.h>
#include <stdbool.h>

bool place(int x[], int k)
{
    for (int i = 1; i < k; i++)
        if (x[i] == x[k] || i - x[i] == k - x[k] || i + x[i] == k + x[k])
            return false;
    return true;
}

void printSolution(int x[], int n, int count)
{
    printf("Solution %d:\n", count);
    for (int i = 1; i <= n; i++, printf("\n"))
        for (int j = 1; j <= n; j++)
            printf("%c ", x[i] == j ? 'Q' : '.');
}

void nQueens(int n)
{
    int x[10] = {0}, k = 1, count = 0;
    while (k != 0)
    {
        x[k]++;
        while (x[k] <= n && !place(x, k))
        {
            x[k]++;
        }
        if (x[k] <= n)
        {
            if (k == n)
            {
                printSolution(x, n, ++count);
            }
            else
            {
                x[++k] = 0;
            }
        }
        else
        {
            k--;
        }
    }
    printf("Total solutions: %d\n", count);
}
int main()
{
    int n;
    printf("Enter the number of queens: ");
    scanf("%d", &n);
    nQueens(n);
    return 0;
}
