# Remove Character Occurrences (Recursive)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://www.geeksforgeeks.org/recursive-program-to-remove-all-occurrences-of-a-char-from-string/)**

---

## 📝 Problem Description

Given a string `s` and a character `c`, write a recursive function to remove all occurrences of the character `c` from the string.

---

## 💡 Intuition & Core Logic

We can traverse the string and modify it in place:
1. **Base Case**:
   - If index `i` is equal to the size of the string `s`, we have traversed the entire string. Return.
2. **Recursive Step**:
   - If the current character `s[i]` is equal to target character `c`:
     - Erase the character at index `i` using `s.erase(i, 1)`.
     - Since erasing a character shifts the subsequent characters to the left, the element at index `i` is now a new character. Therefore, we recursively call the function staying at the **same index** `i`.
   - If `s[i]` is not equal to `c`:
     - Keep the character and recurse on the **next index** `i + 1`.

---

## 🔄 Step-by-Step Dry Run

For `s = "geeks"`, `c = 'e'`:
1. `removeCharacter(s, 'e', 0)`:
   - `s[0] = 'g' != 'e'`.
   - Recurse on next index: `removeCharacter(s, 'e', 1)`.
2. `removeCharacter(s, 'e', 1)`:
   - `s[1] = 'e' == 'e'`.
   - Erase character at index `1`. String becomes `"geks"`.
   - Recurse on same index: `removeCharacter(s, 'e', 1)`.
3. `removeCharacter(s, 'e', 1)`:
   - `s[1] = 'e' == 'e'`.
   - Erase character at index `1`. String becomes `"gks"`.
   - Recurse on same index: `removeCharacter(s, 'e', 1)`.
4. `removeCharacter(s, 'e', 1)`:
   - `s[1] = 'k' != 'e'`.
   - Recurse on next index: `removeCharacter(s, 'e', 2)`.
5. `removeCharacter(s, 'e', 2)`:
   - `s[2] = 's' != 'e'`.
   - Recurse on next index: `removeCharacter(s, 'e', 3)`.
6. `removeCharacter(s, 'e', 3)`:
   - Index `3 == s.size()` (size of `"gks"` is 3).
   - Base case reached: Return.
7. Result string is `"gks"`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    void removeCharacter(string &s, char c, int i = 0) {
        if (i == s.size())
            return;

        if (s[i] == c) {
            s.erase(i, 1);
            removeCharacter(s, c, i);   // stay at same index
        } else {
            removeCharacter(s, c, i + 1);
        }
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $O(N^2)$ - In the worst case, we make $N$ recursive steps. However, each `s.erase` call shifts remaining characters to the left, which takes $O(N)$ time. Thus, the total time complexity is $O(N^2)$.
- **Space Complexity**: $O(N)$ - The recursion stack depth can go up to $N$ in the worst case (e.g. if no characters match).
