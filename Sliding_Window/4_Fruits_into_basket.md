# Fruit Into Baskets (LeetCode 904)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/fruit-into-baskets/)**

---

## 📝 Problem Description

Find the length of the longest contiguous subarray that contains at most 2 distinct integers.

---

## 💡 Intuition & Core Logic

Equivalent to sliding window with at most 2 unique elements. Maintain a frequency map. Expand `right`. If map size > 2, shrink from `left` until map size <= 2. Update max window size.

---

## 🔄 Step-by-Step Dry Run

For `fruits = [1, 2, 3, 2, 2]`.
- right=0 (1), right=1 (2) -> map={1:1, 2:1}, max=2.
- right=2 (3) -> map={1:1, 2:1, 3:1}. size > 2. Shrink left: remove 1. map={2:1, 3:1}. left=1.
- right=3 (2) -> map={2:2, 3:1}. max=3.
- right=4 (2) -> map={2:3, 3:1}. max=4.
- Return **4**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int totalFruit(vector<int>& s) {
        int low=0;
        int high=0;
        int n=s.size();
        int ans=-1;
        int k=2;
        unordered_map<int,int>f;
        for(int high=0;high<n;high++){
            f[s[high]]++;
            while(f.size()>k){
                f[s[low]]--;
                if(f[s[low]]==0)
                f.erase(s[low]);
                low++;
            }
            if (f.size() == k || f.size()<k) {
                ans = max(ans, high - low + 1);
            }
        }

        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
