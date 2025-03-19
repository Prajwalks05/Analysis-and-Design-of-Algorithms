#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *a, n;
void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int *c = (int *)malloc((high - low + 1) * sizeof(int));

    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            c[k - low] = a[i++];
        }
        else
        {
            c[k - low] = a[j++];
        }
        k++;
    }
    while (i <= mid)
    {
        c[k - low] = a[i++];
        k++;
    }
    while (j <= high)
    {
        c[k - low] = a[j++];
        k++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = c[i - low];
    }

    free(c);
}
void merge_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;

        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}
void generate_random_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 100000;
    }
}
void display_elements(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{
    int i, choice;
    srand(time(0));

    printf("Enter the no. of elements (up to 10000): ");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }
    printf("Choose input type:\n");
    printf("1. Generate random elements\n");
    printf("2. Exit\n");
    scanf("%d", &choice);
    if (choice == 1)
    {
        generate_random_array(a, n);
        printf("Randomly generated array:\n");
        display_elements(a, n);
        clock_t start = clock();
        merge_sort(a, 0, n - 1);
        clock_t end = clock();
        double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
        printf("Sorted array: ");
        display_elements(a, n);
        printf("Time taken to sort: %f seconds\n", time_taken);
    }
    else
    {
        printf("Exiting program.\n");
    }
    free(a);
    return 0;
}
