# 🧮 Math Pattern

Mathematical patterns leverage arithmetic properties, formulas, number theory, and bitwise operations to solve algorithmic problems efficiently without brute-force enumeration.

---

## 📝 Concept Cheatsheet

### 1. Sum of First $N$ Natural Numbers (Gauss' Formula)
The sum of integers from $0$ to $n$ is:
$$S = \frac{n \times (n + 1)}{2}$$

```cpp
int expectedSum = n * (n + 1) / 2;
```

### 2. Bit Manipulation / XOR Properties (Alternative for Missing Number)
- $x \oplus x = 0$
- $x \oplus 0 = x$
XORing all numbers from $0$ to $n$ and all elements in `nums` leaves only the missing number!

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Missing Number** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/missing-number/) | [`1_missing_number.cpp`](./1_missing_number.cpp) | [Explanation & Dry Run](1_missing_number.md) |

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*
