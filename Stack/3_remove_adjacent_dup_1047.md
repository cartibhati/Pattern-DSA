# Remove All Adjacent Duplicates In String (LeetCode 1047)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)**

---

## 📝 Problem Description

Remove adjacent duplicate letters repeatedly until none remain.

---

## 💡 Intuition & Core Logic

Traverse string. If stack is not empty and top matches current character, pop from stack. Otherwise, push character. Reverse the stack characters at the end.

---

## 🔄 Step-by-Step Dry Run

For `s = "abbaca"`.
- i=0 'a': push -> Stack=`['a']`.
- i=1 'b': push -> Stack=`['a','b']`.
- i=2 'b': matches top -> pop -> Stack=`['a']`.
- i=3 'a': matches top -> pop -> Stack=`[]`.
- i=4 'c': push -> Stack=`['c']`.
- i=5 'a': push -> Stack=`['c','a']`.
- Result stack reversed = `"ca"`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;

        for(char c : s){
            if(!st.empty() && st.top() == c){
                st.pop();  // remove duplicate
            } else {
                st.push(c);
            }
        }

        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N)` - Auxiliary space usage details.
