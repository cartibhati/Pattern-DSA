# Find Pivot Index (LeetCode 724)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/find-pivot-index/)**

---

## 📝 Problem Description

Given an array of integers `nums`, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. If no such index exists, return -1.

---

## 💡 Intuition & Core Logic

Compute the total sum of the array first. Iterate through the array while maintaining a running `left_sum`. For any index `i`, the `right_sum` is `total_sum - left_sum - nums[i]`. If `left_sum == right_sum`, return the current index `i`. Otherwise, add `nums[i]` to `left_sum` and continue.

---

## 🔄 Step-by-Step Dry Run

For `nums = [1, 7, 3, 6, 5, 6]`, total sum = 28.

| Step | Index | Value | Left Sum | Right Sum | Match? |
|---|---|---|---|---|---|
| 1 | 0 | 1 | 0 | 28 - 0 - 1 = 27 | ❌ No |
| 2 | 1 | 7 | 1 | 28 - 1 - 7 = 20 | ❌ No |
| 3 | 2 | 3 | 1 + 7 = 8 | 28 - 8 - 3 = 17 | ❌ No |
| 4 | 3 | 6 | 8 + 3 = 11 | 28 - 11 - 6 = 11 |  Yes |

Result = **3**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int left = 0;
        int sum = 0;

        for (int x : nums)
            sum += x;

        for (int i = 0; i < nums.size(); i++) {
            int right = sum - left - nums[i];

            if (left == right)
                return i;

            left += nums[i];
        }

        return -1;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
