/*
 * quick_sort.c
 * Quick Sort on patient severity scores.
 * Uses Lomuto partition scheme with the last element of each
 * sub-array as the pivot. Counts comparisons and swaps.
 */

#include <stdio.h>

long comparisons = 0;
long swaps = 0;

void printArray(int arr[], int low, int high, const char *label) {
    printf("%s: [", label);
    for (int i = low; i <= high; i++) {
        printf("%d", arr[i]);
        if (i != high) printf(", ");
    }
    printf("]\n");
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    swaps++;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    printf("   pivot = %d (index %d)\n", pivot, high);
    int i = low - 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    int pi = i + 1;
    printf("   partitioned -> ");
    printArray(arr, low, high, "state");
    printf("   pivot %d fixed at index %d\n", pivot, pi);
    return pi;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        printf("QuickSort(low=%d, high=%d)\n", low, high);
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(void) {
    int scores[] = {45, 72, 30, 90, 65, 50, 85};
    int n = sizeof(scores) / sizeof(scores[0]);

    printf("=== Quick Sort on Patient Severity Scores ===\n\n");
    printArray(scores, 0, n - 1, "Initial array");
    printf("\n");

    quickSort(scores, 0, n - 1);

    printf("\nFinal sorted array (ascending) : ");
    printArray(scores, 0, n - 1, "state");
    printf("Total comparisons               : %ld\n", comparisons);
    printf("Total swaps                     : %ld\n", swaps);

    return 0;
}
