# Check if Array is Sorted (Recursive)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://www.geeksforgeeks.org/program-to-check-if-an-array-is-sorted-or-not-recursive/)**

---

## 📝 Problem Description

Given an array `arr` of size `n`, write a recursive function to check if the array is sorted in non-decreasing order.

---

## 💡 Intuition & Core Logic

An array is sorted if:
1. The current element is less than or equal to the next element.
2. The remaining part of the array is also sorted.

We can implement this recursively:
1. **Base Case**:
   - If our index `i` reaches or exceeds `n - 1` (where `n` is the array size), it means we have checked all adjacent pairs successfully. Return `true`.
2. **Recursive Step**:
   - If the current element `arr[i]` is greater than the next element `arr[i + 1]`, the array is not sorted. Return `false`.
   - Otherwise, recursively check the rest of the array by calling `isSorted(arr, i + 1)`.

---

## 🔄 Step-by-Step Dry Run

For `arr = [1, 2, 4, 3]` and `n = 4`:
1. `isSorted(arr, 0)`:
   - Index `0 < 3`.
   - Compare `arr[0] (1)` and `arr[1] (2)`. Since `1 <= 2`, keep checking.
   - Recursively call `isSorted(arr, 1)`.
2. `isSorted(arr, 1)`:
   - Index `1 < 3`.
   - Compare `arr[1] (2)` and `arr[2] (4)`. Since `2 <= 4`, keep checking.
   - Recursively call `isSorted(arr, 2)`.
3. `isSorted(arr, 2)`:
   - Index `2 < 3`.
   - Compare `arr[2] (4)` and `arr[3] (3)`. Since `4 > 3`, the array is unsorted.
   - Return `false`.
4. The recursion stack unwinds and returns `false` as the final result.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    bool isSorted(vector<int>& arr, int i = 0) {
        int n = arr.size();

        if (i >= n - 1)
            return true;

        if (arr[i] > arr[i + 1])
            return false;

        return isSorted(arr, i + 1);
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $O(N)$ - We visit each element of the array at most once, where $N$ is the size of the array.
- **Space Complexity**: $O(N)$ - The recursion stack depth can go up to $N$ in the worst case (when the array is sorted).
