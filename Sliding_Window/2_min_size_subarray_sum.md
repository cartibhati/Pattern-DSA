# Minimum Size Subarray Sum (LeetCode 209)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/minimum-size-subarray-sum/)**

---

## 📝 Problem Description

Given an array of positive integers `nums` and a positive integer `target`, return the minimal length of a contiguous subarray of which the sum is >= target. Return 0 if none exists.

---

## 💡 Intuition & Core Logic

Use a variable-size sliding window with two pointers `left` and `right`. Expand the window by adding `nums[right]` to a running sum. While the sum is >= target, record the window size `right - left + 1` (updating the minimum found) and shrink the window from the left.

---

## 🔄 Step-by-Step Dry Run

For `target = 7`, `nums = [2, 3, 1, 2, 4, 3]`.
- right=0..2: sum = 2+3+1 = 6 < 7.
- right=3: sum = 6+2 = 8 >= 7. min_len = 4. sum -= nums[0] (2) -> 6, left=1.
- right=4: sum = 6+4 = 10 >= 7. min_len = 4. sum -= nums[1] (3) -> 7 >= 7. min_len = 3. sum -= nums[2] (1) -> 6, left=3.
- right=5: sum = 6+3 = 9 >= 7. min_len = 3. sum -= nums[3] (2) -> 7 >= 7. min_len = 2. sum -= nums[4] -> 3, left=5.
- Return **2**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low=0;
        int high=0;
        int ans=INT_MAX;
        int sum=0;
        while(high<nums.size()){
            sum=sum+nums[high];
            while(sum>=target){
                int len=high-low+1;
                ans=min(ans,len);
                sum=sum-nums[low];
                low++;
            }
            high++;
        }
        return (ans == INT_MAX) ? 0 : ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
