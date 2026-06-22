# Longest Substring Without Repeating Characters (LeetCode 3)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/)**

---

## 📝 Problem Description

Given a string `s`, find the length of the longest substring without repeating characters.

---

## 💡 Intuition & Core Logic

Use a sliding window with a hash set or frequency map. If the character at `right` is already present, shrink `left` until the repeating character is removed. Update max length.

---

## 🔄 Step-by-Step Dry Run

For `s = "abcabcbb"`.
- right=0 (a): set={a}, max=1.
- right=1 (b): set={a,b}, max=2.
- right=2 (c): set={a,b,c}, max=3.
- right=3 (a): duplicate 'a' found. Shrink left: remove 'a' (index 0). left becomes 1. Add 'a'. set={b,c,a}, max=3.
- Repeat for 'b' and 'c'.
- Return **3**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low=0;
        int high=0;
        int ans=INT_MIN;
        int n=s.size();
        unordered_map<char,int>f;
        for(int high=0;high<n;high++){
            f[s[high]]++;
            int k=high-low+1;

            while(f.size()<k){
                f[s[low]]--;
                if(f[s[low]]==0)
                f.erase(s[low]);
                low++;
                k=high-low+1;
            }
            ans=max(ans,high-low+1);
        }
        if(ans==INT_MIN)
       return 0;
       return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(min(M, A)) where A is alphabet size` - Auxiliary space usage details.
