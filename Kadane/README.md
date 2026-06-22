# ⚡ Kadane's Algorithm Pattern

Kadane's Algorithm is a dynamic programming pattern used to find the maximum or minimum subarray sum in O(N) time. It involves updating the optimal subarray ending at each position.

---

## 📝 Concept Cheatsheet

### Kadane's Max Subarray Template
```cpp
int bestend = nums[0];
int ans = nums[0];
for (int i = 1; i < nums.size(); i++) {
    bestend = max(nums[i], bestend + nums[i]);
    ans = max(ans, bestend);
}
```

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Maximum Subarray** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/maximum-subarray/) | [`1_max_subarray_53.cpp`](./1_max_subarray_53.cpp) | [Explanation & Dry Run](1_max_subarray_53.md) |
| 2 | **Smallest Sum Subarray** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://www.geeksforgeeks.org/problems/minimum-sum-subarray/1) | [`2_min_subarray.cpp`](./2_min_subarray.cpp) | [Explanation & Dry Run](2_min_subarray.md) |
| 3 | **Maximum Product Subarray** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/maximum-product-subarray/) | [`3_max_prodcut_subarray.cpp`](./3_max_prodcut_subarray.cpp) | [Explanation & Dry Run](3_max_prodcut_subarray.md) |
| 4 | **Maximum Subarray Sum with One Deletion** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/) | [`4_max_subar_sum_one_del_1186.cpp`](./4_max_subar_sum_one_del_1186.cpp) | [Explanation & Dry Run](4_max_subar_sum_one_del_1186.md) |
| 5 | **Maximum Absolute Sum of Any Subarray** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/) | [`5_max_abs_subar_sum_1749.cpp`](./5_max_abs_subar_sum_1749.cpp) | [Explanation & Dry Run](5_max_abs_subar_sum_1749.md) |
| 6 | **Maximum Sum Circular Subarray** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/maximum-sum-circular-subarray/) | [`6_max_sum_circular_subarray_918.cpp`](./6_max_sum_circular_subarray_918.cpp) | [Explanation & Dry Run](6_max_sum_circular_subarray_918.md) |

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*