# Next Smaller Element

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://www.geeksforgeeks.org/next-smaller-element/)**

---

## 📝 Problem Description

For each element, find the closest next element that is strictly smaller. Return -1 if none.

---

## 💡 Intuition & Core Logic

Monotonic increasing stack. Traverse right-to-left. Pop elements >= `arr[i]`. If stack is empty, res[i] = -1. Else, res[i] = stack top. Push `arr[i]`.

---

## 🔄 Step-by-Step Dry Run

For `arr = [4, 8, 5, 2, 25]`.
- i=4 (25): Stack empty -> res[4]=-1. Push 25.
- i=3 (2): pop 25. Stack empty -> res[3]=-1. Push 2.
- i=2 (5): top (2) < 5 -> res[2]=2. Push 5.
- i=1 (8): top (5) < 8 -> res[1]=5. Push 8.
- i=0 (4): pop 8, 5. top (2) < 4 -> res[0]=2. Push 4.
- Return `[2, 5, 2, -1, -1]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;

        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && st.top() >= arr[i]) {
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
