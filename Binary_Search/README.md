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

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*
