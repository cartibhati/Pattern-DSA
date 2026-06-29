# Binary Search (LeetCode 704)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/binary-search/)**

---

## 📝 Problem Description

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

---

## 💡 Intuition & Core Logic

1. **Divide and Conquer**: Since the input array is already sorted, we can divide our search space in half at each step.
2. **Three Pointers / Indices**:
   - `low`: Points to the start of the current search interval (initially `0`).
   - `high`: Points to the end of the current search interval (initially `n - 1`).
   - `mid`: Points to the middle element of the current search interval, calculated as `low + (high - low) / 2` to prevent potential integer overflow.
3. **Decision Making**:
   - If `nums[mid] == target`, we have found the target, so we return `mid`.
   - If `nums[mid] > target`, the target must lie in the left half, so we narrow our search space by setting `high = mid - 1`.
   - If `nums[mid] < target`, the target must lie in the right half, so we narrow our search space by setting `low = mid + 1`.
4. **Termination**: Repeat this until `low > high`. If we exit the loop without finding the target, return `-1`.

---

## 🔄 Step-by-Step Dry Run

For `nums = [-1, 0, 3, 5, 9, 12]`, `target = 9`.

- **Initialization**:
  - `low = 0`, `high = 5`
  - `mid = 0 + (5 - 0) / 2 = 2`

1. **Iteration 1**:
   - `nums[mid]` (where `mid = 2`) is `3`.
   - Compare `nums[2] = 3` with `target = 9`.
   - Since `3 < 9`, target is in the right half.
   - Update `low = mid + 1 = 3`.
   - Recalculate `mid = 3 + (5 - 3) / 2 = 4`.

2. **Iteration 2**:
   - `nums[mid]` (where `mid = 4`) is `9`.
   - Compare `nums[4] = 9` with `target = 9`.
   - Since `nums[4] == target`, we found the target!
   - Return `mid = 4`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int n = nums.size();
        int high = n - 1;
        int mid = low + (high - low) / 2;
        
        while (low <= high) {
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
            mid = low + (high - low) / 2;
        }
        return -1;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(log N)` — In each iteration of the loop, we divide the search space by half. Thus, the time complexity is logarithmic.
- **Space Complexity**: `O(1)` — We only use a few helper variables (`low`, `high`, `mid`), requiring constant auxiliary space.
