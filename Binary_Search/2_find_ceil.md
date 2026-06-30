# Ceil in a Sorted Array

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/)**

---

## 📝 Problem Description

Given a sorted array `arr` and a value `x`, the ceiling of `x` is the smallest element in the array greater than or equal to `x`. If the ceiling does not exist (i.e., `x` is greater than the maximum element in the array), return `-1`.

*Note: The implementation returns the index of the ceiling element.*

---

## 💡 Intuition & Core Logic

1. **Binary Search**: Since the array is sorted, we can search for the ceil of `x` in `O(log N)` time.
2. **Decision Criteria**:
   - If the middle element `arr[mid]` is less than `x`, the ceiling must lie in the right half of the array. So, we search in the right half: `s = mid + 1`.
   - If the middle element `arr[mid]` is greater than or equal to `x`, then `mid` could be our potential ceiling. We store `mid` as a candidate answer (`res = mid`) and continue searching in the left half to see if there is a smaller element that is still greater than or equal to `x`: `e = mid - 1`.
3. **Termination**: The search space is exhausted when `s > e`.

---

## 🔄 Step-by-Step Dry Run

For `arr = [1, 2, 8, 10, 10, 12, 19]`, `x = 5`.

- **Initialization**:
  - `s = 0`, `e = 6`
  - `res = -1`

1. **Iteration 1**:
   - `mid = 0 + (6 - 0) / 2 = 3`
   - `arr[3] = 10`
   - Since `10 >= 5`, this is a candidate ceiling. Set `res = 3`.
   - Narrow search to the left: `e = mid - 1 = 2`.

2. **Iteration 2**:
   - `mid = 0 + (2 - 0) / 2 = 1`
   - `arr[1] = 2`
   - Since `2 < 5`, the ceiling must be to the right of `mid`.
   - Narrow search to the right: `s = mid + 1 = 2`.

3. **Iteration 3**:
   - `mid = 2 + (2 - 2) / 2 = 2`
   - `arr[2] = 8`
   - Since `8 >= 5`, this is a candidate ceiling. Set `res = 2`.
   - Narrow search to the left: `e = mid - 1 = 1`.

- **Termination**:
  - Now `s (2) > e (1)`, loop terminates.
  - Return `res = 2` (index of element `8`).

---

## 💻 C++ Working Code

```cpp
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        int n = arr.size();
        int s = 0;
        int e = n - 1;
        int res = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (arr[mid] < x) {
                s = mid + 1;
            } else {
                res = mid;
                e = mid - 1;
            }
        }
        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(log N)` — In each iteration, we halve the search space.
- **Space Complexity**: `O(1)` — Only constant auxiliary space is used.
