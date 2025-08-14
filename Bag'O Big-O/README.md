
# CS106B Assignment 5 — Bag'O Big-O (No Stanford Library)

This is a **from-scratch starter** you can use to complete the CS106B *Assignment 5: Bag'O Big-O*
without relying on the Stanford C++ library or the provided GUI harness.

It focuses on:
- Problem 2: `combine` — recursively merging `k` sorted sequences in **O(n log k)**.
- A lightweight timing harness to sanity‑check runtime scaling like the original "Time Tests".
- A placeholder for Problem 1 answers (`BigOAnswers.txt`), since the original functions are tied
  to the Stanford library. You can still practice by adding your own functions to time if you like.

## Build & Run

```bash
# From this folder
cmake -S . -B build
cmake --build build -j
./build/cs106b_a5                # Runs tests
./build/cs106b_a5 --time         # Runs timing harness for combine (prints CSV)
./build/cs106b_a5 --bench 5 18   # Optional: benchmark with log2(k) from 0..5 and n up to 2^18
```

- The timing harness prints CSV with columns: `k,n,ms`. Import into a spreadsheet or plotter.
- By default, the harness uses `k in {1,4,16,64}` and `n up to 2^17` unless you pass `--bench`.

## What you implement

Open `src/Combine.cpp` and complete:

- `mergeSorted` — classic linear merge of two sorted arrays of `DataPoint` by `weight`.
- `combineRange` — recursively combine a slice `[lo, hi)` of the outer vector.
- `combine` — thin wrapper calling `combineRange` on the full input.

**Constraints:** Your overall algorithm must be `O(n log k)` where `n` is total items and `k` is the
number of sequences. Avoid `pop_front`-style operations on `std::vector` — use indices/iterators.

## Tests

Edit or extend tests in `src/tests.cpp`. There are already sanity tests including:
- empty input
- single sequence
- merging different sizes (including duplicates)
- random fuzz tests comparing against a slow baseline

## Problem 1 (Big-O Analysis)

The original assignment ships 13 functions to analyze. Here we include only a **placeholder** file
`BigOAnswers.txt` for your answers. If you want to practice, you can add your own functions and time
them in `src/main.cpp` following the examples.

## Notes

- `DataPoint` is defined in `include/DataPoint.h` and sorts by `weight`; ties keep all elements and
  may be ordered arbitrarily (matching the assignment statement).
- No external libraries are required beyond a C++17 compiler and CMake.
- Keep your implementation pure and iterative inside `mergeSorted` to avoid hidden `O(n^2)` costs.

Happy coding!
