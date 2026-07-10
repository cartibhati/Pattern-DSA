# 🔄 Recursion & Backtracking Pattern

Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem. Backtracking is an algorithmic-technique for solving problems recursively by trying to build a solution incrementally, one piece at a time, removing those solutions that fail to satisfy the constraints of the problem at any point of time.

---

## 📝 Concept Cheatsheet

### Recursion Template
```cpp
ReturnType recursion(arguments) {
    // 1. Base Case(s)
    if (base_case_condition) {
        return base_case_value;
    }
    
    // 2. Recursive Call & Relation
    return recursion(modified_arguments) + relation_logic;
}
```

### Backtracking Template
```cpp
void backtrack(State& state, Result& result, Options& options) {
    // 1. Goal / Base Case
    if (is_goal(state)) {
        result.add(state);
        return;
    }
    
    // 2. Iterate through choices
    for (auto choice : options) {
        if (is_valid(choice, state)) {
            // Make choice
            state.apply(choice);
            
            // Explore
            backtrack(state, result, options);
            
            // Undo choice (Backtrack)
            state.undo(choice);
        }
    }
}
```

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Fibonacci Number** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/fibonacci-number/) | [`1_fibonacci.cpp`](./1_fibonacci.cpp) | [Explanation & Dry Run](1_fibonacci.md) |
| 2 | **Palindrome String** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://www.geeksforgeeks.org/problems/palindrome-string0817/1) | [`2_isPalindrome.cpp`](./2_isPalindrome.cpp) | [Explanation & Dry Run](2_isPalindrome.md) |

---


*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*
