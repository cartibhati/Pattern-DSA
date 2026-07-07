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
        // Create a stack to store characters (Last In First Out - LIFO)
        stack<char> st;

        // Push all characters of the vector onto the stack
        for (char c : s) {
            st.push(c);
        }

        // Pop all characters from the stack and write them back to
        // the vector from the beginning (index 0). This reverses the string.
        int i = 0;
        while (!st.empty()) {
            s[i++] = st.top();
            st.pop();
        }
    }
};

// Alternative Version using stack<int> and index-based loop:
// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         stack<int>st; // Stack storing ASCII integer values of characters
//         for(int i=0;i<s.size();i++)
//             st.push(s[i]); // Push characters (implicitly cast to int)
//         
//         int i=0;
//         while(!st.empty()){
//             s[i]=st.top(); // Retrieve top integer and cast back to char
//             i++;
//             st.pop();
//         }
//     }
// };
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N)` - Auxiliary space usage details.
