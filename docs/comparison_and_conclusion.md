# Comparison Table

| Criterion | Max Heap (as Priority Queue) | Heap Sort | Quick Sort |
|---|---|---|---|
| Underlying structure | Complete binary tree (array-based) | Complete binary tree (array-based), consumed while sorting | No fixed structure — recursive partitioning of the array |
| Heap/tree height (n = 7) | 2 | 2 (during build phase) | N/A — depth of recursion instead (3 levels for this input) |
| Comparisons observed | — (insertion uses parent comparisons, not counted the same way) | 21 | 12 |
| Swaps observed | 4 swaps across 7 insertions | 18 | 12 |
| Best-case time | O(log n) per insert | O(n log n) | O(n log n) |
| Worst-case time | O(log n) per insert | O(n log n) | O(n²) |
| Space | O(n), O(1) extra per operation | O(1) extra (in-place) | O(log n) avg / O(n) worst (recursion stack) |
| Access to highest-priority item | O(1) — always at the root | Not applicable once sorted | Not applicable once sorted |
| Behaviour with continuous new arrivals | Naturally supports insert + extract-max in O(log n) each | Must rebuild/re-sort after new arrivals — not incremental | Must re-sort after new arrivals — not incremental |
| Stability | Not stable | Not stable | Not stable (as implemented) |

# Final Conclusion

For a hospital that **continuously inserts new patients and must retrieve the highest-priority patient immediately**, the **Max Heap used as a priority queue is the most suitable approach**:

- **Insertion is O(log n)** — much cheaper than re-sorting the whole list every time a new patient arrives, which is what Heap Sort or Quick Sort would require.
- **The current highest-priority patient is always available in O(1)** by reading the root — no search or sort is needed at the moment of retrieval.
- The heap keeps itself balanced incrementally (height stays O(log n) as it grows), so performance stays predictable even as the patient list grows large.

**Heap Sort and Quick Sort are the right tools for a different job**: producing a fully ordered list of all patients at once (e.g., for a shift report or an audit), not for maintaining a live, constantly changing priority queue. Between the two sorting algorithms:
- Heap Sort gives a **guaranteed O(n log n)** bound in every case, which matters if predictable worst-case performance is required.
- Quick Sort is usually **faster in practice** (fewer comparisons/swaps were observed on this input) due to smaller constant factors and better cache behaviour, but it can degrade to O(n²) on adversarial or already-sorted input when the pivot is chosen naively (as it is here, using the last element).

**Overall recommendation:** Use the **Max Heap / priority queue** for real-time patient triage (continuous insertion + immediate retrieval of the most severe case), and reserve **Heap Sort or Quick Sort** for producing complete, sorted snapshots of the patient list when needed.
