# Next Greater Element

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://www.geeksforgeeks.org/next-greater-element/)**

---

## 📝 Problem Description

For each element, find the closest next element that is strictly greater. Return -1 if none.

---

## 💡 Intuition & Core Logic

Monotonic decreasing stack. Traverse right-to-left. Pop elements <= `arr[i]`. If stack is empty, res[i] = -1. Else, res[i] = stack top. Push `arr[i]`.

---

## 🔄 Step-by-Step Dry Run

For `arr = [4, 5, 2, 25]`.
- i=3 (25): Stack empty -> res[3]=-1. Push 25.
- i=2 (2): top (25) > 2 -> res[2]=25. Push 2.
- i=1 (5): pop 2. top (25) > 5 -> res[1]=25. Push 5.
- i=0 (4): top (5) > 4 -> res[0]=5. Push 4.
- Return `[5, 25, 25, -1]`.

---

## 💻 C++ Working Code

```cpp
int n = arr.size();
        vector<int> res(n);
        stack<int> st;

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
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N)` - Auxiliary space usage details.
