# 🏔️ Heap / Priority Queue Pattern

The Heap pattern uses binary heaps (usually implemented via `priority_queue` in C++) to efficiently find the minimum or maximum element in a dynamically changing set of numbers. It is particularly useful for finding the K-th smallest/largest element, merging sorted lists, or tracking top-K frequent elements.

---

## 📝 Concept Cheatsheet

### Max-Heap (Standard Priority Queue)
Used for finding K-th smallest elements.
```cpp
priority_queue<int> max_heap; // Top element is the maximum
```

### Min-Heap
Used for finding K-th largest elements.
```cpp
priority_queue<int, vector<int>, greater<int>> min_heap; // Top element is the minimum
```

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Kth Smallest Element** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://www.geeksforgeeks.org/problems/kth-smallest-element5635/1) | [`1_k_smallest.cpp`](./1_k_smallest.cpp) | [Explanation & Dry Run](1_k_smallest.md) |

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*
