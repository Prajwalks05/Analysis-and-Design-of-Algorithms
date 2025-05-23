#include <stdio.h>
#include <stdlib.h>

#define LEFT -1
#define RIGHT 1

typedef struct {
    int value;
    int dir;  // -1 for LEFT, 1 for RIGHT
} Element;

// Function to print a permutation
void printPermutation(Element perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i].value);
    }
    printf("\n");
}

// Function to find the largest mobile element
int getMobileIndex(Element perm[], int n) {
    int mobileIndex = -1;
    for (int i = 0; i < n; i++) {
        int next = i + perm[i].dir;
        if (next >= 0 && next < n && perm[i].value > perm[next].value) {
            if (mobileIndex == -1 || perm[i].value > perm[mobileIndex].value) {
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}

// Function to swap two elements
void swap(Element *a, Element *b) {
    Element temp = *a;
    *a = *b;
    *b = temp;
}

// Function to reverse directions of elements greater than mobile
void reverseDirections(Element perm[], int n, int mobileVal) {
    for (int i = 0; i < n; i++) {
        if (perm[i].value > mobileVal) {
            perm[i].dir *= -1;
        }
    }
}

void johnsonTrotter(int n) {
    Element *perm = malloc(n * sizeof(Element));
    for (int i = 0; i < n; i++) {
        perm[i].value = i + 1;
        perm[i].dir = LEFT;
    }

    int total = 1;
    for (int i = 2; i <= n; i++) total *= i;

    for (int count = 0; count < total; count++) {
        printPermutation(perm, n);
        int mobileIdx = getMobileIndex(perm, n);
        if (mobileIdx == -1) break;

        int swapIdx = mobileIdx + perm[mobileIdx].dir;
        swap(&perm[mobileIdx], &perm[swapIdx]);
        reverseDirections(perm, n, perm[swapIdx].value);
    }

    free(perm);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
