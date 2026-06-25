# First Unique Character in a String (LeetCode 387)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/first-unique-character-in-a-string/)**

---

## 📝 Problem Description

Given a string `s`, find the first non-repeating character in it and return its index. If it does not exist, return `-1`.

---

## 💡 Intuition & Core Logic

1. **Frequency Mapping**: Iterate through the string `s` and record the frequency of each character in a hashmap.
2. **Find First Unique**: Iterate through the string `s` a second time. The first character we encounter with a frequency count of `1` is the first unique character. Return its index.
3. **Fallback**: If no such character is found after scanning the entire string, return `-1`.

---

## 🔄 Step-by-Step Dry Run

For `s = "leetcode"`.
1. **First Pass (Build Frequency Map)**:
   - `l` -> 1
   - `e` -> 3
   - `t` -> 1
   - `c` -> 1
   - `o` -> 1
   - `d` -> 1

2. **Second Pass (Find Index)**:
   - `i = 0`: `s[0] = 'l'`. Frequency of `l` is `1`. We immediately return `0`.

For `s = "loveleetcode"`.
1. **First Pass**:
   - `l` -> 2, `o` -> 2, `v` -> 1, `e` -> 4, `t` -> 1, `c` -> 1, `d` -> 1
2. **Second Pass**:
   - `i = 0`: `s[0] = 'l'`. Freq = 2
   - `i = 1`: `s[1] = 'o'`. Freq = 2
   - `i = 2`: `s[2] = 'v'`. Freq = 1. Return `2`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int n=s.size();
        unordered_map<char,int>f;
        for(int i=0;i<n;i++){
            f[s[i]]++;
        }
        for(int i=0;i<n;i++){
            if(f[s[i]]==1)
            return i;
        }
        return -1;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` — We iterate through the string of length `N` exactly twice. Hashmap lookups and updates take `O(1)` average time.
- **Space Complexity**: `O(1)` — The size of the hashmap is bounded by the size of the alphabet (at most 26 unique lowercase English letters), which is constant space.
