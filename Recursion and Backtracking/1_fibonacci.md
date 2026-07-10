# Fibonacci Number (LeetCode 509)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/fibonacci-number/)**

---

## 📝 Problem Description

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is:

- `F(0) = 0, F(1) = 1`
- `F(n) = F(n - 1) + F(n - 2)`, for `n > 1`.

Given `n`, calculate `F(n)`.

---

## 💡 Intuition & Core Logic

This problem can be solved using simple **Recursion**. 
1. **Base Cases**: 
   - If `n == 0`, the Fibonacci number is `0`.
   - If `n == 1`, the Fibonacci number is `1`.
2. **Recursive Case**:
   - For any `n > 1`, the Fibonacci number is the sum of the previous two Fibonacci numbers: `fib(n - 1) + fib(n - 2)`.

---

## 🔄 Step-by-Step Dry Run

For `n = 4`:
1. `fib(4)` calls `fib(3)` and `fib(2)`:
   - `fib(3)` calls `fib(2)` and `fib(1)`:
     - `fib(2)` calls `fib(1)` and `fib(0)`:
       - `fib(1)` returns `1`.
       - `fib(0)` returns `0`.
       - `fib(2)` returns `1 + 0 = 1`.
     - `fib(1)` returns `1`.
     - `fib(3)` returns `1 + 1 = 2`.
   - `fib(2)` calls `fib(1)` and `fib(0)`:
     - `fib(1)` returns `1`.
     - `fib(0)` returns `0`.
     - `fib(2)` returns `1 + 0 = 1`.
2. `fib(4)` returns `fib(3) + fib(2) = 2 + 1 = 3`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int fib(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        return fib(n-1)+fib(n-2);
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: $O(2^n)$ - The recursion tree grows exponentially because we make two recursive calls for each step.
- **Space Complexity**: $O(n)$ - The recursion stack space is proportional to the maximum depth of the recursion tree, which is $n$.
