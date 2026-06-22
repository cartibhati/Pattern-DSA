# Valid Parentheses (LeetCode 20)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/valid-parentheses/)**

---

## 📝 Problem Description

Determine if an input string containing brackets is valid.

---

## 💡 Intuition & Core Logic

Traverse the string. Push opening brackets to stack. For closing brackets, check if stack is not empty and matches top. If yes, pop. After traversal, stack must be empty.

---

## 🔄 Step-by-Step Dry Run

For `s = "()[]{}"`.
- i=0 '(': push -> Stack=`['(']`.
- i=1 ')': matches top -> pop -> Stack=`[]`.
- i=2 '[': push -> Stack=`['[']`.
- i=3 ']': matches top -> pop -> Stack=`[]`...
- Return **true**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty()) {
                    return false;
                }

                if ((st.top() == '(' && s[i] == ')') ||
                    (st.top() == '[' && s[i] == ']') ||
                    (st.top() == '{' && s[i] == '}')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N)` - Auxiliary space usage details.
