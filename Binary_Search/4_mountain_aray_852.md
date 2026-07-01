# Peak Index in a Mountain Array (LeetCode 852)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/peak-index-in-a-mountain-array/)**

---

## 📝 Problem Description

An array `arr` is a mountain array if the following properties hold:
- `arr.length >= 3`
- There exists some `i` with `0 < i < arr.length - 1` such that:
  - `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
  - `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

Given a mountain array `arr`, return the index `i` such that `arr[0] < arr[1] < ... < arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`.

You must solve it in `O(log(arr.length))` time complexity.

---

## 💡 Intuition & Core Logic

1. **Binary Search**: Since the array rises to a peak and then descends, we can use binary search by comparing the middle element with its next element.
2. **Decision Criteria**:
   - If `arr[mid] < arr[mid + 1]`, we are on the ascending slope of the mountain. The peak must lie to the right of `mid`, so we narrow search to the right: `s = mid + 1`.
   - If `arr[mid] >= arr[mid + 1]`, we are on the descending slope or at the peak. The peak could be `mid` or lie to the left of `mid`, so we narrow search to `e = mid`.
3. **Termination**: The search space is exhausted when `s == e`, and the peak index will be at `s`.

---

## 🔄 Step-by-Step Dry Run

For `arr = [0, 10, 5, 2]`.

- **Initialization**:
  - `s = 0`, `e = 3`

1. **Iteration 1**:
   - `mid = 0 + (3 - 0) / 2 = 1`
   - `arr[1] = 10` and `arr[2] = 5`
   - Since `arr[1] (10) > arr[2] (5)`, we are on the descending side.
   - Set `e = mid = 1`.

2. **Iteration 2**:
   - `mid = 0 + (1 - 0) / 2 = 0`
   - `arr[0] = 0` and `arr[1] = 10`
   - Since `arr[0] (0) < arr[1] (10)`, we are on the ascending side.
   - Set `s = mid + 1 = 1`.

- **Termination**:
  - Now `s (1) == e (1)`, loop terminates.
  - Return `s = 1` (index of element `10`).

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e) {
            int mid = s + (e - s) / 2;

            if (nums[mid] < nums[mid + 1])
                s = mid + 1;
            else
                e = mid;
        }

        return s;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(log N)` — In each iteration, we halve the search space.
- **Space Complexity**: `O(1)` — Only constant auxiliary space is used.
