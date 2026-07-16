# Letter Combinations of a Phone Number

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)**

---

## 📝 Problem Description

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

| Digit | Letters |
|---|---|
| 2 | abc |
| 3 | def |
| 4 | ghi |
| 5 | jkl |
| 6 | mno |
| 7 | pqrs |
| 8 | tuv |
| 9 | wxyz |

---

## 💡 Intuition & Core Logic

This problem can be solved using **Backtracking / Recursion**.
At each step of recursion:
1. **Explore Choices**: For the current digit at index `idx` in the input string `digits`, we fetch the mapped letters (choices).
2. **Backtrack**:
   - Loop through each letter in the choices.
   - Append the letter to our current running combination (`diary`).
   - Recursively call the function for the next digit index (`idx + 1`).
   - Backtrack by removing the last appended letter (`diary.pop_back()`) to try other combinations.
3. **Base Case**: When the index `idx` equals the length of `digits`, we have successfully constructed a combination of letters of the same length. We add it to our results vector and return.

---

## 🔄 Step-by-Step Dry Run

For `digits = "23"`:
- Mapping: `'2' -> "abc"`, `'3' -> "def"`
- Call `fun(digits, n=2, idx=0, diary="", res, f)`:

1. **`idx = 0` (digit `'2'`)**:
   - Choices: `"abc"`.
   - Iterate choices:
     - **Choice 1: `'a'`**
       - Push `'a'` -> `diary = "a"`
       - Call `fun(digits, 2, 1, "a", res, f)`
       - **`idx = 1` (digit `'3'`)**:
         - Choices: `"def"`.
         - Iterate choices:
           - **Choice 1: `'d'`**
             - Push `'d'` -> `diary = "ad"`
             - Call `fun(digits, 2, 2, "ad", res, f)`
             - **`idx = 2`**: Base Case (`idx == n`). Add `"ad"` to `res`. Return.
             - Pop `'d'` -> `diary = "a"`
           - **Choice 2: `'e'`**
             - Push `'e'` -> `diary = "ae"`
             - Call `fun(digits, 2, 2, "ae", res, f)`
             - **`idx = 2`**: Base Case. Add `"ae"` to `res`. Return.
             - Pop `'e'` -> `diary = "a"`
           - **Choice 3: `'f'`**
             - Push `'f'` -> `diary = "af"`
             - Call `fun(digits, 2, 2, "af", res, f)`
             - **`idx = 2`**: Base Case. Add `"af"` to `res`. Return.
             - Pop `'f'` -> `diary = "a"`
         - Return from `idx = 1`
       - Pop `'a'` -> `diary = ""`

     - **Choice 2: `'b'`**
       - Push `'b'` -> `diary = "b"`
       - Call `fun(digits, 2, 1, "b", res, f)`
       - ... builds `"bd"`, `"be"`, `"bf"`
       - Pop `'b'` -> `diary = ""`

     - **Choice 3: `'c'`**
       - Push `'c'` -> `diary = "c"`
       - Call `fun(digits, 2, 1, "c", res, f)`
       - ... builds `"cd"`, `"ce"`, `"cf"`
       - Pop `'c'` -> `diary = ""`

Final results: `["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    void fun(string &s, int n, int idx, string &diary, 
             vector<string>& res, unordered_map<char,string>& f) {
        
        if (idx == n) {
            res.push_back(diary);
            return;
        }

        string choice = f[s[idx]];
        for (int j = 0; j < choice.size(); j++) {
            diary.push_back(choice[j]);
            fun(s, n, idx + 1, diary, res, f);
            diary.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> f;
        f['2'] = "abc";
        f['3'] = "def";
        f['4'] = "ghi";
        f['5'] = "jkl";
        f['6'] = "mno";
        f['7'] = "pqrs";
        f['8'] = "tuv";
        f['9'] = "wxyz";

        vector<string> res;
        string diary = "";

        fun(digits, digits.size(), 0, diary, res, f);
        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $\mathcal{O}(4^N \cdot N)$ where $N$ is the number of digits in the input string. In the worst case (digits containing only `7` or `9` which have 4 choices each), there are $4^N$ combinations. For each combination, we perform operations proportional to $N$ to build and copy the string of length $N$.
- **Space Complexity**: $\mathcal{O}(N)$ — The maximum depth of the recursion stack is $N$, representing the length of the input digits.
