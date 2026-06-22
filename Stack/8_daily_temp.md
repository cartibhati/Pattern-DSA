# Daily Temperatures (LeetCode 739)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/daily-temperatures/)**

---

## 📝 Problem Description

Given daily temperatures, return an array representing how many days to wait for a warmer temperature.

---

## 💡 Intuition & Core Logic

Monotonic decreasing stack storing indices. Traverse right-to-left. Pop indices whose temp <= current temp. If stack empty, res[i] = 0. Else, res[i] = top_index - i. Push index `i`.

---

## 🔄 Step-by-Step Dry Run

For `temperatures = [73, 74, 75, 71, 69, 72, 76, 73]`.
- i=7 (73): Stack empty -> res[7]=0. Push 7.
- i=6 (76): pop 7. Stack empty -> res[6]=0. Push 6.
- i=5 (72): top (6, temp 76) > 72 -> res[5] = 6-5 = 1. Push 5.
- i=4 (69): top (5, temp 72) > 69 -> res[4] = 5-4 = 1. Push 4.
- i=3 (71): pop 4. top (5, temp 72) > 71 -> res[3] = 5-3 = 2. Push 3.
- Return `[1, 1, 4, 2, 1, 1, 0, 0]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> res(n, 0);
        stack<int> st; 

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() &&
                  temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            if(!st.empty()) {
                res[i] = st.top() - i;
            }

            st.push(i);
        }

        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N)` - Auxiliary space usage details.
