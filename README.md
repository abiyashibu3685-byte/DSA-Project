# Hospital Priority Queue — Max Heap, Heap Sort & Quick Sort

Data Structures and Algorithms — Assignment 1

## Problem Statement

A hospital uses a priority queue to manage patients according to severity (higher score = higher priority).

Patient severity scores: `45, 72, 30, 90, 65, 50, 85`

- **(a)** Implement a Max Heap and insert the scores one by one, showing the heap after each insertion.
- **(b)** Implement Heap Sort and Quick Sort on the same data, recording intermediate steps.
- **(c)** Analyse both sorting approaches on heap structure/height, comparisons/swaps, time complexity, and space, and determine which approach suits a hospital that continuously inserts patients and needs the highest-priority patient immediately.

## Repository Structure

```
.
├── README.md                          # This file
├── src/
│   ├── max_heap.c                     # (a) Max heap insertion, prints heap after each insert
│   ├── heap_sort.c                    # (b) Heap Sort, counts comparisons/swaps
│   └── quick_sort.c                   # (b) Quick Sort, counts comparisons/swaps
├── data/
│   └── input.txt                      # Input patient severity scores
├── output/
│   ├── max_heap_output.txt            # Captured program output for (a)
│   ├── heap_sort_output.txt           # Captured program output for (b) heap sort
│   └── quick_sort_output.txt          # Captured program output for (b) quick sort
└── docs/
    ├── trace_table.md                 # Step-by-step trace tables for all three programs
    ├── complexity_analysis.md         # Time & space complexity analysis
    └── comparison_and_conclusion.md   # (c) Comparison table + final conclusion
```

## How to Compile and Run

Requires a C compiler (e.g. `gcc`).

```bash
cd src

gcc -Wall -o max_heap max_heap.c
./max_heap

gcc -Wall -o heap_sort heap_sort.c
./heap_sort

gcc -Wall -o quick_sort quick_sort.c
./quick_sort
```

Each program prints its own trace to the console; the checked-in copies of that output are saved under `output/`.

## Results Summary

| Program | Final output | Comparisons | Swaps |
|---|---|---|---|
| Max Heap insertion | `[90, 72, 85, 45, 65, 30, 50]` (height 2, root = 90) | — | 4 (across 7 insertions) |
| Heap Sort | `[30, 45, 50, 65, 72, 85, 90]` | 21 | 18 |
| Quick Sort | `[30, 45, 50, 65, 72, 85, 90]` | 12 | 12 |

See `docs/trace_table.md` for full step-by-step traces, `docs/complexity_analysis.md` for the time/space complexity breakdown, and `docs/comparison_and_conclusion.md` for the comparison table and final recommendation.

## Conclusion (short version)

The **Max Heap / priority queue** is the most suitable structure for a hospital that continuously inserts patients and needs the highest-priority patient immediately: insertion is O(log n) and the top-priority patient is always retrievable in O(1) from the root. Heap Sort and Quick Sort are better suited to producing a full sorted list on demand rather than maintaining a live, constantly updating queue. Full reasoning is in `docs/comparison_and_conclusion.md`.
