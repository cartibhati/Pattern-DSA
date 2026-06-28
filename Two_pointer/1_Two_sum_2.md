# Two Sum II - Input Array Is Sorted (LeetCode 167)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)**

---

## 📝 Problem Description

Given a 1-indexed sorted array of integers `numbers`, find two numbers such that they add up to a specific `target` number. Return their 1-based indices.

---

## 💡 Intuition & Core Logic

Initialize two pointers: `left = 0` and `right = n - 1`. If `numbers[left] + numbers[right] == target`, return indices + 1. If sum is less than target, increment `left` to increase the sum. If greater, decrement `right` to decrease the sum.

---

## 🔄 Step-by-Step Dry Run

For `numbers = [2, 7, 11, 15]`, `target = 9`.
- left=0 (2), right=3 (15). Sum = 17 > 9 -> right--.
- left=0 (2), right=2 (11). Sum = 13 > 9 -> right--.
- left=0 (2), right=1 (7). Sum = 9 == 9 -> Match! Return `{1, 2}`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(numbers[i]+numbers[j]==target){
                return vector<int>{i + 1, j + 1};
                i++;
                j--;
            }
            else if(numbers[i]+numbers[j]<target)
            i++;
            else
            j--;
        }
        return vector<int>{i + 1, j + 1};
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
