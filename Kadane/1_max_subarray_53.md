# Maximum Subarray (LeetCode 53)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/maximum-subarray/)**

---

## 📝 Problem Description

Find the contiguous subarray which has the largest sum and return its sum.

---

## 💡 Intuition & Core Logic

Track `bestend` (max subarray sum ending here) and global max `ans`. At each element: `bestend = max(val, bestend + val)`, and `ans = max(ans, bestend)`.

---

## 🔄 Step-by-Step Dry Run

For `nums = [-2, 1, -3, 4]`.
- i=0: bestend = -2, ans = -2.
- i=1 (1): bestend = max(1, -2+1) = 1. ans = 1.
- i=2 (-3): bestend = max(-3, 1-3) = -2. ans = 1.
- i=3 (4): bestend = max(4, -2+4) = 4. ans = 4.
- Return **4**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i=0;
        int bestend=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            int v1=bestend+nums[i];
            int v2=nums[i];
            bestend=max(v1,v2);
            ans=max(ans,bestend);
        }
        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
