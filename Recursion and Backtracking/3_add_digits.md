# Add Digits (LeetCode 258)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/add-digits/)**

---

## 📝 Problem Description

Given an integer `num`, repeatedly add all its digits until the result has only one digit, and return it.

---

## 💡 Intuition & Core Logic

We can solve this problem recursively:
1. **Base Case**:
   - If the number `n` is less than `10`, it is already a single digit. We can return `n` directly.
2. **Recursive Step**:
   - Calculate the sum of the digits of `n`.
   - Recursively call `addDigits` on this sum.

---

## 🔄 Step-by-Step Dry Run

For `num = 38`:
1. `addDigits(38)`:
   - Since `38 >= 10`, calculate the sum of its digits: `3 + 8 = 11`.
   - Recursively call `addDigits(11)`.
2. `addDigits(11)`:
   - Since `11 >= 10`, calculate the sum of its digits: `1 + 1 = 2`.
   - Recursively call `addDigits(2)`.
3. `addDigits(2)`:
   - Since `2 < 10`, base case is reached. Return `2`.
4. The recursion stack unwinds and returns `2` as the final result.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int addDigits(int n) {
        if (n < 10)
            return n;

        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }

        return addDigits(sum);
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $O(\log n)$ - In each recursive step, we process the digits of the number. The number of digits of $n$ is proportional to $\log_{10}(n)$. The sum of the digits decreases extremely rapidly, resulting in very few recursive steps (practically $O(1)$ for standard 32-bit integers).
- **Space Complexity**: $O(\log n)$ - The recursion stack depth is proportional to the number of times we reduce the number, which is very small.
