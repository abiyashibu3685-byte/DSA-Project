# Complexity Analysis

## 1. Max Heap (used as a Priority Queue)

| Operation | Time Complexity | Explanation |
|---|---|---|
| Insert one patient | O(log n) | New value is placed at the end and sifted up at most `height` levels. |
| Insert n patients | O(n log n) | n insertions, each O(log n). |
| Get highest-priority patient (peek root) | O(1) | Root of the heap is always the maximum. |
| Space | O(n) | Array storing n elements; O(1) extra space per insertion (iterative sift-up). |

**Heap height** for n = 7 elements: `⌊log₂7⌋ = 2` (confirmed by program output). In general, a binary heap with n nodes has height `⌊log₂ n⌋`, which is what keeps insertion and extraction fast.

## 2. Heap Sort

| Phase | Time Complexity | Notes |
|---|---|---|
| Build max heap | O(n) (tight bound) — often stated as O(n log n) as a looser upper bound | Bottom-up heapify does more work near the leaves and less near the root, giving a true O(n) bound. |
| Extract max, n times | O(n log n) | Each of the n extractions does one O(log n) sift-down. |
| **Overall** | **O(n log n)** — same for best, average, and worst case | Performance does not depend on the input order. |
| Space | O(1) extra (in-place, array-based) + O(log n) recursion stack (heapify is written recursively here) | No auxiliary array is needed. |

Measured on the given input (n = 7): **21 comparisons, 18 swaps**.

## 3. Quick Sort (Lomuto partition, last element as pivot)

| Case | Time Complexity | When it happens |
|---|---|---|
| Best / Average | O(n log n) | Pivot roughly balances the sub-arrays each time. |
| Worst | O(n²) | Already-sorted or reverse-sorted input with a fixed "last element" pivot — partitions become maximally unbalanced (n-1 and 0). |
| Space | O(log n) average recursion stack, O(n) worst case | No auxiliary array (in-place partitioning), but recursion depth depends on how balanced the splits are. |

Measured on the given input (n = 7): **12 comparisons, 12 swaps** — fewer than Heap Sort here because the chosen pivots (85, 50, 30, 72) happened to split the array fairly evenly.

## 4. Summary Table

| Structure/Algorithm | Best | Average | Worst | Space |
|---|---|---|---|---|
| Max Heap – insert | O(log n) | O(log n) | O(log n) | O(n) total, O(1) per op |
| Max Heap – peek max | O(1) | O(1) | O(1) | O(1) |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) extra |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) avg / O(n) worst |
