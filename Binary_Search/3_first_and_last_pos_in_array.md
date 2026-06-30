# Find First and Last Position of Element in Sorted Array (LeetCode 34)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)**

---

## 📝 Problem Description

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

---

## 💡 Intuition & Core Logic

1. **Binary Search**: Since the array is sorted, we can use binary search twice: once to find the first occurrence, and once to find the last occurrence.
2. **First Occurrence**:
   - If `nums[mid] == target`, this is a candidate for the first occurrence. We record the index (`ans = mid`) and continue searching in the left half (`e = mid - 1`) to see if there is an even earlier occurrence.
3. **Last Occurrence**:
   - If `nums[mid] == target`, this is a candidate for the last occurrence. We record the index (`ans = mid`) and continue searching in the right half (`s = mid + 1`) to see if there is a later occurrence.
4. **Time Complexity**: Running two binary searches takes `O(log N) + O(log N) = O(log N)` time.

---

## 🔄 Step-by-Step Dry Run

For `nums = [5, 7, 7, 8, 8, 10]`, `target = 8`.

### Finding First Occurrence:
- **Initialization**: `s = 0`, `e = 5`, `ans = -1`
1. **Iteration 1**:
   - `mid = 0 + (5 - 0) / 2 = 2`
   - `nums[2] = 7 < 8` $\rightarrow$ search right: `s = mid + 1 = 3`
2. **Iteration 2**:
   - `mid = 3 + (5 - 3) / 2 = 4`
   - `nums[4] = 8 == 8` $\rightarrow$ candidate `ans = 4`, search left: `e = mid - 1 = 3`
3. **Iteration 3**:
   - `mid = 3 + (3 - 3) / 2 = 3`
   - `nums[3] = 8 == 8` $\rightarrow$ candidate `ans = 3`, search left: `e = mid - 1 = 2`
- **Termination**: `s (3) > e (2)`. First occurrence index is `3`.

### Finding Last Occurrence:
- **Initialization**: `s = 0`, `e = 5`, `ans = -1`
1. **Iteration 1**:
   - `mid = 0 + (5 - 0) / 2 = 2`
   - `nums[2] = 7 < 8` $\rightarrow$ search right: `s = mid + 1 = 3`
2. **Iteration 2**:
   - `mid = 3 + (5 - 3) / 2 = 4`
   - `nums[4] = 8 == 8` $\rightarrow$ candidate `ans = 4`, search right: `s = mid + 1 = 5`
3. **Iteration 3**:
   - `mid = 5 + (5 - 5) / 2 = 5`
   - `nums[5] = 10 > 8` $\rightarrow$ search left: `e = mid - 1 = 4`
- **Termination**: `s (5) > e (4)`. Last occurrence index is `4`.

**Result**: `[3, 4]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int firstOccurrence(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                ans = mid;
                e = mid - 1;      
            }
            else if (nums[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return ans;
    }

    int lastOccurrence(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target) {
                ans = mid;
                s = mid + 1;      // keep searching right
            }
            else if (nums[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        return {firstOccurrence(nums, target), lastOccurrence(nums, target)};
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(log N)` — Two independent binary search passes are performed, each taking logarithmic time.
- **Space Complexity**: `O(1)` — Only constant auxiliary space is used.
