# Merge Intervals (LeetCode 56)

![Medium](https://img.shields.io/badge/Difficulty-Medium-yellow)
🔗 **[Problem Link](https://leetcode.com/problems/merge-intervals/)**

---

## 📝 Problem Description

Merge all overlapping intervals and return an array of non-overlapping intervals.

---

## 💡 Intuition & Core Logic

Sort intervals by start time. Insert first interval into results. For subsequent intervals: if it starts after the last merged interval's end, push it directly. Else, merge them by updating the last merged interval's end.

---

## 🔄 Step-by-Step Dry Run

For `intervals = [[1,3],[2,6],[8,10],[15,18]]`.
- Push `[1, 3]`.
- i=1 `[2, 6]`: `2 <= 3`. Merge: end = max(3, 6) = 6. Result: `[[1, 6]]`.
- i=2 `[8, 10]`: `8 > 6`. Push. Result: `[[1, 6], [8, 10]]`.
- i=3 `[15, 18]`: `15 > 10`. Push. Result: `[[1, 6], [8, 10], [15, 18]]`.

---

## 💻 C++ Working Code

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        if (a.empty()) return {};

        sort(a.begin(), a.end());

        vector<vector<int>> res;

        int st1 = a[0][0];
        int end1 = a[0][1];

        for (int i = 1; i < a.size(); i++) {
            int st2 = a[i][0];
            int end2 = a[i][1];

            if (end1 >= st2) {
                end1 = max(end1, end2);
            } else {
                res.push_back({st1, end1});
                st1 = st2;
                end1 = end2;
            }
        }

        res.push_back({st1, end1});

        return res;
    }
};
```

---

## 📊 Complexity Analysis

- **Time Complexity**: `O(N log N)` - We iterate through the elements, performing constant-time work per element.
- **Space Complexity**: `O(N) for output` - Auxiliary space usage details.
