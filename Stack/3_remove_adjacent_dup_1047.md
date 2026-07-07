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
        // Stack to store characters during traversal
        stack<char> st;

        // Traverse each character of the string
        for(char c : s){
            // If stack is not empty and the current character matches
            // the top character of the stack, we found an adjacent duplicate.
            // Pop the matching character to remove it.
            if(!st.empty() && st.top() == c){
                st.pop();  // remove duplicate
            } else {
                // Otherwise, push the current character onto the stack
                st.push(c);
            }
        }

        // Reconstruct the remaining string from the stack
        string res = "";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }

        // Since elements are popped in reverse (LIFO), reverse the result string
        reverse(res.begin(), res.end());
        return res;
    }
};

// Alternative Version using index-based loop:
// class Solution {
// public:
//     string removeDuplicates(string s) {
//         stack<char>st; // Stack to keep track of characters
//         for(int i=0;i<s.size();i++){
//             // Check if stack is not empty and current char matches the top
//             if(!st.empty() && s[i]==st.top())
//                 st.pop(); // Remove the adjacent duplicate
//             else
//                 st.push(s[i]); // Push the non-duplicate character
//         }
//         
//         // Retrieve elements from stack (will be in reverse order)
//         string res = "";
//         while(!st.empty()){
//             res.push_back(st.top());
//             st.pop();
//         }
// 
//         // Reverse the string to get the correct original order
//         reverse(res.begin(), res.end());
//         return res;
//     }
// };
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N)` - Auxiliary space usage details.
