# Remove Duplicates from Sorted Array (LeetCode 26)

![Easy](https://img.shields.io/badge/Difficulty-Easy-green)
🔗 **[Problem Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)**

---

## 📝 Problem Description

Remove duplicates from a sorted array in-place such that each unique element appears only once. Return the number of unique elements `k`.

---

## 💡 Intuition & Core Logic

Maintain a write pointer `k` starting at 1. Traverse array with read pointer `i` from 1. If `nums[i] != nums[k-1]`, write it to `nums[k]` and increment `k`.

---

## 🔄 Step-by-Step Dry Run

For `nums = [1, 1, 2]`.
- Start: `k = 1`.
- i=1: `nums[1] (1) == nums[0] (1)`. Duplicate. Skip.
- i=2: `nums[2] (2) != nums[0] (1)`. Write `nums[k] = nums[2] -> nums[1] = 2`. `k` becomes 2.
- Return `k = 2`. Array becomes `[1, 2, 2]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=1;
        int j=1;
        while(j<nums.size()){
            if(nums[j]!=nums[i-1]){
                nums[i]=nums[j];
                i++; 
            }
            j++;
        }
        return i;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
