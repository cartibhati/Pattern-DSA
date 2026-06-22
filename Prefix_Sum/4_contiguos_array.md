# Contiguous Array (LeetCode 525)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/contiguous-array/)**

---

## 📝 Problem Description

Given a binary array `nums`, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

---

## 💡 Intuition & Core Logic

Treat 0 as -1 and 1 as +1. The problem simplifies to finding the maximum length of a subarray with sum 0. Use a hash map to store the first occurrence index of each prefix sum. If a prefix sum is seen again at index `i`, update the max length with `i - map[curr_sum]`.

---

## 🔄 Step-by-Step Dry Run

For `nums = [0, 1, 0]`. Convert to `[-1, 1, -1]`.
- Hash Map starts with `{0: -1}`.
- i=0: `curr_sum = -1`. Not in map. Map = `{0:-1, -1:0}`.
- i=1: `curr_sum = 0`. Seen in map at index -1. Length = `1 - (-1) = 2`. `max_len = 2`.
- i=2: `curr_sum = -1`. Seen in map at index 0. Length = `2 - 0 = 2`. `max_len = max(2, 2) = 2`.

Result = **2**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int zero=0;
        int one=0;
        unordered_map<int,int>f;
        int ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
            else{
                one++;
            }

            int diff=zero-one;
            if(diff==0){
                ans=max(ans,i+1);
                continue;
            }
            if(f.find(diff)==f.end()){
                f[diff]=i;
            }
            else{
                int idx=f[diff];
                int length=i-idx;
                ans=max(length,ans);
            }
        }
        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N)` - Auxiliary space usage details.
