# 🪟 Sliding Window Pattern

Sliding Window involves maintaining a subset of elements in a sequential structure (like an array or string) that expands or shrinks based on certain conditions, avoiding redundant computations by updating the window state dynamically.

---

## 📝 Concept Cheatsheet

### Fixed Size Window Template
```cpp
int sum = 0;
for (int i = 0; i < k; i++) sum += arr[i];
int max_sum = sum;
for (int i = k; i < n; i++) {
    sum += arr[i] - arr[i - k];
    max_sum = max(max_sum, sum);
}
```

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Max Sum Subarray of size K** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1) | [`1_max_subarray_sum.cpp`](./1_max_subarray_sum.cpp) | [Explanation & Dry Run](1_max_subarray_sum.md) |
| 2 | **Minimum Size Subarray Sum** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/minimum-size-subarray-sum/) | [`2_min_size_subarray_sum.cpp`](./2_min_size_subarray_sum.cpp) | [Explanation & Dry Run](2_min_size_subarray_sum.md) |
| 3 | **Longest Substring with K Unique Characters** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://www.geeksforgeeks.org/problems/longest-substring-with-k-unique-characters-in-a-string1612/1) | [`3_long_substr_with_k_uniques.cpp`](./3_long_substr_with_k_uniques.cpp) | [Explanation & Dry Run](3_long_substr_with_k_uniques.md) |
| 4 | **Fruit Into Baskets** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/fruit-into-baskets/) | [`4_Fruits_into_basket.cpp`](./4_Fruits_into_basket.cpp) | [Explanation & Dry Run](4_Fruits_into_basket.md) |
| 5 | **Longest Substring Without Repeating Characters** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [`5_long_substr_without_repeat_char.cpp`](./5_long_substr_without_repeat_char.cpp) | [Explanation & Dry Run](5_long_substr_without_repeat_char.md) |

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*