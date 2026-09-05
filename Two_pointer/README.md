# 雙 Two Pointer Pattern

Two Pointer techniques use two indices (usually scanning from both ends inward, or moving at different rates) to search for pairs or structures in linear data structures. This is extremely efficient for sorted arrays.

---

## 📝 Concept Cheatsheet

### Two Pointer Template
```cpp
int left = 0, right = n - 1;
while (left < right) {
    int sum = arr[left] + arr[right];
    if (sum == target) return {left, right};
    else if (sum < target) left++;
    else right--;
}
```

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Segregate 0s and 1s** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5125/1) | [`2_segregate_0_and_1.cpp`](./2_segregate_0_and_1.cpp) | [Explanation & Dry Run](2_segregate_0_and_1.md) |
| 2 | **Squares of a Sorted Array** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/squares-of-a-sorted-array/) | [`3_squares_of_sorted_array.cpp`](./3_squares_of_sorted_array.cpp) | [Explanation & Dry Run](3_squares_of_sorted_array.md) |
| 3 | **Remove Duplicates from Sorted Array** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | [`4_remove_dup_from_sorted_array.cpp`](./4_remove_dup_from_sorted_array.cpp) | [Explanation & Dry Run](4_remove_dup_from_sorted_array.md) |
| 4 | **Valid Palindrome** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/valid-palindrome/) | [`7_valid_palindrome.cpp`](./7_valid_palindrome.cpp) | [Explanation & Dry Run](7_valid_palindrome.md) |
| 5 | **Two Sum II - Input Array Is Sorted** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | [`1_Two_sum_2.cpp`](./1_Two_sum_2.cpp) | [Explanation & Dry Run](1_Two_sum_2.md) |
| 6 | **3Sum** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/3sum/) | [`5_3_sum.cpp`](./5_3_sum.cpp) | [Explanation & Dry Run](5_3_sum.md) |
| 7 | **3Sum Smaller** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://www.geeksforgeeks.org/problems/3-sum-smaller5017/1) | [`6_triplets_with_smaller_sum.cpp`](./6_triplets_with_smaller_sum.cpp) | [Explanation & Dry Run](6_triplets_with_smaller_sum.md) |
| 8 | **Container With Most Water** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/container-with-most-water/) | [`8_Container With Most Water.cpp`](./8_Container%20With%20Most%20Water.cpp) | [Explanation & Dry Run](8_Container%20With%20Most%20Water.md) |

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*