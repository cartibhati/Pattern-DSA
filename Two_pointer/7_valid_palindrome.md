# Valid Palindrome (LeetCode 125)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/valid-palindrome/)**

---

## 📝 Problem Description

A phrase is a **palindrome** if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string `s`, return `true` if it is a palindrome, or `false` otherwise.

---

## 💡 Intuition & Core Logic

Use two pointers:
- `left` starting at the beginning of the string (`0`).
- `right` starting at the end of the string (`n - 1`).

In each step:
1. Increment `left` until it points to an alphanumeric character (using `isalnum`).
2. Decrement `right` until it points to an alphanumeric character.
3. Compare the lowercase versions of characters at both pointers (using `tolower`). If they don't match, return `false`.
4. If they match, increment `left` and decrement `right` to continue scanning.

If the pointers meet or cross, the string is a valid palindrome, so return `true`.

---

## 🔄 Step-by-Step Dry Run

For `s = "A man, a plan, a canal: Panama"`.
- Start: `left = 0` ('A'), `right = 29` ('a').
- Check characters: `tolower('A') == tolower('a')`. Match. `left` becomes 1, `right` becomes 28.
- `left = 1` (' '), which is not alphanumeric. `left` moves to 2 ('m').
- `right = 28` ('m').
- Check characters: `tolower('m') == tolower('m')`. Match. `left` becomes 3, `right` becomes 27.
- ... (continues matching alphanumeric characters in the same way).
- End: Pointers cross and all characters match. Return `true`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int n=s.size();
        int right=n-1;
        while(left<right){
            while (left < right && !isalnum(s[left]))
                left++;

            while (left < right && !isalnum(s[right]))
                right--;
            
            if(tolower(s[left])!=tolower(s[right]))
            return false;
            left++;
            right--;
        }
        return true;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We traverse the string at most once, where `N` is the length of the string.
- **Space Complexity**: `O(1)` - No extra space is used as we modify/compare the string in-place.
