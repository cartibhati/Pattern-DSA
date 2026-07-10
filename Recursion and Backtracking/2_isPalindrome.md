# Palindrome String (GFG)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://www.geeksforgeeks.org/problems/palindrome-string0817/1)**

---

## 📝 Problem Description

Given a string `s`, check if it is palindrome or not. A string is a palindrome if it reads the same backward as forward.

---

## 💡 Intuition & Core Logic

A string is a palindrome if:
1. The first and last characters are equal.
2. The substring remaining after removing the first and last characters is also a palindrome.

We can solve this recursively:
1. **Base Cases**: 
   - If the length of the current substring (`len`) is `0` or `1`, return `true` (an empty string or single-character string is always a palindrome).
2. **Recursive Step**:
   - Compare characters at index `low` and `high`. If `s[low] != s[high]`, return `false`.
   - Otherwise, recursively check the inner substring by calling `ispal(s, low + 1, high - 1)`.

---

## 🔄 Step-by-Step Dry Run

For `s = "abba"`:
1. `isPalindrome("abba")` calls `ispal(s, 0, 3)`.
2. In `ispal(s, 0, 3)`:
   - `len = 3 - 0 + 1 = 4`.
   - `s[0] == s[3]` ('a' == 'a').
   - Recursively call `ispal(s, 1, 2)`.
3. In `ispal(s, 1, 2)`:
   - `len = 2 - 1 + 1 = 2`.
   - `s[1] == s[2]` ('b' == 'b').
   - Recursively call `ispal(s, 2, 1)`.
4. In `ispal(s, 2, 1)`:
   - `len = 1 - 2 + 1 = 0`.
   - Base case reached: `len == 0` returns `true`.
5. The stack unwinds and returns `true`.

---

## 💻 C++ Working Code

```cpp
class Solution {
  public:
    bool ispal(string &s, int low, int high) {
        int len = high - low + 1;

        if (len == 0 || len == 1)
            return true;

        if (s[low] != s[high])
            return false;

        return ispal(s, low + 1, high - 1);
    }

    bool isPalindrome(string &s) {
        return ispal(s, 0, s.size() - 1);
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $O(N)$ - We check at most $N/2$ pairs of characters, where $N$ is the length of the string.
- **Space Complexity**: $O(N)$ - The recursion stack space is proportional to the depth of recursion, which is at most $N/2$ in the worst case.
