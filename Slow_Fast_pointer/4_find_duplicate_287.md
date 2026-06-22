# Find the Duplicate Number (LeetCode 287)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/find-the-duplicate-number/)**

---

## 📝 Problem Description

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive, find the duplicate number without modifying the array or using extra space.

---

## 💡 Intuition & Core Logic

Treat array as a linked list where index `i` points to `nums[i]`. Find the cycle using slow/fast pointers. Then reset `slow` to 0 and move both pointers 1 step at a time. Their meeting node is the duplicate.

---

## 🔄 Step-by-Step Dry Run

For `nums = [1, 3, 4, 2, 2]`.
- slow=0, fast=0.
- step 1: slow=nums[0]=1, fast=nums[nums[0]]=3.
- step 2: slow=nums[1]=3, fast=nums[nums[3]]=4.
- step 3: slow=nums[3]=2, fast=nums[nums[4]]=4.
- step 4: slow=nums[2]=4, fast=nums[nums[4]]=4. Meet at 4.
- Reset slow=0.
- step 5: slow=nums[0]=1, fast=nums[4]=2.
- step 6: slow=nums[1]=3, fast=nums[2]=4.
- step 7: slow=nums[3]=2, fast=nums[4]=2. Meet at 2.
- Return **2**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=0;
        int fast=0;
        while(true){
            slow=nums[slow];
            fast=nums[fast];
            fast=nums[fast];

            if(slow==fast){
                slow=0;
                while(slow!=fast){
                    slow=nums[slow];
                    fast=nums[fast];
                }
                return slow;
            }
        }
        return -1;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
