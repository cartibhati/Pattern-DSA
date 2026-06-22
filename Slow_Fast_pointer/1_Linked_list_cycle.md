# Linked List Cycle (LeetCode 141)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/linked-list-cycle/)**

---

## 📝 Problem Description

Determine if a linked list has a cycle.

---

## 💡 Intuition & Core Logic

Move `slow` by 1 step, `fast` by 2 steps. If they meet, a cycle exists. If `fast` or `fast->next` becomes NULL, there is no cycle.

---

## 🔄 Step-by-Step Dry Run

List with cycle: `3 -> 2 -> 0 -> -4` (pointing back to 2).
- Start: slow=3, fast=3.
- Step 1: slow=2, fast=0.
- Step 2: slow=0, fast=2.
- Step 3: slow=-4, fast=-4. Pointers meet. Return **true**.

---

## 💻 C++ Working Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
            return true;
        }
        return false;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
