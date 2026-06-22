# Next Greater Element II (LeetCode 503)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/next-greater-element-ii/)**

---

## 📝 Problem Description

Find the next greater number for each element in a circular array.

---

## 💡 Intuition & Core Logic

Pre-populate monotonic stack with elements from index `n-2` down to 0 to simulate circularity. Then perform standard Next Greater Element from right to left (index `n-1` down to 0).

---

## 🔄 Step-by-Step Dry Run

For `arr = [1, 2, 1]`.
- Pre-populate: Stack=`[2, 1]`.
- i=2 (1): pop 1 (<=1). top=2 > 1 -> res[2]=2. Push 1. Stack=`[2, 1]`.
- i=1 (2): pop 1, 2. Stack empty -> res[1]=-1. Push 2. Stack=`[2]`.
- i=0 (1): top=2 > 1 -> res[0]=2. Push 1.
- Return `[2, -1, 2]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;
        for(int i=n-2;i>=0;i--){
            st.push(arr[i]);
        }

        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if (st.empty())
                res[i] = -1;
            else
                res[i] = st.top();

            st.push(arr[i]);
        }

        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N)` - Auxiliary space usage details.
