# Maximum Subarray Sum with One Deletion (LeetCode 1186)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/)**

---

## 📝 Problem Description

Return the maximum sum of a non-empty subarray with at most one deletion.

---

## 💡 Intuition & Core Logic

Maintain `nodelete` (max subarray sum ending at current index with 0 deletions) and `onedelete` (max subarray sum ending at current index with exactly 1 deletion: either we delete the current element leaving `prev_nodelete` sum, or we add current element to an already deleted sum `prev_onedelete`).

---

## 🔄 Step-by-Step Dry Run

For `arr = [1, -2, 0, 3]`.
- Start: nodelete = 1, onedelete = INT_MIN, ans = 1.
- i=1 (-2): nodelete = max(-2, -1) = -1. onedelete = max(INT_MIN, 1) = 1. ans = 1.
- i=2 (0): nodelete = max(0, -1) = 0. onedelete = max(1, -1) = 1. ans = 1.
- i=3 (3): nodelete = max(3, 3) = 3. onedelete = max(4, 0) = 4. ans = 4.
- Return **4**.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodelete=arr[0];
        int onedelete= INT_MIN;
        int ans=arr[0];
        for(int i=1;i<arr.size();i++){
            int prevnodelete = nodelete;
            int prevonedelete = onedelete;

            nodelete = max(arr[i],nodelete+arr[i]);
            int v2;
            if(onedelete==INT_MIN){
                v2=arr[i];
            }
            else{
                v2= prevonedelete+arr[i];
            }

            onedelete  = max(v2,prevnodelete);
            ans = max(ans,max(onedelete,nodelete));
        }
        return ans;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(1)` - Auxiliary space usage details.
