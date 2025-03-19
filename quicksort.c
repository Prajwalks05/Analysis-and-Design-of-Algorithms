#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *a, n; // Array declaration and size variable

// Function prototypes
int partition(int[], int, int);
void quick_sort(int[], int, int);
void swap(int *, int *);
void generate_random_array(int[], int);
void display_elements(int[], int);

int main()
{
    int i, choice;
    clock_t start, end;
    double time_taken;

    // Initialize random number generator
    srand(time(0));

    // Take user input for the number of elements
    printf("Enter the number of elements (up to 10000): ");
    scanf("%d", &n);
    // Dynamically allocate memory for the array
    a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Menu for user choices
    while (1)
    {
        printf("\nChoose an option:\n");
        printf("1. Generate random elements\n");
        printf("2. Display the array before sorting\n");
        printf("3. Sort the array using QuickSort\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Generate random array
            generate_random_array(a, n);
            printf("Randomly generated array:\n");
            display_elements(a, n);
            break;

        case 2:
            // Display the array before sorting
            printf("Array before sorting:\n");
            display_elements(a, n);
            break;

        case 3:
            // Sort the array and display the result
            start = clock();
            quick_sort(a, 0, n - 1);
            end = clock();
            time_taken = (double)(end - start) / CLOCKS_PER_SEC;

            printf("Sorted array:\n");
            display_elements(a, n);
            printf("Time taken to sort: %f seconds\n", time_taken);
            break;

        case 4:
            // Exit program
            printf("Exiting program.\n");
            free(a); // Free dynamically allocated memory
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    // Free dynamically allocated memory before exit
    free(a);
    return 0;
}

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for quicksort
int partition(int a[], int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high + 1;

    while (i <= j)
    {
        do
        {
            i = i + 1;
        } while (a[i] < pivot && i <= high);
        do
        {
            j = j - 1;
        } while (a[j] > pivot && j >= low);
        if (i < j)
        {
            swap(&a[i], &a[j]);
        }
    }

    swap(&a[j], &a[low]);
    return j;
}
void quick_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = partition(a, low, high);
        quick_sort(a, low, mid - 1);  // Sort the left part
        quick_sort(a, mid + 1, high); // Sort the right part
    }
}
void generate_random_array(int a[], int size)
{
    for (int i = 0; i < size; i++)
    {
        a[i] = rand() % 10000000000;
    }
}

void display_elements(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
