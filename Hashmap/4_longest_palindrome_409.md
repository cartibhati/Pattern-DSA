# Longest Palindrome (LeetCode 409)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/longest-palindrome/)**

---

## 📝 Problem Description

Given a string `s` which consists of lowercase or uppercase letters, return the length of the **longest palindrome** that can be built with those letters.

Letters are **case sensitive**, for example, `"Aa"` is not considered a palindrome.

---

## 💡 Intuition & Core Logic

A palindrome reads the same backwards as forwards. To form a palindrome:
1. **Even Frequency**: Any character that appears an even number of times can be placed symmetrically on both sides of the center (e.g., `a...a`, `bb...bb`). Thus, we can use all of its occurrences.
2. **Odd Frequency**: For any character that appears an odd number of times (say, $k$ times), we can use the largest even number of those characters ($k - 1$) symmetrically.
3. **The Center Piece**: A palindrome can have at most **one** unique character in the absolute center. If there is at least one character with an odd frequency, we can choose one of those extra single characters to place in the center, increasing our palindrome length by exactly `1`.

---

## 🔄 Step-by-Step Dry Run

For `s = "abccccdd"`
1. **First Pass (Build Frequency Map & Sum Evens)**:
   - `a` -> 1 (odd, set `odd = true`)
   - `b` -> 1 (odd, set `odd = true`)
   - `c` -> 4 (even, `res += 4` -> `res = 4`)
   - `d` -> 2 (even, `res += 2` -> `res = 6`)
   
2. **Handle Odds**:
   - `odd` is `true`.
   - Iterate to find odd frequencies:
     - `a` (freq = 1): `res += (1 - 1) = 0` -> `res = 6`
     - `b` (freq = 1): `res += (1 - 1) = 0` -> `res = 6`
   - Since `odd` is `true`, return `res + 1` = `7`.
   - *Example palindrome that can be built*: `"ccdadcc"` or `"ccdcdcc"` (length 7).

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>f;
        for(int i=0;i<s.size();i++){
            f[s[i]]++;
        }
        bool odd = false;
        int res=0;
        for(auto i:f){
            int val = i.second;
            if(val%2==0){
                res+=val;
            }
            else
            odd=true;
        }

        if(odd==false)
        return res;

        for(auto i:f){
            int val = i.second;
            if(val%2==1)
            res+=val-1;
        }
        return res+1;//last me string ke bad jitne odd bache unme se kisi ek ko bich me ek bar add krna pdta hai
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` — We traverse the string `s` of length `N` to build the frequency map, and then we traverse the map (at most 52 unique uppercase and lowercase letters), which takes `O(1)` time.
- **Space Complexity**: `O(1)` — The size of the frequency map is bounded by the uppercase and lowercase English alphabets (at most 52 unique keys), which requires constant auxiliary space.
