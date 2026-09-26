# Trace Tables

Input: `45, 72, 30, 90, 65, 50, 85`

## a) Max Heap Insertion

| Step | Insert | Swaps performed | Heap array after insertion |
|------|--------|--------------------------------|------------------------------------|
| 1 | 45 | none | [45] |
| 2 | 72 | index 1 ↔ index 0 | [72, 45] |
| 3 | 30 | none | [72, 45, 30] |
| 4 | 90 | index 3 ↔ index 1, index 1 ↔ index 0 | [90, 72, 30, 45] |
| 5 | 65 | none | [90, 72, 30, 45, 65] |
| 6 | 50 | index 5 ↔ index 2 | [90, 72, 50, 45, 65, 30] |
| 7 | 85 | index 6 ↔ index 2 | [90, 72, 85, 45, 65, 30, 50] |

**Final heap:** `[90, 72, 85, 45, 65, 30, 50]`, size = 7, height = 2, root (highest priority) = **90**

---

## b) Heap Sort

### Phase 1 — Build Max Heap (bottom-up heapify)

| Heapify at index | Swap | Resulting array |
|---|---|---|
| 2 | 2 ↔ 6 | [45, 72, 85, 90, 65, 50, 30] |
| 1 | 1 ↔ 3 | [45, 90, 85, 72, 65, 50, 30] |
| 0 | 0 ↔ 1, then 1 ↔ 3 | [90, 72, 85, 45, 65, 50, 30] |

Heap built: `[90, 72, 85, 45, 65, 50, 30]`

### Phase 2 — Extract max repeatedly

| Step | Root moved | Sorted position | Array state after heapify |
|------|-----------|------------------|----------------------------|
| 1 | 90 | index 6 | [85, 72, 50, 45, 65, 30 | 90] |
| 2 | 85 | index 5 | [72, 65, 50, 45, 30 | 85, 90] |
| 3 | 72 | index 4 | [65, 45, 50, 30 | 72, 85, 90] |
| 4 | 65 | index 3 | [50, 45, 30 | 65, 72, 85, 90] |
| 5 | 50 | index 2 | [45, 30 | 50, 65, 72, 85, 90] |
| 6 | 45 | index 1 | [30 | 45, 50, 65, 72, 85, 90] |

**Final sorted array:** `[30, 45, 50, 65, 72, 85, 90]`
**Total comparisons:** 21  **Total swaps:** 18

---

## c) Quick Sort (Lomuto partition, pivot = last element)

| Call | Pivot | Partition result | Pivot final index |
|------|-------|-------------------|--------------------|
| QuickSort(0, 6) | 85 | [45, 72, 30, 65, 50, 85, 90] | 5 |
| QuickSort(0, 4) | 50 | [45, 30, 50, 65, 72] | 2 |
| QuickSort(0, 1) | 30 | [30, 45] | 0 |
| QuickSort(3, 4) | 72 | [65, 72] | 4 |

**Final sorted array:** `[30, 45, 50, 65, 72, 85, 90]`
**Total comparisons:** 12  **Total swaps:** 12

Full console traces are in `output/max_heap_output.txt`, `output/heap_sort_output.txt`, and `output/quick_sort_output.txt`.
