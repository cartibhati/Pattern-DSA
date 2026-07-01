# Find Minimum in Rotated Sorted Array II (LeetCode 154)

![Hard](https://img.shields.io/badge/Difficulty-Hard-red)
🔗 **[Problem Link](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)**

---

## 📝 Problem Description

Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times. For example, the array `nums = [0,1,4,4,5,6,7]` might become:
- `[4,5,6,7,0,1,4]` if it was rotated 4 times.
- `[0,1,4,4,5,6,7]` if it was rotated 7 times.

Given the sorted rotated array `nums` that may contain **duplicates**, return *the minimum element of this array*.

You must write an algorithm that runs in `O(log n)` time on average, but could degrade to `O(n)` in the worst case.

---

## 💡 Intuition & Core Logic

1. **Handling Duplicates**:
   - Similar to the unique elements version, we use Binary Search.
   - However, since there are duplicates, we can encounter a case where `nums[mid] == nums[e]`. In this scenario, we cannot confidently determine whether the minimum element lies to the left or right of `mid`.
   - **Example**: `nums = [1, 0, 1, 1, 1]` vs `nums = [1, 1, 1, 0, 1]`. In both cases, `nums[s] == nums[mid] == nums[e]`.
2. **Search Strategy**:
   - Maintain search boundaries `s` (start) and `e` (end).
   - **Case 1: `nums[mid] < nums[e]`**
     - The right half is sorted. The minimum element must reside in the left half, and `mid` itself could be the minimum.
     - Action: `e = mid`.
   - **Case 2: `nums[mid] > nums[e]`**
     - The minimum element lies strictly in the right half (inflection point is to the right of `mid`).
     - Action: `s = mid + 1`.
   - **Case 3: `nums[mid] == nums[e]`**
     - We cannot decide which half to discard.
     - However, since `nums[mid] == nums[e]`, we can safely decrement `e` by 1 (`e--`) without losing the minimum element. If `nums[e]` was the unique minimum, `nums[mid]` (which is equal to it) will still be preserved in our search range.
3. **Termination**: When `s == e`, the boundaries converge to the minimum element. We return `nums[s]`.

---

## 🔄 Step-by-Step Dry Run

For `nums = [2, 2, 2, 0, 1]`.

- **Initialization**: `s = 0`, `e = 4`
1. **Iteration 1**:
   - `mid = 0 + (4 - 0) / 2 = 2`
   - `nums[mid] = nums[2] = 2`
   - Compare `nums[mid]` with `nums[e]`: `nums[2] (2) == nums[4] (1)` $\rightarrow$ Since `2 > 1`, `nums[mid] > nums[e]`.
   - Minimum lies in the right half.
   - Update `s = mid + 1 = 3`.
2. **Iteration 2**:
   - `mid = 3 + (4 - 3) / 2 = 3`
   - `nums[mid] = nums[3] = 0`
   - Compare `nums[mid]` with `nums[e]`: `nums[3] (0) < nums[4] (1)`.
   - Right half is sorted, `mid` could be minimum.
   - Update `e = mid = 3`.
- **Termination**: `s (3) == e (3)`. Loop terminates.
- **Result**: `nums[3] = 0`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {

        int s = 0;
        int e = nums.size() - 1;

        while(s < e){

            int mid = s + (e - s)/2;

            if(nums[mid] < nums[e]){
                e = mid;
            }
            else if(nums[mid] > nums[e]){
                s = mid + 1;
            }
            else{
                e--;
            }
        }

        return nums[s];
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**:
  - **Average Case**: `O(log N)` — In each step where `nums[mid] != nums[e]`, we halve the search space.
  - **Worst Case**: `O(N)` — When all elements are duplicates (e.g., `[1, 1, 1, 1]`), the algorithm decrements `e` one by one, leading to linear time complexity.
- **Space Complexity**: `O(1)` — Only constant auxiliary space is used.
