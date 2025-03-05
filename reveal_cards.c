//950. Reveal Cards In Increasing Order
//You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].
//You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.
//You will do the following steps repeatedly until all cards are revealed:
//Take the top card of the deck, reveal it, and take it out of the deck.
//If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
//If there are still unrevealed cards, go back to step 1. Otherwise, stop.
//Return an ordering of the deck that would reveal the cards in increasing order.
#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int n) {
    // Simple bubble sort (or you can use qsort, but here it's for simplicity)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int* deckRevealedIncreasing(int* deck, int n, int* returnSize) {
    *returnSize = n;
    int* ans = (int*)malloc(n * sizeof(int));
    sort(deck, n);

    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1 || i == n - 2) {
            ans[i] = deck[i];
        } else {
            ans[i] = deck[i];
            int temp = ans[n - 1];
            for (int j = n - 2; j >= i + 1; j--) {
                ans[j + 1] = ans[j];
            }
            ans[i + 1] = temp;
        }
    }
   
    return ans;
}

