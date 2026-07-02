# Search in Rotated Sorted Array (LeetCode 33)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/search-in-rotated-sorted-array/)**

---

## 📝 Problem Description

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is possibly rotated at an unknown pivot index `k` (`1 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (0-indexed). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` after the possible rotation and an integer `target`, return *the index of `target` if it is in `nums`, or `-1` if it is not in `nums`*.

You must write an algorithm with `O(log n)` runtime complexity.

---

## 💡 Intuition & Core Logic

1. **Binary Search**: Since the array was originally sorted and then rotated, one of the two halves (left or right) relative to any pivot/middle index will always be perfectly sorted.
2. **Identifying the Sorted Half**:
   - In each step, we compute `mid = s + (e - s) / 2`.
   - **Case 1: Left half is sorted (`nums[s] <= nums[mid]`)**
     - If `target` lies within this sorted left portion (`nums[s] <= target < nums[mid]`), we search the left side by setting `e = mid - 1`.
     - Otherwise, the target must be in the right half, so we set `s = mid + 1`.
   - **Case 2: Right half is sorted (`nums[s] > nums[mid]`)**
     - If `target` lies within this sorted right portion (`nums[mid] < target <= nums[e]`), we search the right side by setting `s = mid + 1`.
     - Otherwise, the target must be in the left half, so we set `e = mid - 1`.
3. **Termination**: If we find `nums[mid] == target`, we return `mid`. If `s > e` and target has not been found, we return `-1`.

---

## 🔄 Step-by-Step Dry Run

For `nums = [4, 5, 6, 7, 0, 1, 2]` and `target = 0`.

- **Initialization**: `s = 0`, `e = 6` (`n = 7`)
1. **Iteration 1**:
   - `mid = 0 + (6 - 0) / 2 = 3`
   - `nums[mid] = nums[3] = 7`
   - `7 != 0` (Continue)
   - Compare `nums[mid]` with `nums[s]`: `7 >= 4` $\rightarrow$ Left half `[4, 5, 6, 7]` is sorted.
   - Check if `target` is within the left sorted half: `4 <= 0 < 7`? (False)
   - Update `s = mid + 1 = 4`.
2. **Iteration 2**:
   - `s = 4`, `e = 6`
   - `mid = 4 + (6 - 4) / 2 = 5`
   - `nums[mid] = nums[5] = 1`
   - `1 != 0` (Continue)
   - Compare `nums[mid]` with `nums[s]`: `nums[5] (1) >= nums[4] (0)` $\rightarrow$ Left half of this subarray is sorted.
   - Check if `target` is within the left sorted half: `0 <= 0 < 1`? (True)
   - Update `e = mid - 1 = 4`.
3. **Iteration 3**:
   - `s = 4`, `e = 4`
   - `mid = 4 + (4 - 4) / 2 = 4`
   - `nums[mid] = nums[4] = 0`
   - `0 == 0` $\rightarrow$ Target found!
   - Return `mid` = `4`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0;
        int n = nums.size();
        int e = n - 1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
                return mid;

            if (nums[mid] >= nums[s]) {
                if (target < nums[mid] && nums[s] <= target)
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            else {
                if (target > nums[mid] && target <= nums[e])
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }
        return -1;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(log N)` — In each iteration, we halve the search space.
- **Space Complexity**: `O(1)` — Only constant auxiliary space is used.
