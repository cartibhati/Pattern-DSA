# Smallest Sum Subarray

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://www.geeksforgeeks.org/problems/minimum-sum-subarray/1)**

---

## 📝 Problem Description

Find the contiguous subarray which has the smallest sum.

---

## 💡 Intuition & Core Logic

Mirror of standard Kadane. Track `bestend` using `min(val, bestend + val)` and `ans` using `min(ans, bestend)`.

---

## 🔄 Step-by-Step Dry Run

For `nums = [3, -4, 2]`.
- i=0: bestend = 3, ans = 3.
- i=1 (-4): bestend = min(-4, 3-4) = -4. ans = -4.
- i=2 (2): bestend = min(2, -4+2) = -2. ans = -4.
- Return **-4**.

---

## 💻 C++ Working Code

```cpp
// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int i=0;
        int bestend=a[0];
        int ans=a[0];
        for(int i=1;i<a.size();i++){
            int v1=bestend+a[i];
            int v2=a[i];
            bestend=min(v1,v2);
            ans=min(ans,bestend);
        }
        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
