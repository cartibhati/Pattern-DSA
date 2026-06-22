# Happy Number (LeetCode 202)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/happy-number/)**

---

## 📝 Problem Description

Determine if a number `n` is happy. A happy number is one that eventually reaches 1 when replaced by the sum of the squares of its digits.

---

## 💡 Intuition & Core Logic

Use Floyd's cycle detection. Define a helper to compute the sum of squares of digits. Let `slow` move 1 step and `fast` move 2 steps. If they meet at 1, it's happy; if they meet at any other number, it's in a cycle and is not happy.

---

## 🔄 Step-by-Step Dry Run

For `n = 19`.
- Step 1: slow = 1^2 + 9^2 = 82. fast = get_next(82) = 68.
- Step 2: slow = 68. fast = get_next(68) -> 100 -> 1.
- Step 3: slow = 100. fast = 1.
- Step 4: slow = 1. fast = 1. Both meet at 1. Return **true**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int sumOfSq(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            n=n/10;
            sum+=d*d;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=n;
        while(fast!=1){
            slow = sumOfSq(slow);
            fast = sumOfSq(sumOfSq(fast));

            if(slow==fast && slow!=1){
                return false;
            }
        }
        return true;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(log N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
