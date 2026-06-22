# Maximum Absolute Sum of Any Subarray (LeetCode 1749)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/)**

---

## 📝 Problem Description

Find the maximum absolute sum of any contiguous subarray.

---

## 💡 Intuition & Core Logic

The maximum absolute sum is `max(max_subarray_sum, abs(min_subarray_sum))`. We run Kadane's max sum and Kadane's min sum and take the max of the two results.

---

## 🔄 Step-by-Step Dry Run

For `nums = [1, -3, 2, 3, -4]`.
- Max subarray sum: `[2, 3]` -> sum = 5.
- Min subarray sum: `[-3]` -> sum = -3.
- Absolute max = max(5, abs(-3)) = 5. Return **5**.

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
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int i=0;
        int bestend=a[0];
        int ans=a[0];
        for(int i=1;i<a.size();i++){
            int v1=bestend+a[i];
            int v2=a[i];
            bestend=min(v1,v2);
            ans=min(ans,bestend);
        }
        return ans;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=maxSubArray(nums);
        int mini=smallestSumSubarray(nums);
        int ans=max(maxi,mini);
        return max(maxi, abs(mini));
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
