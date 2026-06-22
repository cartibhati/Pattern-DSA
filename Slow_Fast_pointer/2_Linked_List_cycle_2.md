# Linked List Cycle II (LeetCode 142)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/linked-list-cycle-ii/)**

---

## 📝 Problem Description

Find the node where the cycle begins. If there is no cycle, return NULL.

---

## 💡 Intuition & Core Logic

First detect the cycle. If one exists, reset `slow` to head. Move both `slow` and `fast` 1 step at a time. The node where they meet is the start of the cycle.

---

## 🔄 Step-by-Step Dry Run

Same list, cycle starts at node 2.
- Meeting point: node -4.
- Reset slow to head (3), keep fast at meeting node (-4).
- Step 1: Move slow to 2, fast to 2. They meet at node 2. Return node **2**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Find meeting point
        while (fast!=NULL && fast->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow; // start of cycle
            }
        }

        return NULL; // no cycle
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
