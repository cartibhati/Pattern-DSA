# 🐢🐇 Slow & Fast Pointer Pattern

Slow & Fast Pointer (also known as Hare & Tortoise algorithm) uses two pointers moving at different speeds to detect cycles, find the middle element, or solve list-based problems in a single pass.

---

## 📝 Concept Cheatsheet

### Cycle Detection Template
```cpp
ListNode *slow = head, *fast = head;
while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) return true; // Cycle detected
}
return false;
```

---

## 📈 Problem Progression (Easy to Hard)

| # | Problem Title | Difficulty | Source & Link | C++ Solution | Detailed Explanation |
|---|---|---|---|---|---|
| 1 | **Linked List Cycle** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/linked-list-cycle/) | [`1_Linked_list_cycle.cpp`](./1_Linked_list_cycle.cpp) | [Explanation & Dry Run](1_Linked_list_cycle.md) |
| 2 | **Middle of the Linked List** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/middle-of-the-linked-list/) | [`3_Middle_of_LL.cpp`](./3_Middle_of_LL.cpp) | [Explanation & Dry Run](3_Middle_of_LL.md) |
| 3 | **Happy Number** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/happy-number/) | [`5_happy_number.cpp`](./5_happy_number.cpp) | [Explanation & Dry Run](5_happy_number.md) |
| 4 | **Palindrome Linked List** | ![Easy](https://img.shields.io/badge/Difficulty-Easy-green) | [Problem Link](https://leetcode.com/problems/palindrome-linked-list/) | [`6_Palindorme_linded_list.cpp`](./6_Palindorme_linded_list.cpp) | [Explanation & Dry Run](6_Palindorme_linded_list.md) |
| 5 | **Linked List Cycle II** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/linked-list-cycle-ii/) | [`2_Linked_List_cycle_2.cpp`](./2_Linked_List_cycle_2.cpp) | [Explanation & Dry Run](2_Linked_List_cycle_2.md) |
| 6 | **Find the Duplicate Number** | ![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow) | [Problem Link](https://leetcode.com/problems/find-the-duplicate-number/) | [`4_find_duplicate_287.cpp`](./4_find_duplicate_287.cpp) | [Explanation & Dry Run](4_find_duplicate_287.md) |

---

*Click on any problem's explanation link to read the step-by-step dry run, logic, and complexity analysis!*