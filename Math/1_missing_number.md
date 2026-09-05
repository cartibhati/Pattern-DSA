# Missing Number (LeetCode 268)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/missing-number/)**

---

## 📝 Problem Description

Given an array `nums` containing `n` distinct numbers in the range `[0, n]`, return the only number in the range that is missing from the array.

---

## 💡 Intuition & Core Logic

1. **Mathematical Sum Formula (Gauss' Formula)**:
   - The sum of the first $n$ natural numbers from $0$ to $n$ is given by:
     $$S_{expected} = \frac{n \times (n + 1)}{2}$$
2. **Actual Sum**:
   - Calculate the sum of all elements present in the array `nums`.
3. **Missing Number**:
   - The difference between `expectedSum` and `actualSum` gives the missing number:
     $$\text{Missing Number} = S_{expected} - S_{actual}$$

---

## 🔄 Step-by-Step Dry Run

Consider `nums = [3, 0, 1]`

- **Array length ($n$)**: $3$
- **Expected Sum**: 
  $$n \times (n + 1) / 2 = 3 \times 4 / 2 = 6$$
- **Actual Sum Calculation**:
  - `i = 0`: `actualSum` = $0 + 3 = 3$
  - `i = 1`: `actualSum` = $3 + 0 = 3$
  - `i = 2`: `actualSum` = $3 + 1 = 4$
- **Result**:
  $$\text{expectedSum} - \text{actualSum} = 6 - 4 = 2$$
- Return `2`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expectedSum = n * (n + 1) / 2;
        int actualSum = 0;

        for (int i = 0; i < n; i++) {
            actualSum += nums[i];
        }

        return expectedSum - actualSum;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(N)$ — Single pass over the array of size $N$ to calculate the sum.
- **Space Complexity**: $\mathcal{O}(1)$ — Constant auxiliary space used for variables `expectedSum` and `actualSum`.
