# Palindrome Linked List (LeetCode 234)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/palindrome-linked-list/)**

---

## 📝 Problem Description

Given the `head` of a singly linked list, return `true` if it is a palindrome or `false` otherwise.

---

## 💡 Intuition & Core Logic

1. **Find the Middle**: Use slow and fast pointers to find the middle of the linked list. For odd-length lists, skip the exact middle node.
2. **Reverse the Second Half**: Reverse the linked list starting from the middle node (`slow`).
3. **Compare Halves**: Compare nodes from the first half (`head`) and reversed second half (`prev`). If all values match, return `true`, else `false`.

---

## 🔄 Step-by-Step Dry Run

List = `1 -> 2 -> 2 -> 1`

- **Find Middle**:
  - `slow = 1`, `fast = 1`
  - Step 1: `slow = 2`, `fast = 2 (node index 2)`
  - Step 2: `slow = 2 (node index 2)`, `fast = NULL`
- **Reverse Second Half**:
  - Second half starting from `slow`: `2 -> 1`
  - Reversed second half: `1 -> 2`
- **Compare Halves**:
  - First half pointer `first`: `1 -> 2`
  - Second half pointer `second`: `1 -> 2`
  - `1 == 1` -> match, `2 == 2` -> match
  - Return `true`.

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
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return true;

        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // For odd-length lists, skip the middle node
        if (fast != NULL) {
            slow = slow->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = NULL;
        ListNode* curr = slow;

        while (curr != NULL) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        // Step 3: Compare both halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second != NULL) {
            if (first->val != second->val)
                return false;

            first = first->next;
            second = second->next;
        }

        return true;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We traverse the list to find the middle, reverse the second half, and compare both halves in `O(N)` time.
- **Space Complexity**: `O(1)` - In-place linked list reversal requires `O(1)` auxiliary space.
