# Previous Smaller Element

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://www.geeksforgeeks.org/find-immediate-smaller-element-every-element-array/)**

---

## 📝 Problem Description

For each element, find the closest previous element that is strictly smaller. Return -1 if none.

---

## 💡 Intuition & Core Logic

Monotonic increasing stack. Traverse left-to-right. Pop elements >= `arr[i]`. If stack is empty, res[i] = -1. Else, res[i] = stack top. Push `arr[i]`.

---

## 🔄 Step-by-Step Dry Run

For `arr = [4, 5, 2, 10, 8]`.
- i=0 (4): Stack empty -> res[0]=-1. Push 4. Stack=`[4]`.
- i=1 (5): top (4) < 5 -> res[1]=4. Push 5. Stack=`[4, 5]`.
- i=2 (2): pop 5, 4. Stack empty -> res[2]=-1. Push 2. Stack=`[2]`.
- i=3 (10): top (2) < 10 -> res[3]=2. Push 10. Stack=`[2, 10]`.
- i=4 (8): pop 10. top (2) < 8 -> res[4]=2. Push 8.
- Return `[-1, 4, -1, 2, 2]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
  public:
    vector<int> prevSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
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
