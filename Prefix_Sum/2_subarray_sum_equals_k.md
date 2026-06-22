# Subarray Sum Equals K (LeetCode 560)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/subarray-sum-equals-k/)**

---

## 📝 Problem Description

Given an array of integers `nums` and an integer `k`, return the total number of continuous subarrays whose sum equals to `k`.

---

## 💡 Intuition & Core Logic

Use a hash map to store frequencies of prefix sums. As we traverse, compute prefix sum `curr_sum`. If `curr_sum - k` is present in the hash map, it means there are subarrays ending at the current index that sum to `k`. Add their count to the total. Then insert/update `curr_sum` frequency in the map.

---

## 🔄 Step-by-Step Dry Run

For `nums = [1, 1, 1]`, `k = 2`.
- Hash Map starts with `{0: 1}` (empty prefix).
- i=0: `curr_sum = 1`. `curr_sum - k = -1` (not in map). Map becomes `{0:1, 1:1}`.
- i=1: `curr_sum = 2`. `curr_sum - k = 0` (found in map, freq 1). `count` becomes 1. Map becomes `{0:1, 1:1, 2:1}`.
- i=2: `curr_sum = 3`. `curr_sum - k = 1` (found in map, freq 1). `count` becomes 2. Map becomes `{0:1, 1:1, 2:1, 3:1}`.

Result = **2**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum=0;
        int res=0;
        unordered_map<int,int>f;
        f[0]=1;
        for(int i=0 ;i<nums.size();i++){
            sum+=nums[i];
            int ques=sum-k;
            int freq=f[ques];
            res+=freq;
            f[sum]++;
        }
        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N)` - Auxiliary space usage details.
