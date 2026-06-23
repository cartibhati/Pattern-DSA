# Remove All Adjacent Duplicates in String II (LeetCode 1209)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/)**

---

## 📝 Problem Description

You are given a string `s` and an integer `k`, a `k` duplicate removal consists of choosing `k` adjacent and equal letters from `s` and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make `k` duplicate removals on `s` until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

---

## 💡 Intuition & Core Logic

Instead of just keeping track of characters, we can keep track of the count of consecutive identical characters.
We can use a stack of pairs: `stack<pair<char, int>>` where:
- The first element is the character.
- The second element is the count of its consecutive occurrences so far.

For each character `c` in the string:
1. If the stack is empty, push `{c, 1}`.
2. If the top of the stack has a different character, push `{c, 1}`.
3. If the top of the stack has the same character:
   - If the count is less than `k - 1`, we pop the top, increment its count, and push it back.
   - If the count is equal to `k - 1`, it means adding this character makes the group of size `k`. So, we pop the top of the stack and do NOT push anything (conceptually removing the `k` adjacent duplicates).

Finally, we rebuild the string from the stack and reverse it.

---

## 🔄 Step-by-Step Dry Run

For `s = "deeedbbcccbdaa"` and `k = 3`.

| Step | Char `c` | Stack State (top on the right) | Action & Notes |
|---|---|---|---|
| 0 | `'d'` | `[{'d', 1}]` | Stack is empty. Push `{'d', 1}`. |
| 1 | `'e'` | `[{'d', 1}, {'e', 1}]` | Top is `'d'`. Push `{'e', 1}`. |
| 2 | `'e'` | `[{'d', 1}, {'e', 2}]` | Top is `'e'`. Increment count to 2. |
| 3 | `'e'` | `[{'d', 1}]` | Top is `'e'` with count 2. Adding 3rd `'e'` triggers removal of 3 consecutive `'e'`s. Pop. |
| 4 | `'d'` | `[{'d', 2}]` | Top is `'d'`. Increment count to 2. |
| 5 | `'b'` | `[{'d', 2}, {'b', 1}]` | Top is `'d'`. Push `{'b', 1}`. |
| 6 | `'b'` | `[{'d', 2}, {'b', 2}]` | Top is `'b'`. Increment count to 2. |
| 7 | `'c'` | `[{'d', 2}, {'b', 2}, {'c', 1}]` | Top is `'b'`. Push `{'c', 1}`. |
| 8 | `'c'` | `[{'d', 2}, {'b', 2}, {'c', 2}]` | Top is `'c'`. Increment count to 2. |
| 9 | `'c'` | `[{'d', 2}, {'b', 2}]` | Top is `'c'` with count 2. Adding 3rd `'c'` triggers removal. Pop. |
| 10 | `'b'` | `[{'d', 2}]` | Top is `'b'` with count 2 (from step 6). Adding 3rd `'b'` triggers removal. Pop. |
| 11 | `'d'` | `[]` | Top is `'d'` with count 2 (from step 4). Adding 3rd `'d'` triggers removal. Pop. |
| 12 | `'a'` | `[{'a', 1}]` | Stack is empty. Push `{'a', 1}`. |
| 13 | `'a'` | `[{'a', 2}]` | Top is `'a'`. Increment count to 2. |

**Reconstructing String**:
- Rebuild from stack: `{'a', 2}` -> `"aa"`.
- Reverse `"aa"` -> `"aa"`.

**Result**: `"aa"`

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){

            char c = s[i];

            if(st.empty()){
                st.push({c,1});
                continue;
            }
            if(st.top().first != c){
                st.push({c,1});
                continue;
            }
            if(st.top().second < (k-1)){
                pair<char,int>p = st.top();
                st.pop();
                st.push({p.first , p.second+1});
                continue;
            }
            st.pop();
        }

        string res="";
        while(!st.empty()){
            pair<char,int>p = st.top();
            st.pop();
            while(p.second--){
                res.push_back(p.first);
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We traverse the string of length `N` once. Each character is pushed and popped from the stack at most once. Rebuilding the string takes `O(N)` time.
- **Space Complexity**: `O(N)` - In the worst case, the stack can store up to `N` characters if there are no duplicates.
