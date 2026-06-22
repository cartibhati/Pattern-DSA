# Maximum Product Subarray (LeetCode 152)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/maximum-product-subarray/)**

---

## 📝 Problem Description

Find the contiguous subarray that has the largest product.

---

## 💡 Intuition & Core Logic

Maintain running `maxend` and `minend` (since a product of two negatives can be positive). Update them with the current element, its product with `maxend`, and its product with `minend`.

---

## 🔄 Step-by-Step Dry Run

For `nums = [2, 3, -2, 4]`.
- i=0: maxend=2, minend=2, ans=2.
- i=1 (3): maxend=6, minend=3, ans=6.
- i=2 (-2): maxend=max(-2, -12, -6)=-2, minend=min(-2, -12, -6)=-12, ans=6.
- i=3 (4): maxend=max(4, -8, -48)=4, minend=min(4, -8, -48)=-48, ans=6.
- Return **6**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxend = nums[0];
        int minend = nums[0];
        int ans = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            int v1 = nums[i];
            int v2 = nums[i] * maxend;
            int v3 = nums[i] * minend;

            int newMax = max(v1, max(v2, v3));
            int newMin = min(v1, min(v2, v3));

            maxend = newMax;
            minend = newMin;

            ans = max(ans, max(maxend,minend));
        }

        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
