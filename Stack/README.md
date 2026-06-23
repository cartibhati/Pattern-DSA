# 🥞 Stack Pattern

Stack is a LIFO (Last In First Out) data structure. A key pattern is the Monotonic Stack, which maintains elements in sorted order to find the next/previous greater/smaller element in O(N) time.

---

## 📝 Concept Cheatsheet

### Monotonic Stack (Next Greater Element) Template
```cpp
stack<int> st;
vector<int> nge(n, -1);
for (int i = n - 1; i >= 0; i--) {
    while (!st.empty() && st.top() <= arr[i]) st.pop();
    if (!st.empty()) nge[i] = st.top();
    st.push(arr[i]);
}
```

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Reverse String** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/reverse-string/) | [`1_reverse_string.cpp`](./1_reverse_string.cpp) | [Explanation & Dry Run](1_reverse_string.md) |
| 2 | **Valid Parentheses** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/valid-parentheses/) | [`2_valid_parentheses_20.cpp`](./2_valid_parentheses_20.cpp) | [Explanation & Dry Run](2_valid_parentheses_20.md) |
| 3 | **Remove All Adjacent Duplicates In String** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/) | [`3_remove_adjacent_dup_1047.cpp`](./3_remove_adjacent_dup_1047.cpp) | [Explanation & Dry Run](3_remove_adjacent_dup_1047.md) |
| 4 | **Previous Greater Element** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://www.geeksforgeeks.org/previous-greater-element/) | [`4_prev_greater.cpp`](./4_prev_greater.cpp) | [Explanation & Dry Run](4_prev_greater.md) |
| 5 | **Previous Smaller Element** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://www.geeksforgeeks.org/find-immediate-smaller-element-every-element-array/) | [`5_prev_smaller.cpp`](./5_prev_smaller.cpp) | [Explanation & Dry Run](5_prev_smaller.md) |
| 6 | **Next Smaller Element** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://www.geeksforgeeks.org/next-smaller-element/) | [`6_next_smaller.cpp`](./6_next_smaller.cpp) | [Explanation & Dry Run](6_next_smaller.md) |
| 7 | **Next Greater Element** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://www.geeksforgeeks.org/next-greater-element/) | [`7_next_greater_gfg.cpp`](./7_next_greater_gfg.cpp) | [Explanation & Dry Run](7_next_greater_gfg.md) |
| 8 | **Daily Temperatures** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/daily-temperatures/) | [`8_daily_temp.cpp`](./8_daily_temp.cpp) | [Explanation & Dry Run](8_daily_temp.md) |
| 9 | **Next Greater Element II** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/next-greater-element-ii/) | [`9_next_greater_2.cpp`](./9_next_greater_2.cpp) | [Explanation & Dry Run](9_next_greater_2.md) |
| 10 | **Remove All Adjacent Duplicates in String II** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/) | [`10_remove_adjacent_dup_1209.cpp`](./10_remove_adjacent_dup_1209.cpp) | [Explanation & Dry Run](10_remove_adjacent_dup_1209.md) |

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*