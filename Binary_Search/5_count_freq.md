# Number of Occurrence (GFG)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://www.geeksforgeeks.org/problems/number-of-occurrence2159/1)**

---

## 📝 Problem Description

Given a sorted array `arr[]` and a number `target`, write a function that counts the occurrences of `target` in `arr[]`. If `target` is not present in `arr[]`, return `0`.

Expected Time Complexity is `O(log N)`.

---

## 💡 Intuition & Core Logic

1. **Binary Search**: Since the array is sorted, we can search for the target's occurrences efficiently.
2. **First and Last Occurrence**:
   - The number of occurrences of a target is given by `(last_occurrence_index - first_occurrence_index + 1)`.
   - We implement `firstOccurrence()` to find the first index of `target` in the array.
   - We implement `lastOccurrence()` to find the last index of `target` in the array.
   - If `firstOccurrence()` returns `-1`, it means the target does not exist in the array, so we return `0`.
3. **Complexity**: Each search takes `O(log N)` time, resulting in an overall time complexity of `O(log N)`.

---

## 🔄 Step-by-Step Dry Run

For `arr = [1, 1, 2, 2, 2, 2, 3]`, `target = 2`.

### Finding First Occurrence:
- **Initialization**: `s = 0`, `e = 6`, `ans = -1`
1. **Iteration 1**:
   - `mid = 0 + (6 - 0) / 2 = 3`
   - `arr[3] = 2 == 2` $\rightarrow$ candidate `ans = 3`, search left: `e = mid - 1 = 2`
2. **Iteration 2**:
   - `mid = 0 + (2 - 0) / 2 = 1`
   - `arr[1] = 1 < 2` $\rightarrow$ search right: `s = mid + 1 = 2`
3. **Iteration 3**:
   - `mid = 2 + (2 - 2) / 2 = 2`
   - `arr[2] = 2 == 2` $\rightarrow$ candidate `ans = 2`, search left: `e = mid - 1 = 1`
- **Termination**: `s (2) > e (1)`. First occurrence index is `2`.

### Finding Last Occurrence:
- **Initialization**: `s = 0`, `e = 6`, `ans = -1`
1. **Iteration 1**:
   - `mid = 0 + (6 - 0) / 2 = 3`
   - `arr[3] = 2 == 2` $\rightarrow$ candidate `ans = 3`, search right: `s = mid + 1 = 4`
2. **Iteration 2**:
   - `mid = 4 + (6 - 4) / 2 = 5`
   - `arr[5] = 2 == 2` $\rightarrow$ candidate `ans = 5`, search right: `s = mid + 1 = 6`
3. **Iteration 3**:
   - `mid = 6 + (6 - 6) / 2 = 6`
   - `arr[6] = 3 > 2` $\rightarrow$ search left: `e = mid - 1 = 5`
- **Termination**: `s (6) > e (5)`. Last occurrence index is `5`.

### Final Count:
- `first = 2`, `last = 5`
- `count = 5 - 2 + 1 = 4`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int firstOccurrence(vector<int>& arr, int target) {
        int s = 0, e = arr.size() - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) {
                ans = mid;
                e = mid - 1;
            }
            else if (arr[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return ans;
    }

    int lastOccurrence(vector<int>& arr, int target) {
        int s = 0, e = arr.size() - 1;
        int ans = -1;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (arr[mid] == target) {
                ans = mid;
                s = mid + 1;
            }
            else if (arr[mid] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }

        return ans;
    }

    int countFreq(vector<int>& arr, int target) {
        int first = firstOccurrence(arr, target);

        if (first == -1)
            return 0;

        int last = lastOccurrence(arr, target);

        return last - first + 1;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(log N)` — Finding the first and last occurrence each takes `O(log N)` time.
- **Space Complexity**: `O(1)` — Only constant auxiliary space is used.
