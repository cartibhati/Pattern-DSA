# 🏁 Prefix Sum Pattern

Prefix Sum involves precomputing cumulative sums of an array to allow O(1) range sum queries or subarray sum evaluations. It is commonly combined with Hash Maps to track frequencies of prefix sums for finding specific subarray targets.

---

## 📝 Concept Cheatsheet

### Prefix Sum Template
```cpp
vector<int> prefix(n);
prefix[0] = nums[0];
for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + nums[i];
}
```
**Key Formula**: Subarray sum between `[L, R]` = `prefix[R] - prefix[L - 1]` (where `prefix[-1] = 0`).

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Find Pivot Index** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/find-pivot-index/) | [`1_find_pivot_index_724.cpp`](./1_find_pivot_index_724.cpp) | [Explanation & Dry Run](1_find_pivot_index_724.md) |
| 2 | **Subarray Sum Equals K** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/subarray-sum-equals-k/) | [`2_subarray_sum_equals_k.cpp`](./2_subarray_sum_equals_k.cpp) | [Explanation & Dry Run](2_subarray_sum_equals_k.md) |
| 3 | **Subarray Sums Divisible by K** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/subarray-sum-divisible-by-k/) | [`3_subarray_sum_divisible_by_k.cpp`](./3_subarray_sum_divisible_by_k.cpp) | [Explanation & Dry Run](3_subarray_sum_divisible_by_k.md) |
| 4 | **Contiguous Array** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/contiguous-array/) | [`4_contiguos_array.cpp`](./4_contiguos_array.cpp) | [Explanation & Dry Run](4_contiguos_array.md) |

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*