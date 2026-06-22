# Longest Substring with K Unique Characters (GFG)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://www.geeksforgeeks.org/problems/longest-substring-with-k-unique-characters-in-a-string1612/1)**

---

## 📝 Problem Description

Given a string `s`, find the length of the longest substring that contains exactly K unique characters.

---

## 💡 Intuition & Core Logic

Use sliding window with a frequency map. Move `right` to expand the window. If the number of unique characters in the map exceeds K, shrink from `left` until unique characters <= K. When unique characters == K, update max length.

---

## 🔄 Step-by-Step Dry Run

For `s = "aabacbebebe"`, `K = 3`.
- Window expands to `"aabac"` (len 5). unique = 3. `max_len = 5`.
- Expand to `"aabacb"` (len 6). unique = 3. `max_len = 6`.
- Expand to `"aabacbe"` -> unique = 4. Shrink left until window is `"cbe"`.
- Eventually window expands to `"cbebebe"` (len 7). unique = 3. `max_len = 7`.
- Return **7**.

---

## 💻 C++ Working Code

```cpp
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int low=0;
        int high=0;
        int n=s.size();
        int ans=-1;
        unordered_map<char,int>f;
        for(int high=0;high<n;high++){
            f[s[high]]++;
            
            while(f.size()>k){
                f[s[low]]--;
                if(f[s[low]]==0)
                f.erase(s[low]);
                low++;
            }
            
            if(f.size()==k){
                int len = high-low+1;
                ans= max(ans,len);
            }
        }
        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(A) where A is alphabet size` - Auxiliary space usage details.
