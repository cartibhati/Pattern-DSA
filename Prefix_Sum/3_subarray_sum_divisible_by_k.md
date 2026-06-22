# Subarray Sums Divisible by K (LeetCode 974)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/subarray-sum-divisible-by-k/)**

---

## 📝 Problem Description

Given an integer array `nums` and an integer `k`, return the number of non-empty subarrays that have a sum divisible by `k`.

---

## 💡 Intuition & Core Logic

Maintain a running prefix sum and compute its remainder modulo `k`. If a remainder repeats, the elements in between sum to a multiple of `k`. Adjust negative remainders using `(rem + k) % k`. Use a hash map to keep track of remainder frequencies.

---

## 🔄 Step-by-Step Dry Run

For `nums = [4, 5, 0, -2, -3, 1]`, `k = 5`.
- Hash Map starts with `{0: 1}`.

| Index | Value | Pref Sum | Remainder `(sum%k+k)%k` | Freq in Map | Count Added | Map State |
|---|---|---|---|---|---|---|
| 0 | 4 | 4 | 4 | 0 | 0 | `{0:1, 4:1}` |
| 1 | 5 | 9 | 4 | 1 | 1 | `{0:1, 4:2}` |
| 2 | 0 | 9 | 4 | 2 | 2 | `{0:1, 4:3}` |
| 3 | -2 | 7 | 2 | 0 | 0 | `{0:1, 4:3, 2:1}` |
| 4 | -3 | 4 | 4 | 3 | 3 | `{0:1, 4:4, 2:1}` |
| 5 | 1 | 5 | 0 | 1 | 1 | `{0:2, 4:4, 2:1}` |

Result = **7**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0;
        int ans=0;
        unordered_map<int,int>f;
        f[0]=1;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0){
                rem+=k;
            }
            ans+=f[rem];
            f[rem]++;
        }
        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(K)` - Auxiliary space usage details.
