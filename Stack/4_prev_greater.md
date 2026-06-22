# Previous Greater Element

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://www.geeksforgeeks.org/previous-greater-element/)**

---

## 📝 Problem Description

For each element, find the closest previous element that is strictly greater. Return -1 if none.

---

## 💡 Intuition & Core Logic

Monotonic decreasing stack. Traverse left-to-right. Pop elements <= `arr[i]`. If stack is empty, res[i] = -1. Else, res[i] = stack top. Push `arr[i]`.

---

## 🔄 Step-by-Step Dry Run

For `arr = [10, 4, 8, 5, 20]`.
- i=0 (10): Stack empty -> res[0]=-1. Push 10. Stack=`[10]`.
- i=1 (4): top (10) > 4 -> res[1]=10. Push 4. Stack=`[10, 4]`.
- i=2 (8): pop 4. top (10) > 8 -> res[2]=10. Push 8. Stack=`[10, 8]`.
- i=3 (5): top (8) > 5 -> res[3]=8. Push 5. Stack=`[10, 8, 5]`.
- i=4 (20): pop 5, 8, 10. Stack empty -> res[4]=-1. Push 20.
- Return `[-1, 10, 10, 8, -1]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    vector<int> preGreaterEle(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
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
