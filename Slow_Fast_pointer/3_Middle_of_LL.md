# Middle of the Linked List (LeetCode 876)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/middle-of-the-linked-list/)**

---

## 📝 Problem Description

Return the middle node of a linked list. If there are two middle nodes, return the second middle node.

---

## 💡 Intuition & Core Logic

Move `slow` by 1 step, `fast` by 2 steps. When `fast` reaches the end, `slow` will be at the middle node.

---

## 🔄 Step-by-Step Dry Run

List = `1 -> 2 -> 3 -> 4 -> 5`.
- Start: slow=1, fast=1.
- Step 1: slow=2, fast=3.
- Step 2: slow=3, fast=5. fast->next is NULL. Stop.
- Return slow (node **3**).

---

## 💻 C++ Working Code

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
