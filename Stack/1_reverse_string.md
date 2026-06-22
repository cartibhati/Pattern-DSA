# Reverse String (LeetCode 344)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/reverse-string/)**

---

## 📝 Problem Description

Reverse a string in-place using a stack.

---

## 💡 Intuition & Core Logic

Push all characters of the input vector/string onto a stack. Pop them one by one and write them back into the vector from index 0.

---

## 🔄 Step-by-Step Dry Run

For `s = ["h","e","l","l","o"]`.
- Push all characters. Stack = `[h, e, l, l, o]` (top is 'o').
- Pop: write 'o' to index 0, 'l' to index 1... Result = `["o","l","l","e","h"]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        stack<char> st;

        for (char c : s) {
            st.push(c);
        }

        int i = 0;
        while (!st.empty()) {
            s[i++] = st.top();
            st.pop();
        }
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N)` - Auxiliary space usage details.
