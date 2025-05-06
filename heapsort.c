#include <stdio.h>

void heapify(int a[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  
  if (left < n && a[left] > a[largest])
    largest = left;
  if (right < n && a[right] > a[largest])
    largest = right;

  if (largest != i) {
    int temp = a[i];
    a[i] = a[largest];
    a[largest] = temp;

    // Recursively heapify the affected sub-tree
    heapify(a, n, largest);
  }
}

void heapSort(int a[], int n) {
  // Build heap (rearrange array)
  for (int i = n / 2 - 1; i >= 0; i--)
    heapify(a, n, i);

  // One by one extract an element from heap
  for (int i = n - 1; i >= 0; i--) {
    // Move current root to end
    int temp = a[0];
    a[0] = a[i];
    a[i] = temp;

    // call max heapify on the reduced heap
    heapify(a, i, 0);
  }
}
int main() {
  int a[10], n;

  printf("Enter the number of array elements: ");
  scanf("%d", & n);

  printf("Enter array elements: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", & a[i]);
  }
  heapSort(a, n);
  printf("Sorted array elements: ");
  for (int i = 0; i < n; i++) {
    printf(" %d", a[i]);
  }

  return 0;
}
