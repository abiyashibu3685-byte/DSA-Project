/*
 * heap_sort.c
 * Heap Sort on patient severity scores.
 * Builds a max heap, then repeatedly extracts the maximum
 * element, producing an ascending sorted array.
 * Counts comparisons and swaps for performance analysis.
 */

#include <stdio.h>

long comparisons = 0;
long swaps = 0;

void printArray(int arr[], int n, const char *label) {
    printf("%s: [", label);
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i != n - 1) printf(", ");
    }
    printf("]\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

/* Sift-down: restore max-heap property for subtree rooted at i,
   within the first n elements of arr. */
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n) {
        comparisons++;
        if (arr[left] > arr[largest])
            largest = left;
    }
    if (right < n) {
        comparisons++;
        if (arr[right] > arr[largest])
            largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        printf("   heapify swap: index %d <-> index %d -> ", i, largest);
        printArray(arr, n, "state");
        heapify(arr, n, largest);
    }
}

void buildMaxHeap(int arr[], int n) {
    printf("--- Phase 1: Build Max Heap ---\n");
    for (int i = n / 2 - 1; i >= 0; i--) {
        printf("Heapify subtree at index %d\n", i);
        heapify(arr, n, i);
    }
    printArray(arr, n, "Heap built");
    printf("\n");
}

void heapSort(int arr[], int n) {
    buildMaxHeap(arr, n);

    printf("--- Phase 2: Extract elements one by one ---\n");
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        printf("Step: move root %d to sorted position %d -> ", arr[i], i);
        printArray(arr, n, "state");
        heapify(arr, i, 0);
    }
}

int main(void) {
    int scores[] = {45, 72, 30, 90, 65, 50, 85};
    int n = sizeof(scores) / sizeof(scores[0]);

    printf("=== Heap Sort on Patient Severity Scores ===\n\n");
    printArray(scores, n, "Initial array");
    printf("\n");

    heapSort(scores, n);

    printf("\nFinal sorted array (ascending) : ");
    printArray(scores, n, "state");
    printf("Total comparisons               : %ld\n", comparisons);
    printf("Total swaps                     : %ld\n", swaps);

    return 0;
}
