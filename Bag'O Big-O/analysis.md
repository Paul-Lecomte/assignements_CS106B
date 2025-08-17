# CS106B Assignment 5 — Bag o’ Big-O
**Name:** Paul Lecomte

---

## 1. Runtime of `mergeSorted`

- What does `mergeSorted` do?
- Walk through how it compares elements from two sorted vectors.
- How many total comparisons happen in the worst case?
- Give the Big-O runtime.

**Answer:**  
(Your explanation here)

---

## 2. Runtime of `combineRange`

- Explain the recursion tree: how the runs are divided and merged back.
- How much work is done at each “level” of recursion?
- How many levels are there in total?
- Conclude the runtime.

**Answer:**  
(Your explanation here)

---

## 3. Runtime of `combine`

- Since `combine` just calls `combineRange`, summarize the total runtime.
- Compare to the naive “append + sort” strategy.

**Answer:**  
(Your explanation here)

---

## 4. Why Divide-and-Conquer is Efficient

- Contrast left-to-right merging with divide-and-conquer merging.
- Which scales better as `k` (the number of runs) grows large?
- Give an example (e.g., `k = 1024`) to illustrate the difference.

**Answer:**  
(Your explanation here)

---

## 5. Optional Experiment (for fun)

- Generate large random runs (with `makeKRuns`).
- Measure how long your combine takes vs. the slow baseline.
- Report whether it matches your theoretical Big-O analysis.

---

