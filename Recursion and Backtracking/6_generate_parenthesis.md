# Generate Parentheses

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/generate-parentheses/)**

---

## 📝 Problem Description

Given `n` pairs of parentheses, write a function to *generate all combinations of well-formed parentheses*.

---

## 💡 Intuition & Core Logic

This problem can be solved using **Backtracking / Recursion**.
At each step, we can either add an opening parenthesis `'('` or a closing parenthesis `')'`, provided they satisfy the rules of a well-formed parenthesis sequence:
1. **Opening Parentheses**: We can add an opening parenthesis `'('` as long as the count of open parentheses (`open`) is less than `n`.
2. **Closing Parentheses**: We can add a closing parenthesis `')'` as long as the count of closed parentheses (`close`) is less than the count of open parentheses (`open`). This ensures that we never add a closing parenthesis without a matching opening parenthesis.
3. **Base Case**: When the number of open and close parentheses both reach `n`, we have found a valid combination. We add it to our results and return.

---

## 🔄 Step-by-Step Dry Run

For `n = 2`:
Starting with `open = 0`, `close = 0`, `tmp = ""`

1. `fun(0, 0, 2, "", res)`:
   - `open < n` (0 < 2) -> Push `'('` -> `tmp = "("` -> Call `fun(1, 0, 2, "(", res)`
2. `fun(1, 0, 2, "(", res)`:
   - `open < n` (1 < 2) -> Push `'('` -> `tmp = "(("` -> Call `fun(2, 0, 2, "((", res)`
     - In `fun(2, 0, 2, "((", res)`:
       - `open == n` (2 == 2) -> Cannot add `'('`.
       - `close < open` (0 < 2) -> Push `')'` -> `tmp = "(()"` -> Call `fun(2, 1, 2, "(()", res)`
       - In `fun(2, 1, 2, "(()", res)`:
         - `open == n` -> Cannot add `'('`.
         - `close < open` (1 < 2) -> Push `')'` -> `tmp = "(())"` -> Call `fun(2, 2, 2, "(())", res)`
         - In `fun(2, 2, 2, "(())", res)`:
           - `open == n` and `close == n` (2 == 2) -> **Goal Reached**. Add `"(())"` to `res`. Return and backtrack.
     - Backtrack from `((` -> `close < open` (0 < 1) -> Push `')'` -> `tmp = "()"` -> Call `fun(1, 1, 2, "()", res)`
3. `fun(1, 1, 2, "()", res)`:
   - `open < n` (1 < 2) -> Push `'('` -> `tmp = "()("` -> Call `fun(2, 1, 2, "()(", res)`
     - In `fun(2, 1, 2, "()(", res)`:
       - `open == n` -> Cannot add `'('`.
       - `close < open` (1 < 2) -> Push `')'` -> `tmp = "()()"` -> Call `fun(2, 2, 2, "()()", res)`
       - In `fun(2, 2, 2, "()()", res)`:
         - `open == n` and `close == n` (2 == 2) -> **Goal Reached**. Add `"()()"` to `res`. Return and backtrack.
   - `close < open` (1 < 1 is false) -> Cannot add `')'`.

Final combinations: `["(())", "()()"]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    void fun(int open, int close, int n, string &tmp, vector<string> &res) {
        if (open == n && close == n) {
            res.push_back(tmp);
            return;
        }

        if (open < n) {
            tmp.push_back('(');
            fun(open + 1, close, n, tmp, res);
            tmp.pop_back();
        }

        if (close < open) {
            tmp.push_back(')');
            fun(open, close + 1, n, tmp, res);
            tmp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string tmp = "";
        fun(0, 0, n, tmp, res);
        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $O(\frac{4^n}{\sqrt{n}})$ — The number of valid parentheses sequences is given by the $n$-th Catalan number $C_n = \frac{1}{n+1}\binom{2n}{n}$, which is asymptotically bounded by $\frac{4^n}{n\sqrt{n}}$. Each sequence takes $O(n)$ to copy.
- **Space Complexity**: $O(n)$ — The depth of the recursion stack is at most $2n$ (since the length of the parenthesis string is at most $2n$).
