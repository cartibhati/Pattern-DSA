# Maximum Sum Circular Subarray (LeetCode 918)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/maximum-sum-circular-subarray/)**

---

## 📝 Problem Description

Find the maximum possible sum of a non-empty subarray of a circular array.

---

## 💡 Intuition & Core Logic

The maximum sum is either non-circular (standard Kadane's max sum) or circular (total sum minus Kadane's min sum). If all elements are negative, return the standard Kadane's max sum.

---

## 🔄 Step-by-Step Dry Run

For `nums = [5, -3, 5]`.
- total_sum = 7. max_sum = 5.
- min_sum = -3.
- circular_sum = 7 - (-3) = 10.
- Return max(5, 10) = **10**.

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
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
        }
        int maxSum = maxSubArray(nums);
        int minSum = smallestSumSubarray(nums);

        int answer = max(maxSum, totalSum - minSum);

        if (maxSum < 0)
            return maxSum;
            
        return answer;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
