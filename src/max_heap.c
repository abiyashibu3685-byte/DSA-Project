/*
 * max_heap.c
 * Hospital Priority Queue - Max Heap Insertion
 * Inserts patient severity scores one at a time and prints
 * the heap array (level-order) after every insertion.
 */

#include <stdio.h>

#define MAX_SIZE 100

void printHeap(int heap[], int size) {
    printf("Heap array : [");
    for (int i = 0; i < size; i++) {
        printf("%d", heap[i]);
        if (i != size - 1) printf(", ");
    }
    printf("]\n");
}

/* Restore max-heap property by moving a newly inserted
   element up towards the root (sift-up / bubble-up). */
void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] < heap[index]) {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            printf("   swap: index %d <-> index %d\n", index, parent);
            index = parent;
        } else {
            break;
        }
    }
}

void insert(int heap[], int *size, int value) {
    heap[*size] = value;
    (*size)++;
    heapifyUp(heap, *size - 1);
}

int heapHeight(int size) {
    int height = -1;
    int nodes = 1;
    long total = 0;
    while (total < size) {
        total += nodes;
        nodes *= 2;
        height++;
    }
    return height;
}

int main(void) {
    int scores[] = {45, 72, 30, 90, 65, 50, 85};
    int n = sizeof(scores) / sizeof(scores[0]);
    int heap[MAX_SIZE];
    int size = 0;

    printf("=== Hospital Priority Queue: Max Heap Insertion ===\n\n");

    for (int i = 0; i < n; i++) {
        printf("Step %d - Insert severity score %d\n", i + 1, scores[i]);
        insert(heap, &size, scores[i]);
        printHeap(heap, size);
        printf("\n");
    }

    printf("Final Max Heap        : ");
    printHeap(heap, size);
    printf("Heap size              : %d\n", size);
    printf("Heap height            : %d\n", heapHeight(size));
    printf("Highest priority patient (root of heap) = %d\n", heap[0]);

    return 0;
}
