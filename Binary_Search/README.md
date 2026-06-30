# 🔍 Binary Search Pattern

Binary Search is an efficient search algorithm designed for sorted linear data structures. Instead of scanning linearly, it repeatedly halves the search space, reducing search complexity from `O(N)` to `O(log N)`. 

---

## 📝 Concept Cheatsheet

### Standard Binary Search Template (Recursive / Iterative)
```cpp
int binarySearch(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoids overflow
        if (nums[mid] == target) return mid;
        else if (nums[mid] > target) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}
```

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Binary Search** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/binary-search/) | [`1_binary_search_704.cpp`](./1_binary_search_704.cpp) | [Explanation & Dry Run](1_binary_search_704.md) |
| 2 | **Ceil in Sorted Array** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/) | [`2_find_ceil.cpp`](./2_find_ceil.cpp) | [Explanation & Dry Run](2_find_ceil.md) |
| 3 | **First and Last Position of Element in Sorted Array** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | [`3_first_and_last_pos_in_array.cpp`](./3_first_and_last_pos_in_array.cpp) | [Explanation & Dry Run](3_first_and_last_pos_in_array.md) |

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*
