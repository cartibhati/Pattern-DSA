# Find Minimum in Rotated Sorted Array (LeetCode 153)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)**

---

## 📝 Problem Description

Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times. For example, the array `nums = [0,1,2,4,5,6,7]` might become:
- `[4,5,6,7,0,1,2]` if it was rotated 4 times.
- `[0,1,2,4,5,6,7]` if it was rotated 7 times.

Given the sorted rotated array `nums` of **unique** elements, return *the minimum element of this array*.

You must write an algorithm that runs in `O(log n)` time.

---

## 💡 Intuition & Core Logic

1. **Binary Search**: Since the array was originally sorted, we can leverage Binary Search to find the minimum element in `O(log N)` time instead of `O(N)` linear search.
2. **Inflection Point Identification**:
   - We maintain search boundaries `s` (start) and `e` (end).
   - In each step, we compute `mid = s + (e - s) / 2`.
   - **Case 1: `nums[mid] < nums[e]`**
     - This indicates that the right half (from `mid` to `e`) is sorted.
     - The minimum element must reside in the left half, and `mid` itself could be the minimum.
     - Therefore, we shrink our search space to `e = mid`.
   - **Case 2: `nums[mid] >= nums[e]`**
     - Since elements are unique and `mid < e`, this means `nums[mid] > nums[e]`.
     - This implies the minimum element lies strictly in the right half because the inflection point (where the drop/reset occurs) is to the right of `mid`.
     - Therefore, we search the right half: `s = mid + 1`.
3. **Termination**: When `s == e`, the search space has converged to the minimum element. We return `nums[s]`.

---

## 🔄 Step-by-Step Dry Run

For `nums = [3, 4, 5, 1, 2]`.

- **Initialization**: `s = 0`, `e = 4` (`n = 5`)
1. **Iteration 1**:
   - `mid = 0 + (4 - 0) / 2 = 2`
   - `nums[mid] = nums[2] = 5`
   - Compare `nums[mid]` with `nums[e]`: `5 > nums[4] (2)` $\rightarrow$ Minimum lies in the right half.
   - Update `s = mid + 1 = 3`.
2. **Iteration 2**:
   - `mid = 3 + (4 - 3) / 2 = 3`
   - `nums[mid] = nums[3] = 1`
   - Compare `nums[mid]` with `nums[e]`: `1 < nums[4] (2)` $\rightarrow$ `mid` could be the minimum, search left including `mid`.
   - Update `e = mid = 3`.
- **Termination**: `s (3) == e (3)`. Loop terminates.
- **Result**: `nums[3] = 1`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int n = nums.size();
        int e = n - 1;
        while (s < e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] < nums[e])
                e = mid;
            else
                s = mid + 1;
        }
        return nums[s];
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(log N)` — In each iteration, we halve the search space.
- **Space Complexity**: `O(1)` — Only constant auxiliary space is used.
